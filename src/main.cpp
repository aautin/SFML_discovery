#include <stdio.h>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Character.hpp"

void handleEvents(sf::RenderWindow &window) {
    std::optional<sf::Event> event;
	while ((event = window.pollEvent()))
	{
		if (event->is<sf::Event::Closed>())
			window.close();
	}
}

void updateGameLogic(Character &player) {
	if (!player.isMoving())
		player.setDirection(STEP_SIZE, STEP_SIZE);
	else {
		player.move();
        player.setSprite();
    }
}

void renderGame(sf::RenderWindow &window, Character& player) {
    window.clear();
    window.draw(player.getSprite());
    window.display();
}

int main() {
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(800, 600)), "SFML Game Loop Example");

    sf::Texture player_texture;
    if (!player_texture.loadFromFile("assets/1 Characters/1/D_Walk.png"))
        return -1;
    Character player(player_texture);

    while (window.isOpen()) {
        handleEvents(window);
        updateGameLogic(player);
        renderGame(window, player);
        sf::sleep(sf::milliseconds(32)); // Environ 30 FPS
    }

    return 0;
}
