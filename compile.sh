rm -rf build
mkdir build
g++ src/main.cpp src/includes/commands/commands.cpp src/includes/app/app.cpp -o ./build/app.out
build/app.out