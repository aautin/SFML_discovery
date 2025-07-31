#include "Game.hpp"

Game::Game(std::string title, sf::Vector2u mapSize, sf::Vector2f tileSize)
: _window(sf::VideoMode(sf::Vector2u(mapSize.x * tileSize.x, mapSize.y * tileSize.y)), title),
  _tileSize(tileSize), _player(), _map(mapSize, tileSize)
{
	_window.setVerticalSyncEnabled(false);
}


// ------------------- Update Game -------------------
void Game::updateEvents()
{
	std::optional<sf::Event> event;
	while (event = _window.pollEvent()) {
		if (event->getIf<sf::Event::Closed>())
			_window.close();
		else if (event->getIf<sf::Event::KeyPressed>() || event->getIf<sf::Event::KeyReleased>()) {
			const auto& code = event->getIf<sf::Event::KeyPressed>() ?
				event->getIf<sf::Event::KeyPressed>()->code : event->getIf<sf::Event::KeyReleased>()->code;

			if (_player.isInput(code))
				_player.event(*event);
		}
	}
}

void Game::updateLogic()
{
	_player.logic(*this);
}

void Game::updateRender()
{
	_window.clear();

	_map.draw(_window, _tileSize);
	_player.draw(_window, _tileSize);

	_window.display();
}


// ------------------- Getters -------------------
sf::Vector2f Game::getTileSize() const
{
	return _tileSize;
}

sf::Vector2u Game::getMapSize() const
{
	return _map.getMapSize();
}
