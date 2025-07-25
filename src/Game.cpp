#include "Game.hpp"

Game::Game(std::string& title, size_t mapWidth, size_t mapHeight, sf::Texture& tile)
	: _player(Character()), _mapWidth(mapWidth), _mapHeight(mapHeight), _map(tile)
{
	sf::VideoMode mode(sf::Vector2u(
		_mapWidth * tile.getSize().x, _mapHeight * tile.getSize().y
	));
	_window.create(mode, title);

	// To be continued...
	// Here draw the entire map tiles in the _map attribute...

	updateRender();
}

Game::~Game()
{
}

void Game::run()
{
	while (_window.isOpen())
	{
		updateEvents();
		updateLogic();
		updateRender();
	}
}

bool isCharacterKey(sf::Keyboard::Key key)
{
	return key == sf::Keyboard::Key::A
		|| key == sf::Keyboard::Key::D
		|| key == sf::Keyboard::Key::W
		|| key == sf::Keyboard::Key::S
		|| key == sf::Keyboard::Key::Space;
}

void Game::updateEvents()
{
	std::optional<sf::Event> event;
	while (event = _window.pollEvent())
	{
		if (event->getIf<sf::Event::Closed>())
			_window.close();
		else if ((event->getIf<sf::Event::KeyPressed>()
			|| event->getIf<sf::Event::KeyReleased>())
			&& isCharacterKey(event->getIf<sf::Event::KeyReleased>()->code))
			_player.updateEvent(*event);
	}
}

void Game::updateLogic()
{
	_player.updateLogic(*this);
}

void Game::updateRender()
{
	_window.clear();
	_window.draw(_map);
	_window.draw(_player.getRender());
	_window.display();
}