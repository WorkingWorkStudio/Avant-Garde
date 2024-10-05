cmake_minimum_required(VERSION 3.6)
project( Avant-garde )
set(CMAKE_CXX_STANDARD 17)                                                          # set C++ version 17

EXECUTE_PROCESS( COMMAND uname -m COMMAND tr -d '\n' OUTPUT_VARIABLE ARCHITECTURE ) # find computer architecture
message( STATUS "Architecture: ${ARCHITECTURE}" )                                   # print architecture
# if (${ARCHITECTURE} STREQUAL "arm64")
#     set(CMAKE_SYSTEM_PROCESSOR arm)
# else ()
#     message( FATAL_ERROR "incompatible architecture" )
# endif ()

# find_package( glfw REQUIRED )
# find_package( glm REQUIRED )
# find_package( vulkan REQUIRED )

include_directories( /opt/homebrew/Cellar/glfw/3.4/include )
     # GLFW/glfw3.h
     # GLFW/glfw3native.h
include_directories( /opt/homebrew/Cellar/glm/1.0.1/include )
     # glm/*   - a lot of files
include_directories( /opt/homebrew/Cellar/vulkan-headers/1.3.296/include )
     # vk_video/*.h
     # vulkan/*.h *.hpp *.cppm
include_directories( /opt/homebrew/Cellar/molten-vk/1.2.10/include )
     # MoltenVK/*.h
     # MoltenVKShaderConverter/*.h
# include_directories( $ENV{HOME}/VulkanSDK/1.3.290/macOS/include )
# include_directories( ~/VulkanSDK/1.3.290/macOS/include/**/*.hpp )
# include_directories( ~/VulkanSDK/1.3.290/macOS/include/**/*.cppm )

message(STATUS "Included Directories")
get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
     message(STATUS " - dir='${dir}'")
endforeach()

# "/opt/homebrew/Cellar/vulkan-validationlayers/1.3.296/share/vulkan/explicit_layer.d"

# find all cpp files in src
file(GLOB_RECURSE SOURCES "../../src/*.cpp")
add_executable( game.exe ${SOURCES})

file(GLOB_RECURSE SOURCES
     "/opt/homebrew/Cellar/vulkan-headers/1.3.296/include/**/*.h"
     "/opt/homebrew/Cellar/vulkan-headers/1.3.296/include/**/*.hpp"
     "/opt/homebrew/Cellar/vulkan-headers/1.3.296/include/**/*.cppm"
)
file(GLOB libraries
     "/opt/homebrew/Cellar/glfw/3.4/lib/*.dylib"
          # libglfw.3.4.dylib
          # libglfw.3.dylib
          # libglfw.dylib
          # libglfw3.a
     # "/opt/homebrew/Cellar/glm/1.0.1/lib/*.dylib"
     #      # libglm.dylib
     # "/opt/homebrew/Cellar/molten-vk/1.2.10/lib/*.dylib"
     #      # libMoltenVK.dylib
     # "/opt/homebrew/Cellar/vulkan-loader/1.3.296/lib/*.dylib"
     #      # libvulkan.1.3.296.dylib
     #      # libvulkan.1.dylib
     #      # libvulkan.dylib
     # "/opt/homebrew/Cellar/vulkan-validationlayers/1.3.296/*.dylib"
     #      # libVkLayer_khronos_validation.dylib
     
     "~/VulkanSDK/1.3.290/macOS/lib"
)

set(CMAKE_XCODE_SCHEME_ENVIRONMENT "${CMAKE_XCODE_SCHEME_ENVIRONMENT};VK_ADD_LAYER_PATH=$ENV{VK_ADD_LAYER_PATH}")
set(CMAKE_XCODE_SCHEME_ENVIRONMENT "${CMAKE_XCODE_SCHEME_ENVIRONMENT};VK_ICD_FILENAMES=$ENV{VK_ICD_FILENAMES}")
set(CMAKE_XCODE_SCHEME_ENVIRONMENT "${CMAKE_XCODE_SCHEME_ENVIRONMENT};VK_DRIVER_FILES=$ENV{VK_DRIVER_FILES}")

target_link_libraries( game.exe ${libraries} )
