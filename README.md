# Avant-garde
This is a [RCOS](https://handbook.rcos.io/) Project.

### Compatibility
| OS | Versions Supported | Status |
| - | :-: | :-: |
| Windows 11 | v. 23H2 | 🚫 |
| MacOS | Sonoma 14.6.x | 🚫 |
| Linux | ❓ | 🚫 |

### Installation Instructions
1. Clone repository
2. Within repository root directory, run the following commands:
```
To be determined.
``` 
👍 You are ready for development!

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
