#include <SFML/Graphics.hpp>
#include "Character.hpp"

Character::Character(const sf::Texture& texture) : _sprite(texture)
{
	_position[0] = 0;
	_position[1] = 0;
	_anim_index = 0;
}
Character::~Character()
{
}

bool	Character::isMoving()
{
	return _direction[0] != 0 || _direction[1] != 0;
}
void	Character::move()
{
	_position[0] = _position[0];
	_position[1] = _position[1];
	
	_direction[0] -= MOVE_SIZE;
	if (_direction[0] < 0)
		_direction[0] = 0;
	
	_direction[1] -= MOVE_SIZE;
	if (_direction[1] < 0)
		_direction[1] = 0;

	_anim_index = (_anim_index + 1) % 6;
	printf("Player is moving to (%f, %f) with animation index %u\n", _direction[0], _direction[1], _anim_index);
}
void	Character::setDirection(float x, float y)
{
	_direction[0] = x;
	_direction[1] = y;
}
void	Character::setSprite()
{
	_sprite.setPosition(sf::Vector2f(_position[0], _position[1]));
	_sprite.setTextureRect(
		sf::IntRect(sf::Vector2i(_anim_index * FRAME_SIZE, 0), sf::Vector2i(FRAME_SIZE, FRAME_SIZE))
	);
}

sf::Sprite	Character::getSprite()
{
	return _sprite;
}
