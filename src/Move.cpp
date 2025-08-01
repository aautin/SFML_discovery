#include "Move.hpp"
#include "Character.hpp"
#include "Game.hpp"
#include "utils.hpp"

Move::Move(sf::Keyboard::Key direction)
	: AAction(50, "./assets/1 Characters/1/D_Walk.png"), 
	_lastMove(getCurrentTimeMillisecond()), _moveRemaining(0, 0)
{
	if (direction == sf::Keyboard::Key::A)
		_moveRemaining.x = -1;
	else if (direction == sf::Keyboard::Key::D)
		_moveRemaining.x = 1;
	else if (direction == sf::Keyboard::Key::W)
		_moveRemaining.y = -1;
	else if (direction == sf::Keyboard::Key::S)
		_moveRemaining.y = 1;
}

void Move::execute(Game& game, Character& character)
{
	if (_moveRemaining.x < 0 ) {
		character.setPosition(sf::Vector2f(
			character.getPosition().x - STEP_SIZE,
			character.getPosition().y
		));
		_moveRemaining.x += STEP_SIZE;
	}
	else if (_moveRemaining.x > 0) {
		character.setPosition(sf::Vector2f(
			character.getPosition().x + STEP_SIZE,
			character.getPosition().y
		));
		_moveRemaining.x -= STEP_SIZE;
	}
	if (_moveRemaining.y < 0) {
		character.setPosition(sf::Vector2f(
			character.getPosition().x,
			character.getPosition().y - STEP_SIZE
		));
		_moveRemaining.y += STEP_SIZE;
	}
	else if (_moveRemaining.y > 0) {
		character.setPosition(sf::Vector2f(
			character.getPosition().x,
			character.getPosition().y + STEP_SIZE
		));
		_moveRemaining.y -= STEP_SIZE;
	}

	_lastMove = getCurrentTimeMillisecond();
	
	if (character.snapPosition())
		_moveRemaining = sf::Vector2f(0, 0);
}

bool Move::isFinished() const
{
	return _moveRemaining.x == 0 && _moveRemaining.y == 0;
}
