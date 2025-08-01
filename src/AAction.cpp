#include "AAction.hpp"
#include "Character.hpp"
#include "Game.hpp"
#include "utils.hpp"

// ------------------- Constructor & Destructor -------------------
AAction::AAction(size_t frameTime, std::string texturePath)
    : _animation(frameTime, texturePath)
{
}


// ------------------- Getters -------------------
sf::Sprite AAction::getFrame()
{
	return _animation.getFrame();
}


// ------------------- Others -------------------
void AAction::update(Game& game, Character& actor)
{
	unsigned long currentTime = getCurrentTimeMillisecond();

	std::vector<unsigned long>::iterator it = _executeTimestamps.begin();
	while (it != _executeTimestamps.end() && *it <= currentTime) {
		execute(game, actor);
		it = _executeTimestamps.erase(it);
		it = _executeTimestamps.begin();
	}
}
