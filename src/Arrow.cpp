#include "Arrow.hpp"
#include "Game.hpp"

Arrow::Arrow()
	: AAction(INFINITE, 1, "./assets/2 Dungeon Tileset/2 Objects/arrow.png", {}, NEVER)
{
	_directionKey = sf::Keyboard::Key::Unknown;
	_animation.setDirection(sf::degrees(0), sf::Vector2f(0, 0));
}

void Arrow::update(sf::Keyboard::Key key, Game& game)
{
	if (_directionKey == key)
		return;

	_directionKey = key;
	switch (key)
	{
		case sf::Keyboard::Key::Left:
			_animation.setDirection(sf::degrees(0), sf::Vector2f(-(float)(game.getTileSize().x), 0));
			break;
		case sf::Keyboard::Key::Right:
			_animation.setDirection(sf::degrees(180), sf::Vector2f(game.getTileSize().x, 0));
			break;
		case sf::Keyboard::Key::Up:
			_animation.setDirection(sf::degrees(90), sf::Vector2f(0, -(float)(game.getTileSize().y)));
			break;
		case sf::Keyboard::Key::Down:
			_animation.setDirection(sf::degrees(270), sf::Vector2f(0, game.getTileSize().y));
			break;
		default:
			return;
	}
}
