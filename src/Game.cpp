#include "Game.hpp"

Game::Game(std::string& title, size_t mapWidth, size_t mapHeight, sf::Texture& tile)
	: _player(Character()), _mapWidth(mapWidth), _mapHeight(mapHeight),
	_tileSize(sf::Vector2u(tile.getSize().x, tile.getSize().y))
{
	sf::VideoMode mode(sf::Vector2u(
		_mapWidth * _tileSize.x, _mapHeight * _tileSize.y
	));
	_window.create(mode, title);

	generateMap(tile);
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

bool Game::isCharacterKey(sf::Keyboard::Key key)
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

	drawMap(_window);
	_window.draw(_player.getRender());

	_window.display();
}

void Game::generateMap(const sf::Texture& map_texture)
{
	_map.clear();
	for (size_t i = 0; i < _mapWidth; ++i) {
		for (size_t j = 0; j < _mapHeight; ++j) {
			sf::Sprite sprite(map_texture);
			sprite.setPosition(sf::Vector2f(i * map_texture.getSize().x, j * map_texture.getSize().y));
			_map.push_back(sprite);
		}
	}
}

void Game::drawMap(sf::RenderWindow& window)
{
	std::vector<sf::Sprite>::const_iterator it;
	for (it = _map.begin(); it != _map.end(); ++it)
		window.draw(*it);
}

sf::Vector2u Game::getTileSize() const
{
	return _tileSize;
}
