## "RLLNG"

# What is it?
RLLNG is just a simple wrapper for the Roblox launcher, nothing quite that special, however it's more minimal then Grapejuice!

# Features

- Makes it possible to launch the Roblox game client from a browser without asking you to install a bunch of bloat
- Can be used within a **Firejail sandbox** with the given custom firejail profile
- Written and tested on Gentoo GNU/Linux


# Requirements
- Firejail (**Multiplayer games should always be sandboxed so you're less likely to be pwned by a future client RCE vulnerability**)
- The only requirements are app-emulation/wine-staging (with ABI 32), and of course https://www.roblox.com/download/client
- DXVK installed in your wineprefix
- Make sure you keep wine-staging, and DXVK updated for performance improvements

# Setting up WINE
**NVIDIA drivers require abi_x86_32 USE on Gentoo!**

**I use doas and recommend it, however you can replace it with sudo**
  ## Gentoo Portage Configuration & Emerge
  - Create a new package.use file for wine-staging 
    > doas nano /etc/portage/package.use/wine-staging
  - Paste this into the new file you've created 
    > app-emulation/wine-staging abi_x86_32 abi_x86_64 vulkan
  - Unmask wine-staging 
     > doas nano /etc/portage/package.accept_keywords/wine-staging 
  - Paste in 
     > app-emulation/wine-staging ~amd64
  - Now that portage is configured properly to build wine-staging you may now emerge app-emulation/wine-staging to your system

  ## Building WINE staging on other distros
  - https://github.com/wine-staging/wine-staging Follow their documentation
  
  ## Installing Roblox inside of a new WINE prefix
  - Download https://www.roblox.com/download/client
  - Open your terminal and run 
    > WINEPREFIX="~/.local/share/games/roblox" wine ~/Downloads/RobloxPlayerLauncher.exe


  ## Forcing and making sure Roblox uses D3D11 as its rendering engine
   - Go to 
     > ~/.local/share/games/roblox/drive_c/users/$USER/AppData/Local/Roblox/Versions/version-HASHHERE
   - Create a brand new folder named "ClientSettings"
   - Copy/Paste the provided file "ClientAppSettings.json" into that new folder
  
  ## Installing DXVK in your Roblox WINE prefix
  - Follow the instructions here pretty straightforward https://github.com/doitsujin/dxvk (Roblox prefix would be "~/.local/share/games/roblox")


# How to build this into a binary

- Run make


# How to install

  ## Editing mimeinfo.cache and installing the binary
  - Go to ~/.local/share/applications
  - Place the provided "roblox-player.desktop" into that same folder
  - Open your mimeinfo.cache file and copy this into it at the very bottom
     > x-scheme-handler/roblox-player=roblox-player.desktop
  - Place the compiled RLLNG binary into ~/.local/bin (Make it if you don't have it)
  - Create a new fodler in your .config directory named "firejail" ~/.config/firejail, and place RLLNG.local into it


### Play some fucking lego!!!!111
- Run your browser and click play on any game

### Advantages of running in Firejail
- David Ballsucki wont be able to **scan your file system**
- Script kiddies wont be able to **pwn your system** if they ever come across a certain type of **RCE vulnerability**
- You're **saving** the planet and it's **eco-friendly**

### Why I made this
- I got tired of Grapejuice being bloat as hell and giving everyone the idea they need all of these retarded packages and an oudated version of WINE
- Grapejuice & Firejail sandbox = gross
- Other client launcher wrappers are also bloat
- Grapejuice is fucking racist they're still commiting changes to the "master" branch!!1111
- I personally don't need an eye-candy UI with settings to run lego

### TODO
- Have it setup the prefix, DXVK, and install lego by itself
- Create scripts to help setup Portage, and help users build wine-staging on other distros
- Options to change the rendering mode
- Disable FFLags that have anything to do with tracking
- Have it bother users about new wine-staging versions, and DXVK for performance improvements
- Commit future changes to the "slave" branch because Grapejuice isn't helping minorities
