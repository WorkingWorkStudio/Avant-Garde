echo "~~ CMake ~~~~~~~~~~~~~~~~~~~"
cmake .

echo "~~ make ~~~~~~~~~~~~~~~~~~~~"
make

echo "~~ Remove Build ~~~~~~~~~~~~"
rm -rf ./CMakeFiles
rm -rf ./cmake_install.cmake
rm -rf ./CMakeCache.txt
rm -rf ./Makefile

echo "~~ Exit Code: $? ~~~~~~~~~~~"
