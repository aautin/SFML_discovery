#include "AAction.hpp"
#include "utils.hpp"

// ------------------- Constructor & Destructor -------------------
AAction::AAction(Animation animation, std::vector<unsigned long> actionTimestamps, unsigned long endTimestamp)
	: _animation(animation), _actionTimestamps(actionTimestamps), _lastUpdateTimestamp(0), _endTimestamp(endTimestamp) {}

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

	std::vector<unsigned long>::iterator it = _actionTimestamps.begin();
	while (it != _actionTimestamps.end() && *it <= currentTime) {
		execute(game, actor);
		it = _actionTimestamps.erase(it);
		it = _actionTimestamps.begin();
	}

	_lastUpdateTimestamp = currentTime;
	_animation.setFrame();
}

bool AAction::isFinished() const
{
	return _endTimestamp <= getCurrentTimeMillisecond();
}

