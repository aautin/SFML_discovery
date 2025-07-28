#include "Move.hpp"
#include "Character.hpp"
#include "Game.hpp"
#include "utils.hpp"

unsigned long getEndTimestamp(sf::Vector2f move)
{
	float totalDistance = abs(move.x) + abs(move.y);
	
	unsigned long currentTime = getCurrentTimeMillisecond();
	int totalSteps = static_cast<int>(totalDistance / STEP_SIZE + ((static_cast<int>(totalDistance) % STEP_SIZE) != 0 ? 1 : 0));

	return currentTime + totalSteps * STEP_TIME;
}

std::vector<unsigned long> getTimestamp(sf::Vector2f move)
{
	std::vector<unsigned long> timestamps;

	float totalDistance = abs(move.x) + abs(move.y);
	
	unsigned long currentTime = getCurrentTimeMillisecond();
	int totalSteps = static_cast<int>(totalDistance / STEP_SIZE + ((static_cast<int>(totalDistance) % STEP_SIZE) != 0 ? 1 : 0));
	
	for (int i = 0; i < totalSteps; ++i)
		timestamps.push_back(currentTime + i * STEP_TIME);

	return timestamps;
}

sf::Vector2f calculateMove(sf::Keyboard::Key direction, sf::Vector2u size)
{
	sf::Vector2f move(0, 0);
	if (direction == sf::Keyboard::Key::A)
		move.x = -(float)(size.x);
	else if (direction == sf::Keyboard::Key::D)
		move.x = size.x;
	else if (direction == sf::Keyboard::Key::W)
		move.y = -(float)(size.y);
	else if (direction == sf::Keyboard::Key::S)
		move.y = size.y;

	return move;
}

Move::Move(sf::Keyboard::Key direction, sf::Vector2u size)
	: AAction(50, 6, "./assets/1 Characters/1/D_Walk.png",
	getTimestamp(calculateMove(direction, size)), getEndTimestamp(calculateMove(direction, size))),
	_moveRemaining(calculateMove(direction, size)) {}

Move::~Move() {}

void Move::execute(Game& game, Character& character)
{
	sf::Vector2f move(0, 0);
	if (_moveRemaining.x > 0)
		move.x = (_moveRemaining.x < STEP_SIZE) ? _moveRemaining.x : STEP_SIZE;
	if (_moveRemaining.x < 0)
		move.x = (_moveRemaining.x > -STEP_SIZE) ? _moveRemaining.x : -STEP_SIZE;
	if (_moveRemaining.y > 0)
		move.y = (_moveRemaining.y < STEP_SIZE) ? _moveRemaining.y : STEP_SIZE;
	if (_moveRemaining.y < 0)
		move.y = (_moveRemaining.y > -STEP_SIZE) ? _moveRemaining.y : -STEP_SIZE;

	character.setPosition(character.getPosition().x + move.x, character.getPosition().y + move.y);

	_moveRemaining = sf::Vector2f(
		_moveRemaining.x - move.x,
		_moveRemaining.y - move.y
	);
}

bool Move::isFinished() const
{
	// Vérifier si le mouvement est terminé
	return _moveRemaining.x == 0 && _moveRemaining.y == 0;
}
