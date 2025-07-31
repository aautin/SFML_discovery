#include "Game.hpp"

Game::Game(std::string title, std::string mapFilename, sf::Vector2f tileSize)
: _map(tileSize, mapFilename), _tileSize(tileSize), _player(),
  _window()
{
	_window.setVerticalSyncEnabled(false);
}


// ------------------- Update Game -------------------
bool Game::isRunning() const
{
	return _window.isOpen();
}

void Game::events()
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

void Game::logic()
{
	_player.logic(*this);
}

void Game::render()
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
