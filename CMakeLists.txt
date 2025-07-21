cmake_minimum_required(VERSION 3.15)
project(MyGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Static linking configuration
set(BUILD_SHARED_LIBS OFF)
set(SFML_STATIC_LIBRARIES TRUE)
add_definitions(-DSFML_STATIC)

# Prefer static libraries but don't force completely static linking
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a" ".so")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++")

# Submodule
add_subdirectory(SFML)

# Source files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)
add_executable(my_game ${SOURCES})

# Configure system libraries based on platform
if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    # Windows specific libraries
    set(SYSTEM_LIBS "")
else()
    # Linux specific libraries
    set(SYSTEM_LIBS GL X11 Xrandr Xcursor Xi udev xcb pthread)
endif()

# Include + link SFML with static libraries
target_include_directories(my_game PRIVATE include)
target_link_libraries(my_game
    sfml-graphics
    sfml-window
    sfml-system
    ${SYSTEM_LIBS}
)

# Output directory
set_target_properties(my_game PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
