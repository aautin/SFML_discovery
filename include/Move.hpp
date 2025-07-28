#ifndef MOVE_HPP
# define MOVE_HPP

# include "AAction.hpp"
# include "Character.hpp"
# include "Game.hpp"

# define STEP_SIZE 3
# define STEP_TIME 50

class Move : public AAction
{
	public:
		Move(sf::Vector2f move);
		~Move();
	
		void execute(Game& game, Character& character) override;
		bool isFinished() const override;
	private:
		sf::Vector2f _moveRemaining;
};

#endif
