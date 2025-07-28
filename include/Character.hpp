#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <memory>
# include <SFML/Graphics.hpp>

# include "AAction.hpp"
# include "Arrow.hpp"

class Game;
class Character
{
	public:
		Character(sf::Vector2f tileSize);
		~Character() {};

		void		event(sf::Event const& event);
		void		logic(Game& game);
		sf::Sprite	renderAction() const;
		sf::Sprite	renderArrow() const;

		void			setPosition(float x, float y);
		sf::Vector2f	getPosition() const;

		void			addInput(std::vector<sf::Keyboard::Key>& input, sf::Keyboard::Key key);
		void			removeInput(std::vector<sf::Keyboard::Key>& input, sf::Keyboard::Key key);
		bool			isInput(sf::Keyboard::Key key) const;
		
	private:
		float							_position[2];
		
		std::vector<sf::Keyboard::Key>	_arrowInput;
		std::unique_ptr<Arrow>			_arrow;
		bool							isArrowInput(sf::Keyboard::Key key) const;

		std::vector<sf::Keyboard::Key>	_actionInput;
		std::unique_ptr<AAction>		_action;
		bool							isActionInput(sf::Keyboard::Key key) const;
};

#endif