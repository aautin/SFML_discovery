#include "Move.hpp"

// ------------------- MoveLeft -------------------
MoveLeft::MoveLeft(sf::Vector2u tileSize) : AAction()
{}

MoveLeft::~MoveLeft() {}

void MoveLeft::execute(Game& game, Character& character)
{
	// Implement the logic for moving the character left
	character.setPosition(character.getPosition().x, character.getPosition().y);
}

// ------------------- MoveRight -------------------
MoveRight::MoveRight(sf::Vector2u tileSize) : AAction()
{}

MoveRight::~MoveRight() {}

void MoveLeft::execute(Game& game, Character& character)
{
	// Implement the logic for moving the character right
}

// ------------------- MoveUp -------------------
MoveUp::MoveUp(sf::Vector2u tileSize) : AAction()
{}

MoveUp::~MoveUp() {}

void MoveUp::execute(Game& game, Character& character)
{
	// Implement the logic for moving the character up
}

// ------------------- MoveDown -------------------
MoveDown::MoveDown(sf::Vector2u tileSize) : AAction()
{}

MoveDown::~MoveDown() {}

void MoveDown::execute(Game& game, Character& character)
{
	// Implement the logic for moving the character down
}
