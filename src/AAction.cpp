#include "AAction.hpp"
#include "utils.hpp"
#include "Game.hpp"
#include "Character.hpp"

// ------------------- Constructor & Destructor -------------------
AAction::AAction(size_t frameTime, size_t framesNbs, std::string texturePath,
                 std::vector<unsigned long> executeTimestamps, unsigned long endTimestamp, sf::Vector2f tileSize)
    : _animation(frameTime, framesNbs, texturePath, getCurrentTimeMillisecond(), tileSize),
      _executeTimestamps(executeTimestamps),
      _endTimestamp(endTimestamp) 
{
}

AAction::~AAction() {}


// ------------------- Getters -------------------
sf::Sprite AAction::getFrame() const
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

	_animation.setFrame();
}
