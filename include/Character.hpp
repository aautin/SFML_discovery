#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <memory>
# include <SFML/Graphics.hpp>

# include "AAction.hpp"

class Game;
class Character
{
	public:
		Character();
		~Character() {};

		void		event(sf::Event const& event);
		void		logic(Game& game);
		sf::Sprite	render() const;

		void			setPosition(float x, float y);
		sf::Vector2f	getPosition() const;

		void			addInput(sf::Keyboard::Key key);
		void			removeInput(sf::Keyboard::Key key);
		bool			isCharacterInput(sf::Keyboard::Key key) const;

	private:
		float							_position[2];
		std::vector<sf::Keyboard::Key>	_input;
		std::unique_ptr<AAction>		_action;
};

#endif