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

```bash
# Build both Linux and Windows executables
./build_all.sh

# Build only Linux
./build_all.sh linux

# Build only Windows
./build_all.sh windows
```

## 📁 Project Structure

```
├── src/                   # Main game source code
├── docker/
│   ├── Dockerfile.linux   # Linux build configuration
│   └── Dockerfile.windows # Windows cross-compilation configuration
├── SFML/                  # SFML source code (submodule)
├── out/
│   ├── linux/             # Linux executable output
│   └── windows/           # Windows executable output
├── build_all.sh           # Main build script
└── CMakeLists.txt         # CMake configuration
```

## � Technical Details

### Build System
- **Linux Build**: Native GCC compilation in Ubuntu 22.04 container
- **Windows Build**: MinGW-w64 cross-compilation with posix threading model
- **SFML**: Built from source with all dependencies included
- **Dependencies**: Automatically fetched and built (FreeType, OGG, Vorbis, FLAC)

### Key Solutions Implemented

1. **Threading Model Fix**: Using MinGW-w64 posix threading model instead of win32 to support C++11 `<mutex>` features
2. **Robust File Copying**: Volume-based copying instead of `docker cp` for reliable file permissions
3. **Complete Dependency Chain**: All SFML dependencies built from source for maximum compatibility

### Windows Cross-Compilation

The Windows build uses MinGW-w64 with the posix threading model:

```dockerfile
# Configure MinGW to use posix threading model for better C++11 support
RUN update-alternatives --set x86_64-w64-mingw32-gcc /usr/bin/x86_64-w64-mingw32-gcc-posix && \
    update-alternatives --set x86_64-w64-mingw32-g++ /usr/bin/x86_64-w64-mingw32-g++-posix
```

This resolves the `__gthread_time_t` and related threading issues that occur with the default win32 threading model.

## 📊 Build Outputs

After a successful build:
- **Linux**: `./out/linux/my_game`
- **Windows**: `./out/windows/my_game.exe`

Both executables are self-contained and include all necessary SFML dependencies.

## 🎯 Game Features

The current demo application:
- Creates an SFML window (800x600)
- Renders a green circle in the center
- Handles window close events
- Demonstrates basic SFML setup and rendering

## 🛠️ Development

### Prerequisites

- Docker
- Git

### Building from Source

1. Clone the repository:
```bash
git clone https://github.com/aautin/game_from_scratch.git game_from_scratch
cd game_from_scratch
git submodule update --init --recursive
```

2. Run the build:
```bash
./build_all.sh
```

## 📝 Download

Latest versions are available here:

👉 [Releases](https://github.com/aautin/game_from_scratch/releases)

No dependencies required. Download, extract, and run.
