#!/bin/bash
set -e

mkdir -p out/linux out/windows

# Build Linux
echo "Building Linux version..."
docker build -f docker/Dockerfile.linux -t mygame-linux .

echo "Checking if Linux executable exists in container..."
docker run --rm mygame-linux ls -la /app/build/bin/

# Copy the Linux executable using volume mount approach
echo "Copying Linux executable using volume mount..."
docker run --rm -v "$(pwd)/out/linux:/output" mygame-linux cp /app/build/bin/my_game /output/

# Check if Linux file was actually copied
echo "Checking if Linux file was copied successfully..."
if [ -f "./out/linux/my_game" ]; then
    echo "✅ Linux build completed successfully!"
    echo "Executable location: ./out/linux/my_game"
    ls -la ./out/linux/my_game
else
    echo "❌ ERROR: Linux file was not copied successfully!"
    echo "Contents of output directory:"
    ls -la ./out/linux/
    exit 1
fi

echo ""
echo "=================================================="
echo ""

# Build Windows
echo "Building Windows version..."
docker build -f docker/Dockerfile.windows -t mygame-windows .

echo "Checking if Windows executable exists in container..."
docker run --rm mygame-windows ls -la /app/build/bin/

# Copy the Windows executable using volume mount approach
echo "Copying Windows executable using volume mount..."
docker run --rm -v "$(pwd)/out/windows:/output" mygame-windows cp /app/build/bin/my_game.exe /output/

# Check if Windows file was actually copied
echo "Checking if Windows file was copied successfully..."
if [ -f "./out/windows/my_game.exe" ]; then
    echo "✅ Windows build completed successfully!"
    echo "Executable location: ./out/windows/my_game.exe"
    ls -la ./out/windows/my_game.exe
else
    echo "❌ ERROR: Windows file was not copied successfully!"
    echo "Contents of output directory:"
    ls -la ./out/windows/
    exit 1
fi

echo ""
echo "=================================================="
echo "🎉 Build completed successfully for both platforms!"
echo "📁 Linux executable:   ./out/linux/my_game"
echo "📁 Windows executable: ./out/windows/my_game.exe"
echo "=================================================="
