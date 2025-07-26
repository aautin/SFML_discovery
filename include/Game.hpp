#ifndef GAME_HPP
# define GAME_HPP

# include <SFML/Graphics.hpp>

# include "Character.hpp"

class Game
{
	public:
		Game(std::string& title, size_t mapWidth, size_t mapHeight, sf::Texture& tile);
		~Game();

		void run();

	private:
		void	updateEvents();
		void	updateLogic();
		void	updateRender();

		bool	isCharacterKey(sf::Keyboard::Key key);

		void	generateMap(const sf::Texture& map_texture);
		void	drawMap(sf::RenderWindow& window);

		sf::RenderWindow	_window;
		Character 			_player;

		std::vector<sf::Sprite>	_map;
		size_t					_mapWidth;
		size_t					_mapHeight;
};

#endif