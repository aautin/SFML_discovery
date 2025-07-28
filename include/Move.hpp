#ifndef MOVE_HPP
# define MOVE_HPP

# include "AAction.hpp"

# define STEP_SIZE 3
# define STEP_TIME 50

class Game;
class Character;
class Move : public AAction
{
	public:
		Move(sf::Keyboard::Key direction, sf::Vector2u size);
		~Move();
	
		void execute(Game& game, Character& character) override;
		bool isFinished() const override;
	private:
		sf::Vector2f _moveRemaining;
};

#endif