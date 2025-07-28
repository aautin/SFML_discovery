#include "sys/time.h"
#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

// ------------------- Time -------------------
unsigned long getCurrentTimeMillisecond()
{
    struct timeval tv;
    gettimeofday(&tv, (void*)0);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}


// ------------------- Texture loading -------------------
sf::Texture loadTexture(const std::string& filepath)
{
    sf::Texture texture;
    if (!texture.loadFromFile(filepath)) {
        printf("Error: Failed to load texture from %s\n", filepath.c_str());
        // Return an empty texture instead of crashing
    }
    return texture;
}

// ------------------- Sprite appearance -------------------
void hideSprite(sf::Sprite& sprite)
{
	sprite.setColor(sf::Color(255, 255, 255, 0));
}

void fadeSprite(sf::Sprite& sprite)
{
	sprite.setColor(sf::Color(255, 255, 255, 100));
}

void showSprite(sf::Sprite& sprite)
{
	sprite.setColor(sf::Color(255, 255, 255, 255));
}
