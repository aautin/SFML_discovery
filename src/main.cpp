#include <stdio.h>
#include <stdlib.h>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Game.hpp"
#include "utils.hpp"

int main()
{
    Game game("My Game", sf::Vector2u(10, 10));
    game.run();

    return EXIT_SUCCESS;
}
