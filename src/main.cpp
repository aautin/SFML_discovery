#include <stdio.h>
#include <stdlib.h>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Character.hpp"

void    handleEvents(sf::RenderWindow &window, Character &player1, Character &player2)
{
    std::optional<sf::Event> event;
    while ((event = window.pollEvent())) {
        if (event->is<sf::Event::Closed>())
            window.close();
        else if (event->is<sf::Event::KeyPressed>()) {
            auto code = event->getIf<sf::Event::KeyPressed>()->code;
            direction dir = static_cast<direction>(code);
            if ((dir == LEFT1 || dir == RIGHT1 || dir == UP1 || dir == DOWN1) && !player1.isMoving())
                player1.setDirection(dir);
            if ((dir == LEFT2 || dir == RIGHT2 || dir == UP2 || dir == DOWN2) && !player2.isMoving())
                player2.setDirection(dir);
        }
    }
}

void    updateGameLogic(Character &player1, Character &player2)
{
    if (player1.isMoving())
        player1.move();
    else
        player1.idle();
    player1.setSprite();

    if (player2.isMoving())
        player2.move();
    else
        player2.idle();
    player2.setSprite();
}

void    generate_map(sf::Vector2u& window_size, std::vector<sf::Sprite>& map_sprites, std::vector<sf::Texture>& textures)
{
    textures.push_back(sf::Texture());
    textures.back().loadFromFile("assets/2 Dungeon Tileset/1 Tiles/Tile_20.png");

    window_size.x = 20 * FRAME_SIZE * 2;
    window_size.y = 20 * FRAME_SIZE * 2;

    for (unsigned int i = 0; i < 20 * 2; ++i) {
        for (unsigned int j = 0; j < 20 * 2; ++j) {
            sf::Sprite sprite(textures[rand() % textures.size()]);
            sprite.setPosition(sf::Vector2f(i * FRAME_SIZE, j * FRAME_SIZE));
            map_sprites.push_back(sprite);
        }
    }
    for (auto& sprite : map_sprites) {
        sprite.setScale(sf::Vector2f(2.0f, 2.0f));
    }
}

void renderGame(sf::RenderWindow& window, std::vector<sf::Sprite>& map_sprites, Character& player1, Character& player2)
{
    window.clear();
    for (const auto& sprite : map_sprites) window.draw(sprite);
    window.draw(player1.getSprite());
    window.draw(player2.getSprite());
    window.display();
}

int main()
{
    sf::Vector2u window_size;
    std::vector<sf::Sprite> map_sprites;
    std::vector<sf::Texture> map_textures;
    generate_map(window_size, map_sprites, map_textures);

    sf::RenderWindow window(sf::VideoMode(window_size), "SFML Game Loop Example");

    sf::Texture walking_texture1;
    sf::Texture idle_texture1;
    if (!walking_texture1.loadFromFile("assets/1 Characters/1/D_Walk.png")
        || !idle_texture1.loadFromFile("assets/1 Characters/1/D_Idle.png"))
        return -1;

    sf::Texture walking_texture2;
    sf::Texture idle_texture2;
    if (!walking_texture2.loadFromFile("assets/1 Characters/2/D_Walk.png")
        || !idle_texture2.loadFromFile("assets/1 Characters/2/D_Idle.png"))
        return -1;


    Character player1(walking_texture1, idle_texture1);
    Character player2(walking_texture2, idle_texture2);

    while (window.isOpen()) {
        handleEvents(window, player1, player2);
        updateGameLogic(player1, player2);
        renderGame(window, map_sprites, player1, player2);
    }

    return 0;
}
