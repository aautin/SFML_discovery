#include <algorithm>

#include "Game.hpp"
#include "Character.hpp"
#include "Idle.hpp"
#include "Move.hpp"

// ------------------- Constructor -------------------
Character::Character(sf::Vector2f tileSize)
	: _position{0, 0},
	_actionInput(),
	_arrowInput(),
	_arrow(std::make_unique<Arrow>(tileSize)),
	_action(std::make_unique<Idle>(tileSize))
{}


// ------------------- Event Logic Render -------------------
void	Character::event(sf::Event const& event)
{
	sf::Keyboard::Key key = event.is<sf::Event::KeyPressed>() ?
		event.getIf<sf::Event::KeyPressed>()->code : event.getIf<sf::Event::KeyReleased>()->code;
	auto inputHandler = event.is<sf::Event::KeyPressed>() ? &Character::addInput : &Character::removeInput;

	if (isActionInput(key))
		(this->*inputHandler)(_actionInput, key);
	else if (isArrowInput(key))
		(this->*inputHandler)(_arrowInput, key);
}

void	Character::logic(Game& game)
{
	if (_action->isFinished())
		_action = nullptr;
	if (_action)
		_action->update(game, *this);
	if (!_actionInput.empty() && (_action == nullptr || dynamic_cast<Idle*>(_action.get()) != nullptr))
		_action = std::make_unique<Move>(_actionInput.back(), game.getTileSize());
	if (_action == nullptr)
		_action = std::make_unique<Idle>(game.getTileSize());
	_action->update(game, *this);

	if (!_arrowInput.empty())
		_arrow->update(_arrowInput.back(), game);
}

sf::Sprite	Character::renderAction() const
{
	sf::Sprite characterSprite = _action->getFrame();
	characterSprite.setPosition(sf::Vector2f(_position[0], _position[1]));

	return characterSprite;
}

sf::Sprite	Character::renderArrow() const
{

	sf::Sprite arrowSprite = _arrow->getFrame();
	arrowSprite.setPosition(sf::Vector2f(
		_position[0] + arrowSprite.getPosition().x, _position[1] + arrowSprite.getPosition().y
	));

	return arrowSprite;
}


// ------------------- Position -------------------
void Character::setPosition(float x, float y)
{
	_position[0] = x;
	_position[1] = y;
}

sf::Vector2f Character::getPosition() const
{
	return sf::Vector2f(_position[0], _position[1]);
}


// ------------------- Input -------------------
void Character::addInput(std::vector<sf::Keyboard::Key>& input, sf::Keyboard::Key key)
{
	input.push_back(key);
}

void Character::removeInput(std::vector<sf::Keyboard::Key>& input, sf::Keyboard::Key key)
{
	input.erase(
        std::remove(input.begin(), input.end(), key),
        input.end()
    );
}

bool Character::isActionInput(sf::Keyboard::Key key) const
{
	return key == sf::Keyboard::Key::A
		|| key == sf::Keyboard::Key::D
		|| key == sf::Keyboard::Key::W
		|| key == sf::Keyboard::Key::S
		|| key == sf::Keyboard::Key::Space;
}

bool Character::isArrowInput(sf::Keyboard::Key key) const
{
	return key == sf::Keyboard::Key::Up
		|| key == sf::Keyboard::Key::Down
		|| key == sf::Keyboard::Key::Left
		|| key == sf::Keyboard::Key::Right;
}

bool Character::isInput(sf::Keyboard::Key key) const
{
	return isActionInput(key) || isArrowInput(key);
}
