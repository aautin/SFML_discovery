#include <algorithm>

#include "Game.hpp"
#include "Character.hpp"
#include "Idle.hpp"
#include "Move.hpp"

// ------------------- Constructor -------------------
Character::Character() : 
	_position{0, 0},
	_input(),
	_action(std::make_unique<Idle>()) {}


// ------------------- Event Logic Render -------------------
void	Character::event(sf::Event const& event)
{
	if (event.is<sf::Event::KeyPressed>())
		addInput(event.getIf<sf::Event::KeyPressed>()->code);
	else if (event.is<sf::Event::KeyReleased>())
		removeInput(event.getIf<sf::Event::KeyReleased>()->code);
}

void	Character::logic(Game& game)
{
	if (_action->isFinished())
		_action = nullptr;
	
	if (_action)
		_action->update(game, *this);

	if (!_input.empty() && (_action == nullptr || dynamic_cast<Idle*>(_action.get()) != nullptr)) {
		switch (_input.back()) {
			case sf::Keyboard::Key::A:
				_action = std::make_unique<Move>(sf::Vector2f(-(float)(game.getTileSize().x), 0));
				break;
			case sf::Keyboard::Key::D:
				_action = std::make_unique<Move>(sf::Vector2f(game.getTileSize().x, 0));
				break;
			case sf::Keyboard::Key::W:
				_action = std::make_unique<Move>(sf::Vector2f(0, -(float)(game.getTileSize().y)));
				break;
			case sf::Keyboard::Key::S:
				_action = std::make_unique<Move>(sf::Vector2f(0, game.getTileSize().y));
				break;
			default:
				break;
		}
    }

	if (_action == nullptr)
		_action = std::make_unique<Idle>();

	_action->update(game, *this);
}

sf::Sprite	Character::render() const
{
	sf::Sprite characterSprite = _action->getFrame();
	characterSprite.setPosition(sf::Vector2f(_position[0], _position[1]));
	return characterSprite;
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
void Character::addInput(sf::Keyboard::Key key)
{
	_input.push_back(key);
}

void Character::removeInput(sf::Keyboard::Key key)
{
	_input.erase(
        std::remove(_input.begin(), _input.end(), key),
        _input.end()
    );
}

bool Character::isCharacterInput(sf::Keyboard::Key key) const
{
	return key == sf::Keyboard::Key::A
		|| key == sf::Keyboard::Key::D
		|| key == sf::Keyboard::Key::W
		|| key == sf::Keyboard::Key::S
		|| key == sf::Keyboard::Key::Space;
}
