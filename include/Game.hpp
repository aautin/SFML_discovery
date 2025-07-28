#ifndef GAME_HPP
# define GAME_HPP

# include <SFML/Graphics.hpp>

# include "Character.hpp"

class Game
{
	public:
		Game(std::string title, sf::Vector2f mapSize, sf::Vector2f tileSize);
		~Game() {}

		void	run();

		sf::Vector2f	getTileSize() const;
		sf::Vector2f	getMapSize() const;

	private:
		void	updateEvents();
		void	updateLogic();
		void	updateRender();

		void	generateMap();
		void	drawMap();

		sf::RenderWindow	_window;
		Character 			_player;

		sf::Texture				_tileTexture;
		sf::Vector2f			_tileSize;
		std::vector<sf::Sprite>	_map;
		sf::Vector2f			_mapSize;
};

#endif