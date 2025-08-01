#include <algorithm>
#include <cmath>

#include "Game.hpp"
#include "Character.hpp"
#include "Idle.hpp"
#include "Move.hpp"

// ------------------- Constructor -------------------
Character::Character()
	: _position(0, 0),
	  _action(std::make_unique<Idle>())
{}


// ------------------- Event Logic Render -------------------
void Character::event(sf::Event const& event)
{
	if (event.is<sf::Event::KeyPressed>())
		addInput(event.getIf<sf::Event::KeyPressed>()->code);
	else if (event.is<sf::Event::KeyReleased>())
		removeInput(event.getIf<sf::Event::KeyReleased>()->code);
}

void Character::logic(Game& game)
{
	if (_action->isFinished())
		_action = std::make_unique<Idle>();

	if (dynamic_cast<Idle*>(_action.get()) != nullptr && !_inputs.empty())
		_action = std::make_unique<Move>(_inputs.back());

	_action->update(game, *this);
}

void Character::render(sf::RenderWindow& window, sf::Vector2u tileSize) const
{
	sf::Sprite characterSprite = _action->getFrame();
	setScale(characterSprite, Vector2f(tileSize * 2));
	setOffsetPosition(characterSprite, _position, tileSize);
	window.draw(characterSprite);
}


// ------------------- Position -------------------
void Character::setPosition(sf::Vector2f newPosition)
{
	_position = newPosition;
}

sf::Vector2f Character::getPosition() const
{
	return _position;
}

bool Character::snapPosition()
{
	sf::Vector2f snappedPosition = _position;

	snappedPosition.x = std::round(snappedPosition.x);
	snappedPosition.y = std::round(snappedPosition.y);

	if (isToleratedDifference(_position, snappedPosition, 0.01f)) {
		_position = snappedPosition;
		return true;
	}
	return false;
}


// ------------------- Input -------------------
void Character::addInput(sf::Keyboard::Key const& key)
{
	_inputs.push_back(key);
}

void Character::removeInput(sf::Keyboard::Key const& key)
{
	_inputs.erase(
        std::remove(_inputs.begin(), _inputs.end(), key),
        _inputs.end()
    );
}

bool Character::isInput(sf::Keyboard::Key const& key) const
{
	switch (key)
	{
		case sf::Keyboard::Key::A:
		case sf::Keyboard::Key::D:
		case sf::Keyboard::Key::W:
		case sf::Keyboard::Key::S:
			return true;
	}
	return false;
}
