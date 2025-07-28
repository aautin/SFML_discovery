#ifndef ARROW_HPP
# define ARROW_HPP

# include <SFML/Graphics.hpp>

# include "AAction.hpp"

class Game;
class Character;
class Arrow : public AAction
{
	public:
		Arrow(sf::Vector2f tileSize);
		~Arrow() {};
	
		void				update(sf::Keyboard::Key key, Game& game);
		void				execute(Game& game, Character& character) override {}
		bool				isFinished() const override { return false; }
		sf::Keyboard::Key	getDirectionKey() const { return _directionKey; }

	private:
		sf::Keyboard::Key	_directionKey;
};

#endif