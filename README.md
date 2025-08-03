# 🎮 SFML game-oriented practice

## ✨ Features

- **Cross-OS builds**: Automatic generation of Linux and Windows executables
- **Docker-based build system**: Consistent, reproducible builds
- **SFML from source**: Complete control over the graphics library

## 🚀 Quick Start

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
├── src/                   # Game header files
├── src/                   # Game source code
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
├── maps/                  # Map files
└── CMakeLists.txt         # CMake configuration
```

## � Technical Details

- **Linux Build**: Native GCC compilation in Ubuntu 22.04 container
- **Windows Build**: MinGW-w64 cross-compilation with posix threading model
- **SFML**: Built from source with all dependencies included
- **Dependencies**: Automatically fetched and built (FreeType, OGG, Vorbis, FLAC)

## 🎯 Pseudo-Game Features

- Opens an SFML window
- 1 character to control :
	- AWSD movement keys
 	- walking and idle animations
 	- some collisions
- map file parsing
- Character movements are grid-based
- Absolutely no goal in this game, just testing the graphic library

## 🗂️ Assets for development

- [free-top-down-roguelike-game-kit-pixel-art](https://craftpix.net/freebies/free-top-down-roguelike-game-kit-pixel-art/)

## 🛠️ Development prerequisites

- Docker
- Git
- Tar 

No other dependencies required. Clone, build and run to play !
