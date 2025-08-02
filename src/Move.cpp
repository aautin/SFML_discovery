#include "Move.hpp"
#include "Character.hpp"
#include "Game.hpp"
#include "utils.hpp"

Move::Move(sf::Keyboard::Key direction)
	: AAction(RUN_SPEED, "./assets/1 Characters/1/D_Walk.png")
{
	_moveRemaining = directionToMove(direction);

	unsigned long startTime = getCurrentTimeMillisecond();
	size_t steps = 0;
	for (float move = 0.f; move < 1.f; move += STEP_SIZE) {
		steps++;
		_executeTimestamps.push_back(startTime + (steps * RUN_SPEED));
	}
}

void Move::execute(Game& game, Character& character)
{
	if (_moveRemaining.x < 0 ) {
		character.setPosition(sf::Vector2f(
			character.getPosition().x - STEP_SIZE,
			character.getPosition().y
		));
		_moveRemaining += sf::Vector2f(STEP_SIZE, 0);
	}
	else if (_moveRemaining.x > 0) {
		character.setPosition(sf::Vector2f(
			character.getPosition().x + STEP_SIZE,
			character.getPosition().y
		));
		_moveRemaining -= sf::Vector2f(STEP_SIZE, 0);
	}
	if (_moveRemaining.y < 0) {
		character.setPosition(sf::Vector2f(
			character.getPosition().x,
			character.getPosition().y - STEP_SIZE
		));
		_moveRemaining += sf::Vector2f(0, STEP_SIZE);
	}
	else if (_moveRemaining.y > 0) {
		character.setPosition(sf::Vector2f(
			character.getPosition().x,
			character.getPosition().y + STEP_SIZE
		));
		_moveRemaining -= sf::Vector2f(0, STEP_SIZE);
	}
	
	if (character.snapPosition())
		_moveRemaining = sf::Vector2f(0, 0);
}

bool Move::isFinished() const
{
	return _moveRemaining.x == 0 && _moveRemaining.y == 0;
}
