cmake_minimum_required(VERSION 3.6)
project( CV-Computer-Controller )
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
include_directories( /opt/homebrew/Cellar/vulkan-headers/1.3.296/include )
include_directories( /opt/homebrew/Cellar/glfw/3.4/include )
include_directories( /opt/homebrew/Cellar/glm/1.0.1/include )

add_executable( game.exe main.cpp )

file(GLOB libraries
     "/opt/homebrew/Cellar/glfw/3.4/lib/*.dylib"
     "/opt/homebrew/Cellar/glm/1.0.1/lib/*.dylib"
     "/opt/homebrew/Cellar/vulkan-loader/1.3.296/lib/*.dylib"
)

target_link_libraries( game.exe ${libraries} )