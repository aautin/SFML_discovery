#ifndef UTILS_HPP
# define UTILS_HPP

# include <SFML/Graphics.hpp>

// ------------------- Time -------------------
unsigned long	getCurrentTimeMillisecond();

// ------------------- Texture loading -------------------
sf::Texture	loadTexture(const std::string& filepath);

// ------------------- Sprite appearance -------------------
void	hideSprite(sf::Sprite& sprite);
void	fadeSprite(sf::Sprite& sprite);
void	showSprite(sf::Sprite& sprite);
void	scale(sf::Sprite& sprite, sf::Texture& texture, sf::Vector2f targetSize);


#endif
