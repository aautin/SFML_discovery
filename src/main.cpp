#include <stdio.h>
#include <stdlib.h>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Game.hpp"
#include "utils.hpp"

int main()
{
    try {
        Game game("My Game", sf::Vector2u(10, 10), sf::Vector2f(32, 32));

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
