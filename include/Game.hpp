#ifndef GAME_HPP
# define GAME_HPP

# include <SFML/Graphics.hpp>

# include "Character.hpp"
# include "Map.hpp"

class Game
{
	public:
		Game(std::string title, sf::Vector2u mapSize, sf::Vector2f tileSize);
		~Game() {}

		void	updateEvents();
		void	updateLogic();
		void	updateRender();

		sf::Vector2f	getTileSize() const;
		sf::Vector2u	getMapSize() const;

	private:
		sf::RenderWindow	_window;
		Character 			_player;
		Map					_map;
		sf::Vector2f		_tileSize;
};

#endif