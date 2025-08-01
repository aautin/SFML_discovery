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
		~Character() {}

		void			event(sf::Event const& event);
		void			logic(Game& game);
		void			render(sf::RenderWindow& window, sf::Vector2u tileSize) const;

		void			setPosition(sf::Vector2f newPosition);
		sf::Vector2f	getPosition() const;
		bool			snapPosition();

		bool			isInput(sf::Keyboard::Key const& key) const;

	private:
		sf::Vector2f					_position;
		std::vector<sf::Keyboard::Key>	_inputs;
		std::unique_ptr<AAction>		_action;
	
		void	addInput(sf::Keyboard::Key const& key);
		void	removeInput(sf::Keyboard::Key const& key);
};

#endif