#ifndef UTILS_HPP
# define UTILS_HPP

# include <SFML/Graphics.hpp>

// ------------------- Time -------------------
unsigned long	getCurrentTimeMillisecond();

// ------------------- Texture loading -------------------
sf::Texture		loadTexture(const std::string& filepath);

// ------------------- Sprite Getters -------------------
size_t 			getFramesNb(sf::Vector2u textureSize);
sf::Vector2u	getFramesSize(sf::Vector2u textureSize);
sf::Vector2f	getSpriteSize(sf::Sprite const& sprite);

// ------------------- Sprite -------------------
void			setScale(sf::Sprite& sprite, sf::Vector2f targetSize);
void			setOffsetPosition(sf::Sprite& sprite, sf::Vector2f gridPosition, sf::Vector2u tileSize);

// ------------------- Vector Operation -------------------
sf::Vector2f	operator*(const sf::Vector2f& lhs, const float rhs);
sf::Vector2u	operator*(const sf::Vector2u& lhs, const int rhs);
sf::Vector2u	Vector2u(const sf::Vector2f& v);
sf::Vector2f	Vector2f(const sf::Vector2u& v);

// ------------------- Other utility functions -------------------
bool			isToleratedDifference(sf::Vector2f value, sf::Vector2f target, float tolerance);

#endif