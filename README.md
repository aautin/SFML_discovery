# 🎮 Cross-Platform SFML Game

## 🔧 Technical Details

### Build System

- **Linux Build**: Native GCC compilation in Ubuntu 22.04 containerbased game built with a robust cross-platform Docker build system that produces both Linux and Windows executables.

## ✨ Features

- **Cross-platform builds**: Automatic generation of Linux and Windows executables
- **Docker-based build system**: Consistent, reproducible builds
- **SFML from source**: Complete control over the graphics library
- **Simple game demo**: Window with green circle rendering to test SFML functionality

## 🚀 Quick Start

### Building Both Platforms

1. Clone the repository:
```bash
git clone https://github.com/aautin/game_from_scratch.git game_from_scratch
cd game_from_scratch
git submodule update --init --recursive
```

2. Extract the assets:
```bash
tar -x -f assets.tar.gz
```

3. Run the build:
```bash
./build.sh
```

## 📁 Project Structure

```
├── src/                   # Main game source code
├── assets/                # Extracted assets
├── assets.tar.gz          # Archived assets
├── docker/
│   ├── Dockerfile.linux   # Linux build configuration
│   └── Dockerfile.windows # Windows cross-compilation configuration
├── SFML/                  # SFML source code (submodule)
├── out/
│   ├── linux/             # Linux executable output
│   └── windows/           # Windows executable output
├── build.sh               # Main build script
└── CMakeLists.txt         # CMake configuration
```

## � Technical Details

### Build System
- **Linux Build**: Native GCC compilation in Ubuntu 22.04 container
- **Windows Build**: MinGW-w64 cross-compilation with posix threading model
- **SFML**: Built from source with all dependencies included
- **Dependencies**: Automatically fetched and built (FreeType, OGG, Vorbis, FLAC)

## 📊 Build Outputs

After a successful build:
- **Linux**: `./out/linux/my_game`
- **Windows**: `./out/windows/my_game.exe`

Both executables are self-contained and include all necessary SFML dependencies.

## 🎯 Game Features

- Opens an SFML window
- 2 players to play with (AWSD and Directional-Keys)
- Grid-based movements
- Simple grid-map based on a single tile
- Absolutely no goal and no collision

## 🛠️ Development prerequisites

- Docker
- Git
- Tar 

## 🎮 Play the game

Latest versions are available here:
👉 [Releases](https://github.com/aautin/game_from_scratch/releases)

No dependencies required. Download, extract, and run.
