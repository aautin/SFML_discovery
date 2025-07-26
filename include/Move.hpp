#ifndef MOVE_HPP
# define MOVE_HPP

# include "AAction.hpp"
# include "Character.hpp"
# include "Game.hpp"

class MoveLeft : public AAction
{
	public:
		MoveLeft(sf::Vector2u tileSize);
		~MoveLeft();
	
		void execute(Game& game, Character& character) override;
};

class MoveRight : public AAction
{
	public:
		MoveRight(sf::Vector2u tileSize);
		~MoveRight();

		void execute(Game& game, Character& character) override;
};

class MoveUp : public AAction
{
	public:
		MoveUp(sf::Vector2u tileSize);
		~MoveUp();

		void execute(Game& game, Character& character) override;
};

class MoveDown : public AAction
{
	public:
		MoveDown(sf::Vector2u tileSize);
		~MoveDown();

		void execute(Game& game, Character& character) override;
};

#endif
