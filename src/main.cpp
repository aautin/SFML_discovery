#include <stdio.h>
#include <stdlib.h>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Game.hpp"
#include "utils.hpp"

int main(int argc, char** argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <tile_size>\n", argv[0]);
        return EXIT_FAILURE;
    }
    if (atoi(argv[1]) <= 0) {
        fprintf(stderr, "Tile size must be a positive integer.\n");
        return EXIT_FAILURE;
    }

    Game game("My Game", sf::Vector2f(10, 10), sf::Vector2f(16 * atoi(argv[1]), 16 * atoi(argv[1])));
    game.run();
    return EXIT_SUCCESS;
}
