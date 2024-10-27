# Avant-garde
This is a [RCOS](https://handbook.rcos.io/) Project.

Feel free to take a look at our [Kanban](https://docs.google.com/drawings/d/1AZ96UuH22W9aF4FDUhVJ3GPxuHaQv0s0LfwgRhOCg70/edit?usp=sharing) board for task management.

### Compatibility
| OS | Versions Supported | Status |
| - | :-: | :-: |
| Windows 11 | 23H2 | 🚫 |
| MacOS | Sonoma 14.6.x | ✔️ |
| Linux | ❓ | 🚫 |

# Installation Instructions

### Windows
TBD

### MacOS
Using any code editor and terminal running shell script (VSCode Compatible):
1. Clone this repository
2. Install Homebrew if you don't already have it:
```
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```
3. Install CMake & GLFW with Brew:
```
brew install cmake glfw
```
4. Install the latest [Vulkan SDK](https://vulkan.lunarg.com/sdk/home#mac) (1.3.296.0), recommend putting the folder in the home folder i.e. `~` or `/Users/[username]` and name the folder VulkanSDK. If you installed else where or named differently, you need the modify the folder location in `/dev/setup_env.sh` within the cloned repository. Select `System Global Installation` and `GLM Header` when prompted.
5. From the repository's root directory, run the following commands:
```
cd dev
./build_unix.sh
```
6. You may need to give `build_unix.sh` some permission:
```
chmod +x build_unix.sh
```
Helpful Tools: [.exe Disassembler](https://dogbolt.org/)

👍 You are ready for development!

### Linux
TBD

# VulkanProject

## Getting Started
Make sure to install all of the libraries listed in the [Vulken Tutorial](https://vulkan-tutorial.com/Development_environment)\
NOTE: Place the glfw3.lib or glfw.lib into the lib folder if you are using windows \
NOTE: To compile, update the path in shaders/compile-shaders.<bat/sh> for the glslc.<exe/sh> file \
- For windows: it lives in `C:/VulkanSDK/x.x.x.x/Bin32/glslc.exe`
- For linux: depends on where you placed it

### Windows
Install visual studio 2022\
Install libraries listed in the tutorial\
Click open existing project\
Click the run button

### Linux
Use any text editor that uses `.clangd` configurations if tou want to have intellisense\
Make sure to install all the libraries listed in the vulken tutorial\
Have `Make` install in your computer\
Run `make` then `make test`

### Mac
TBA

## Monitor System Stats with an overlay
For linux systems:
- `VK_INSTANCE_LAYERS='VK_LAYER_MESA_OVERLAY' /path/to/app` ( Only works with amd gpus? )
- `mangohud /path/to/app`\

For windows systems:
- PresentMon (by Intel)
- Ocat
