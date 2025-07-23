#include <stdio.h>
#include <stdlib.h>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Character.hpp"

void handleEvents(sf::RenderWindow &window, Character &player)
{
    std::optional<sf::Event> event;
    while ((event = window.pollEvent())) {
        if (event->is<sf::Event::Closed>())
            window.close();
        else if (event->is<sf::Event::KeyPressed>()) {
            auto code = event->getIf<sf::Event::KeyPressed>()->code;
            direction dir = static_cast<direction>(code);
            if ((dir == LEFT_MOVE || dir == RIGHT_MOVE || dir == UP_MOVE || dir == DOWN_MOVE) && !player.isMoving())
                player.setMove(dir);
            if ((dir == LEFT_ARROW || dir == RIGHT_ARROW || dir == UP_ARROW || dir == DOWN_ARROW))
                player.setArrow(dir);
        }
    }
}

void updateGameLogic(Character &player)
{
    if (player.isMoving())
        player.move();
    else
        player.idle();
}

void generateMapSprites(std::vector<sf::Sprite>& map_sprites, const sf::Texture& map_texture)
{
    for (int i = 0; i < MAP_WIDTH; ++i) {
        for (int j = 0; j < MAP_HEIGHT; ++j) {
            sf::Sprite sprite(map_texture);
            sprite.setPosition(sf::Vector2f(i * FRAME_SIZE, j * FRAME_SIZE));
            sprite.setScale(sf::Vector2f(2.0f, 2.0f));
            map_sprites.push_back(sprite);
        }
    }
}

void prepareRender(Character &player)
{
    player.setCurrentSprite();
    player.setArrowSprite();
}

void renderGame(sf::RenderWindow& window, const std::vector<sf::Sprite>& map_sprites, Character& player)
{
    window.clear();
    for (const auto& sprite : map_sprites) {
        window.draw(sprite);
    }
    window.draw(player.getCurrentSprite());
    window.draw(player.getArrowSprite());
    window.display();
}

int main()
{
    sf::Vector2u window_size(MAP_WIDTH * FRAME_SIZE, MAP_HEIGHT * FRAME_SIZE);
    std::vector<sf::Sprite> map_sprites;
    
    
    sf::Texture map_texture, walking_texture, idle_texture, arrow_texture;
    if (!walking_texture.loadFromFile("assets/1 Characters/1/D_Walk.png")
        || !idle_texture.loadFromFile("assets/1 Characters/1/D_Idle.png")
        || !map_texture.loadFromFile("assets/2 Dungeon Tileset/1 Tiles/Tile_20.png")
        || !arrow_texture.loadFromFile("assets/2 Dungeon Tileset/2 Objects/arrow.png"))
        return -1;
    generateMapSprites(map_sprites, map_texture);

    Character player(walking_texture, idle_texture, arrow_texture);
    sf::RenderWindow window(sf::VideoMode(window_size), "SFML Game Loop Example");
    while (window.isOpen()) {
        handleEvents(window, player);
        updateGameLogic(player);
        prepareRender(player);
        renderGame(window, map_sprites, player);
    }

    return 0;
}
