#include <stdio.h>
#include <stdlib.h>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Game.hpp"
#include "utils.hpp"

int main()
{
    try {
        Game game("My Game", "maps/small", sf::Vector2u(64, 64));

        while (game.isRunning()) {
            game.events();
            game.logic();
            game.render();
        }
        return EXIT_SUCCESS;
        
    } catch (const std::exception& e) {
        fprintf(stderr, "Error: %s\n", e.what());
        return EXIT_FAILURE;
    }
}
