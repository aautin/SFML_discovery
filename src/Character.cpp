#include <sys/time.h>

#include <SFML/Graphics.hpp>
#include "Character.hpp"

unsigned long Character::getCurrentTimeMillisecond()
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

Character::Character(const sf::Texture& walking, const sf::Texture& idle) : _walking(walking), _idle(idle), _current(_idle)
{
	_position[0] = STEP_SIZE / 2;
	_position[1] = STEP_SIZE / 2;
	_move_distance = 0;
	_move_timestamp = 0;
	_anim_index = 0;
	_flip = false;
	
	_idle.setScale(sf::Vector2f(2.0f, 2.0f));
	_walking.setScale(sf::Vector2f(2.0f, 2.0f));

	_current = _idle;
	setSprite();
}
Character::~Character()
{
}

bool	Character::isMoving()
{
	return _move_distance > 0;
}
void	Character::move()
{
	if (_move_distance <= 0 || (this->getCurrentTimeMillisecond() - _move_timestamp < WALKING_FRAME_TIME))
		return;

	size_t moves = (this->getCurrentTimeMillisecond() - _move_timestamp) / WALKING_FRAME_TIME;
	_move_timestamp = this->getCurrentTimeMillisecond();
	_anim_index = (_anim_index + moves) % 6;

	int move_length = MOVE_SIZE * moves;
	_move_distance -= move_length;
	if (_move_distance <= 0) {
		_move_distance = 0;
		_current = _idle;
		_anim_index = 0;
	}

	switch (_move_direction) {
		case LEFT1:
			_position[0] -= move_length;
			break;
		case RIGHT1:
			_position[0] += move_length;
			break;
		case UP1:
			_position[1] -= move_length;
			break;
		case DOWN1:
			_position[1] += move_length;
			break;
		case LEFT2:
			_position[0] -= move_length;
			break;
		case RIGHT2:
			_position[0] += move_length;
			break;
		case UP2:
			_position[1] -= move_length;
			break;
		case DOWN2:
			_position[1] += move_length;
			break;
		default:
			break;
	}
}
void	Character::idle()
{
	if (this->getCurrentTimeMillisecond() - _move_timestamp < IDLE_FRAME_TIME)
		return;

	size_t moves = (this->getCurrentTimeMillisecond() - _move_timestamp) / IDLE_FRAME_TIME;
	_move_timestamp = this->getCurrentTimeMillisecond();
	_anim_index = (_anim_index + moves) % 4;
}
void	Character::setDirection(direction dir)
{
	_move_timestamp = getCurrentTimeMillisecond();
	_move_direction = dir;
	_move_distance = STEP_SIZE;

	_current = _walking;
}
void	Character::setSprite()
{
	_current.setPosition(sf::Vector2f(_position[0], _position[1]));
	_current.setTextureRect(
		sf::IntRect(sf::Vector2i(_anim_index * FRAME_SIZE, 0), sf::Vector2i(FRAME_SIZE, FRAME_SIZE))
	);
}
sf::Sprite	Character::getSprite()
{
	return _current;
}
