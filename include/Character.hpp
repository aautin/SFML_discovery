#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <memory>
# include <SFML/Graphics.hpp>

# include "AAction.hpp"

class Character
{
	public:
		Character();
		~Character();

		void		updateEvent(sf::Event const& event);
		void		updateLogic(Game& game);
		sf::Sprite	getRender() const;

		void			setPosition(float x, float y);
		sf::Vector2f	getPosition() const;

	private:
		float						_position[2];
		sf::Keyboard::Key			_input;
		std::unique_ptr<AAction>	_action;
};

#endif