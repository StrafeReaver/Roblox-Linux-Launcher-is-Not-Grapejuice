#include <iostream>
#include <filesystem>
#include <string>

class RobloxLauncher
{
    public:
        RobloxLauncher(const std::string& wpfx, const std::string& cmdarg);
        ~RobloxLauncher();
        void Launch();
    private:
        const std::string GetLauncherPath();
        std::string WinePrefix;
        std::string CmdArgument;
        
};