#include "Game.hpp"
// #include "Character.hpp"
#include "utils.hpp"


// ------------------- Constructor -------------------
Game::Game(std::string title, sf::Vector2f mapSize, sf::Vector2f tileSize)
: _mapSize(mapSize), _tileSize(tileSize), _tileTexture(loadTexture("./assets/2 Dungeon Tileset/1 Tiles/Tile_20.png")), _player(tileSize)
{
	generateMap();

	sf::VideoMode mode(sf::Vector2u(_mapSize.x * _tileSize.x, _mapSize.y * _tileSize.y));
    _window.create(mode, title);

	updateRender();
}


// ------------------- Main Loop -------------------
void Game::updateEvents()
{
	std::optional<sf::Event> event;
	while (event = _window.pollEvent())
	{
		if (event->getIf<sf::Event::Closed>())
			_window.close();
		// else if (event->getIf<sf::Event::KeyPressed>()
			// && _player.isInput(event->getIf<sf::Event::KeyPressed>()->code))
			// _player.event(*event);
		// else if (event->getIf<sf::Event::KeyReleased>()
			// && _player.isInput(event->getIf<sf::Event::KeyReleased>()->code))
			// _player.event(*event);
	}
}

void Game::updateLogic()
{
	_player.logic(*this);
}

void Game::updateRender()
{
	_window.clear();

	drawMap();
	_window.draw(_player.renderArrow());
	_window.draw(_player.renderAction());

	_window.display();
}

void Game::run()
{
	while (_window.isOpen())
	{
		updateEvents();
		updateLogic();
		updateRender();
		sf::sleep(sf::milliseconds(20));
	}
}


// ------------------- Map -------------------
void Game::generateMap()
{
	_map.clear();
	for (float i = 0; i < _mapSize.x; ++i) {
		for (float j = 0; j < _mapSize.y; ++j) {
			sf::Sprite sprite(_tileTexture);
			scale(sprite, _tileTexture, _tileSize);
			printf("Tile position: %f, %f\n", i * _tileSize.x, j * _tileSize.y);
			sprite.setPosition(sf::Vector2f(i * _tileSize.x, j * _tileSize.y));
			_map.push_back(sprite);
		}
	}
}

void Game::drawMap()
{
	std::vector<sf::Sprite>::const_iterator it;
	for (it = _map.begin(); it != _map.end(); ++it)
		_window.draw(*it);
}


// ------------------- Getters -------------------
sf::Vector2f Game::getTileSize() const
{
	return _tileSize;
}

sf::Vector2f Game::getMapSize() const
{
	return _mapSize;
}
