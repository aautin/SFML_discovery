cmake_minimum_required(VERSION 3.15)
project(MyGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Static linking
set(BUILD_SHARED_LIBS OFF)
add_definitions(-DSFML_STATIC)

# Submodule
add_subdirectory(SFML)

# Source files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)
add_executable(my_game ${SOURCES})

# Include + link SFML
target_include_directories(my_game PRIVATE include)
target_link_libraries(my_game
    sfml-graphics
    sfml-window
    sfml-system
)

# Output directory
set_target_properties(my_game PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
