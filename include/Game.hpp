#ifndef GAME_HPP
# define GAME_HPP

# include <SFML/Graphics.hpp>

# include "Character.hpp"

class Game
{
	public:
		Game(std::string title, sf::Vector2u mapSize);
		~Game() {}

		void	run();

		sf::Vector2u	getTileSize() const;
		sf::Vector2u	getMapSize() const;

	private:
		void	updateEvents();
		void	updateLogic();
		void	updateRender();

		void	generateMap();
		void	drawMap();

		sf::RenderWindow	_window;
		Character 			_player;

		sf::Texture				_tileTexture;
		sf::Vector2u			_tileSize;
		std::vector<sf::Sprite>	_map;
		sf::Vector2u			_mapSize;
};

#endif