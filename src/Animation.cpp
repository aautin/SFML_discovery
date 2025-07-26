#include "Animation.hpp"
#include "utils.hpp"

// ------------------- Constructor & Destructor -------------------
Animation::Animation(size_t frameSize, size_t frameTime, size_t framesNbs,
					 const sf::Texture& texture, unsigned long startTimestamp)
	: _frameIndex(0), _frameSize(frameSize), _frameTime(frameTime),
	_framesNbs(framesNbs), _obj(texture), _startTimestamp(startTimestamp)
{
	setFrame();
}

Animation::~Animation() {}


// ------------------- Frame -------------------
sf::Sprite Animation::getFrame() const
{
	return _obj;
}

void Animation::setFrame()
{
	unsigned long timeSinceStart = getCurrentTimeMillisecond() - _startTimestamp;
	_frameIndex = (timeSinceStart / _frameTime) % _framesNbs;
	_obj.setTextureRect(
		sf::IntRect(sf::Vector2i(_frameIndex * _frameSize, 0),
		sf::Vector2i(_frameSize, _frameSize))
	);
	_obj.setOrigin(sf::Vector2f(_frameSize / 2.0f, _frameSize / 2.0f));
}
