#ifndef MOVE_HPP
# define MOVE_HPP

# include "AAction.hpp"

# define STEP_SIZE 0.1f
# define RUN_SPEED 50

class Game;
class Character;
class Move : public AAction
{
	public:
		Move(sf::Keyboard::Key direction);
		~Move() {}

		void execute(Game& game, Character& character) override;
		bool isFinished() const override;
	private:
		sf::Vector2f 	_moveRemaining;
};

#endif