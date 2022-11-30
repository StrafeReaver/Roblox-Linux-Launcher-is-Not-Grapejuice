#include "RLLNG.hpp"

RobloxLauncher::RobloxLauncher(const std::string& wpfx, const std::string& cmdarg)
{
    CmdArgument = cmdarg;
    WinePrefix = wpfx;
}

RobloxLauncher::~RobloxLauncher()
{
    std::cout << "done\n";
}

void RobloxLauncher::Launch()
{
    const std::string launcherpath = GetLauncherPath();
    const std::string cmd = "wine " + launcherpath + " " + CmdArgument;

    setenv("WINEPREFIX", WinePrefix.c_str(), true);
    std::system(cmd.c_str());
}

const std::string RobloxLauncher::GetLauncherPath()
{
    for (const auto& launcherdir : std::filesystem::recursive_directory_iterator(WinePrefix + "/drive_c/users/" + std::string(getenv("USER")) + "/AppData/Local/Roblox/Versions")) // gotta us3 a little recurs10n
        if (launcherdir.is_regular_file() ? launcherdir.path().extension() == ".exe" : std::filesystem::exists("RobloxPlayerLauncher.exe")) // lol werks on my machine tm
            return launcherdir.path().string();
    return {};
}

int main(int argc, char* args[])
{
    const std::string homedir = std::string(getenv("HOME"));

    std::cout.sync_with_stdio(false);

    auto Launcher = std::make_unique<RobloxLauncher>(homedir + "/.local/share/games/roblox", args[1]);

    Launcher->Launch();
    
    return 0;
}
