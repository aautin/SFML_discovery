#ifndef IDLE_HPP
# define IDLE_HPP

# include <SFML/Graphics.hpp>

# include "utils.hpp"
# include "AAction.hpp"

class Game;
class Character;
class Idle : public AAction
{
	public:
		Idle(sf::Vector2f tileSize);
		~Idle();

		void execute(Game& game, Character& actor) override;
		bool isFinished() const override;
};

#endif
