#include <sys/time.h>

#include <SFML/System/Angle.hpp>
#include <SFML/Graphics.hpp>
#include "Character.hpp"


Character::Character(const sf::Texture& walking, const sf::Texture& idle,
					 const sf::Texture& arrow, const sf::Texture& shoot)
	: _walking(walking), _idle(idle), _current(_idle), _arrow(arrow), _shoot(shoot)
{
	_position[0] = STEP_SIZE / 2;
	_position[1] = STEP_SIZE / 2;

	_move_length = 0;
	_move_timestamp = 0;
	
	_shoot_direction = LEFT_ARROW;
	_shoot_timestamp = 0;
	
	_idle.setScale(sf::Vector2f(2.0f, 2.0f));
	_walking.setScale(sf::Vector2f(2.0f, 2.0f));
	_shoot.setScale(sf::Vector2f(2.0f, 2.0f));
	
	_cooldown = 0;

	_anim_index = 0;
	_current = _idle;
	setCurrentSprite();
	setArrowSprite();
}
Character::~Character()
{
}

bool	Character::isOnCooldown()
{
	return getCurrentTimeMillisecond() <= _cooldown;
}
bool	Character::isMoving()
{
	return _move_length > 0;
}
bool	Character::isShooting()
{
	return _shoot_length > 0;
}
bool	Character::isIdle()
{
	return !isMoving() && !isShooting();
}
void	Character::move()
{
	if (_move_length <= 0 || (this->getCurrentTimeMillisecond() - _move_timestamp < WALKING_FRAME_TIME))
		return;

	size_t frames = (this->getCurrentTimeMillisecond() - _move_timestamp) / WALKING_FRAME_TIME;
	_move_timestamp = this->getCurrentTimeMillisecond();
	_anim_index = (_anim_index + frames) % 6;

	int move_length = MOVE_SIZE * frames;
	if (_move_length - move_length <= 0) {
		move_length = _move_length;
		_move_length = 0;
		_current = _idle;
		_anim_index = 0;
	}
	else
		_move_length -= move_length;

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
void	Character::shoot()
{
	if ((this->getCurrentTimeMillisecond() - _shoot_timestamp < ATTACK_FRAME_TIME))
		return;

	size_t frames = (this->getCurrentTimeMillisecond() - _shoot_timestamp) / ATTACK_FRAME_TIME;
	_shoot_timestamp = this->getCurrentTimeMillisecond();
	if (_shoot_length - frames <= 0) {
		_shoot_length = 0;
		_current = _idle;
	}
	else {
		_anim_index = _anim_index + frames;
		_shoot_length -= frames;
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
	_move_direction = dir;
	_move_length = STEP_SIZE;
	_move_timestamp = getCurrentTimeMillisecond();
	_anim_index = 0;

	_current = _walking;
}
void	Character::setArrow(direction dir)
{
	_shoot_direction = dir;
}
void	Character::setShoot()
{
	_shoot_length = 4;
	_shoot_timestamp = getCurrentTimeMillisecond();
	_anim_index = 0;
	_cooldown = _shoot_timestamp + COOLDOWN;

	_current = _shoot;
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
	showSprite(_arrow);
	
	switch (_shoot_direction) {
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
	}

	if (isMoving() || isShooting() || isOnCooldown()) {
		disableSprite(_arrow);
		printf("Arrow disabled\n");
	}
	else
		printf("Arrow enabled\n");
}
sf::Sprite	Character::getCurrentSprite()
{
	return _current;
}
sf::Sprite	Character::getArrowSprite()
{
	return _arrow;
}
