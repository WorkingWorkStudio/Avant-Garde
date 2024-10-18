source setup_env.sh
mkdir -p ../build
cmake -S . -B ../build
cd ../build
make
make Shaders
cd ..
./build/Avant-Garde