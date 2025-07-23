#include "sys/time.h"

#include <SFML/Graphics.hpp>

// ------------------- Time -------------------
unsigned long getCurrentTimeMillisecond()
{
    struct timeval tv;
    gettimeofday(&tv, (void*)0);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
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
