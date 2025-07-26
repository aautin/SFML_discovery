#include "Character.hpp"
#include "Move.hpp"

Character::Character()
{
	_position[0] = 0;
	_position[1] = 0;
	_input = sf::Keyboard::Key::Unknown;
	_action = std::make_unique<Idle>();
}

Character::~Character()
{
}

void	Character::updateEvent(sf::Event const& event)
{
	if (event.is<sf::Event::KeyPressed>())
		_input = event.getIf<sf::Event::KeyPressed>()->code;
	else if (event.is<sf::Event::KeyReleased>()
		&& _input == event.getIf<sf::Event::KeyReleased>()->code)
		_input = sf::Keyboard::Key::Unknown;
}

void	Character::updateLogic(Game& game)
{
	if (_input != sf::Keyboard::Key::Unknown
		&& dynamic_cast<Idle*>(_action.get()) != nullptr) {
		switch (_input) {
			case sf::Keyboard::Key::A:
				_action = std::make_unique<MoveLeft>(game.getTileSize());
				break;
			case sf::Keyboard::Key::D:
				_action = std::make_unique<MoveRight>(game.getTileSize());
				break;
			case sf::Keyboard::Key::W:
				_action = std::make_unique<MoveUp>(game.getTileSize());
				break;
			case sf::Keyboard::Key::S:
				_action = std::make_unique<MoveDown>(game.getTileSize());
				break;
			// case sf::Keyboard::Key::Space:
			// 	_action = std::make_unique<Shoot>();
			// 	break;
			default:
				break;
		}
    }

	if (_action->isFinished())
		_action = std::make_unique<Idle>();
	_action->update(game, *this);
}

sf::Sprite	Character::getRender() const
{
	sf::Sprite frame = _action->getFrame();
	frame.setPosition(sf::Vector2f(
		frame.getPosition().x + _position[0],
		frame.getPosition().y + _position[1])
	);

	return frame;
}

void Character::setPosition(float x, float y)
{
	_position[0] = x;
	_position[1] = y;
}

sf::Vector2f Character::getPosition() const
{
	return sf::Vector2f(_position[0], _position[1]);
}
