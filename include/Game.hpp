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
		void updateEvents();
		void updateLogic();
		void updateRender();

		bool isCharacterKey(sf::Keyboard::Key key);

		sf::RenderWindow	_window;
		Character 			_player;

		sf::Sprite			_map;
		size_t				_mapWidth;
		size_t				_mapHeight;
};

#endif