#ifndef GAME_HPP
# define GAME_HPP

# include <SFML/Graphics.hpp>

# include "Character.hpp"
# include "Map.hpp"

class Game
{
	public:
		Game(std::string title, std::string mapFilename, sf::Vector2u tileSize);
		~Game() {}

		bool	isRunning() const;
		void	events();
		void	logic();
		void	render();

		sf::Vector2u	getTileSize() const;

	private:
		sf::RenderWindow	_window;
		Character 			_player;
		Map					_map;
		sf::Vector2u		_tileSize;
};

#endif