#include <sys/time.h>

#include <SFML/System/Angle.hpp>
#include <SFML/Graphics.hpp>
#include "Character.hpp"

unsigned long Character::getCurrentTimeMillisecond()
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

Character::Character(const sf::Texture& walking, const sf::Texture& idle, const sf::Texture& arrow) : _walking(walking), _idle(idle), _current(_idle), _arrow(arrow)
{
	_position[0] = STEP_SIZE / 2;
	_position[1] = STEP_SIZE / 2;
	_arrow_direction = LEFT_ARROW;

	_move_distance = 0;
	_move_timestamp = 0;
	_anim_index = 0;
	
	_idle.setScale(sf::Vector2f(2.0f, 2.0f));
	_walking.setScale(sf::Vector2f(2.0f, 2.0f));

	_current = _idle;
	setCurrentSprite();
	setArrowSprite();
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
		case LEFT_MOVE:
			_position[0] -= move_length;
			break;
		case RIGHT_MOVE:
			_position[0] += move_length;
			break;
		case UP_MOVE:
			_position[1] -= move_length;
			break;
		case DOWN_MOVE:
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
void	Character::setMove(direction dir)
{
	_move_timestamp = getCurrentTimeMillisecond();
	_move_direction = dir;
	_move_distance = STEP_SIZE;

	_current = _walking;
}
void	Character::setArrow(direction dir)
{
	_arrow_direction = dir;
}
void	Character::setCurrentSprite()
{
	_current.setPosition(sf::Vector2f(_position[0], _position[1]));
	_current.setTextureRect(
		sf::IntRect(sf::Vector2i(_anim_index * FRAME_SIZE, 0), sf::Vector2i(FRAME_SIZE, FRAME_SIZE))
	);
}
void Character::setArrowSprite()
{
	_arrow.setOrigin(sf::Vector2f(FRAME_SIZE / 2, FRAME_SIZE / 2));

	switch (_arrow_direction) {
		case LEFT_ARROW:
			_arrow.setRotation(sf::degrees(0));
			_arrow.setPosition(sf::Vector2f(_position[0] - FRAME_SIZE + FRAME_SIZE, _position[1] + FRAME_SIZE));
			break;
		case RIGHT_ARROW:
			_arrow.setRotation(sf::degrees(180));
			_arrow.setPosition(sf::Vector2f(_position[0] + FRAME_SIZE + FRAME_SIZE, _position[1] + FRAME_SIZE));
			break;
		case UP_ARROW:
			_arrow.setRotation(sf::degrees(90));
			_arrow.setPosition(sf::Vector2f(_position[0] + FRAME_SIZE, _position[1] - FRAME_SIZE + FRAME_SIZE));
			break;
		case DOWN_ARROW:
			_arrow.setRotation(sf::degrees(270));
			_arrow.setPosition(sf::Vector2f(_position[0] + FRAME_SIZE, _position[1] + FRAME_SIZE + FRAME_SIZE));
			break;
		default:
			break;
	}
}
sf::Sprite	Character::getCurrentSprite()
{
	return _current;
}
sf::Sprite	Character::getArrowSprite()
{
	return _arrow;
}
