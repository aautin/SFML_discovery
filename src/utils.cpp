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

// ------------------- Sprite Getters -------------------
size_t getFramesNb(sf::Vector2u textureSize)
{
    if (textureSize.x > textureSize.y)
        return textureSize.x / textureSize.y;
    else if (textureSize.y > textureSize.x)
        return textureSize.y / textureSize.x;
    else
        return 1;
}

sf::Vector2u getFramesSize(sf::Vector2u textureSize)
{
    if (textureSize.x > textureSize.y)
        textureSize.x = textureSize.y;
    else if (textureSize.y > textureSize.x)
        textureSize.y = textureSize.x;

    return textureSize;
}

sf::Vector2f getSpriteSize(sf::Sprite const& sprite)
{
    return sf::Vector2f(
        static_cast<float>(sprite.getTextureRect().size.x) * sprite.getScale().x,
        static_cast<float>(sprite.getTextureRect().size.y) * sprite.getScale().y
    );
}


// ------------------- Sprite Setters -------------------
void setScale(sf::Sprite& sprite, sf::Vector2f targetSize)
{
    sf::Vector2f scale(
        targetSize.x / static_cast<float>(sprite.getTextureRect().size.x),
        targetSize.y / static_cast<float>(sprite.getTextureRect().size.y)
    );

    sprite.setScale(scale);
}

void setOffsetPosition(sf::Sprite& sprite, sf::Vector2f gridPosition, sf::Vector2u tileSize)
{
    sf::Vector2f spriteSize = getSpriteSize(sprite);

    sf::Vector2f offset(
        (tileSize.x - spriteSize.x) / 2.0f,
        (tileSize.y - spriteSize.y) / 2.0f
    );

    sprite.setPosition(sf::Vector2f(
        gridPosition.x * static_cast<float>(tileSize.x) + offset.x,
        gridPosition.y * static_cast<float>(tileSize.y) + offset.y
    ));
}


// ------------------- Vector Operation -------------------
sf::Vector2f operator*(const sf::Vector2f& lhs, const float rhs)
{
    return sf::Vector2f(lhs.x * rhs, lhs.y * rhs);
}

sf::Vector2u operator*(const sf::Vector2u& lhs, const int rhs)
{
    return sf::Vector2u(lhs.x * rhs, lhs.y * rhs);
}

sf::Vector2u Vector2u(const sf::Vector2f& v)
{
    return sf::Vector2u(static_cast<unsigned int>(v.x), static_cast<unsigned int>(v.y));
}

sf::Vector2f Vector2f(const sf::Vector2u& v)
{
    return sf::Vector2f(static_cast<float>(v.x), static_cast<float>(v.y));
}


// ------------------- Other utility functions -------------------
bool isToleratedDifference(sf::Vector2f value, sf::Vector2f target, float tolerance)
{
    return std::abs(value.x - target.x) < tolerance && std::abs(value.y - target.y) < tolerance;
}
