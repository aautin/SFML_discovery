#include "Animation.hpp"
#include "utils.hpp"

// ------------------- Constructor & Destructor -------------------
Animation::Animation(size_t frameTime, size_t framesNbs,
					 std::string texturePath, unsigned long startTimestamp)
	: _texture(loadTexture(texturePath)),
	  _obj(_texture),
	  _startTimestamp(startTimestamp),
	  _frameIndex(0),
	  _frameTime(frameTime),
	  _framesNbs(framesNbs)
{
	_frameSize = sf::Vector2u(_texture.getSize().x / _framesNbs, _texture.getSize().y);
	_obj.setOrigin(sf::Vector2f(_frameSize.x / 4.0f, _frameSize.y / 4.0f));
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
		sf::IntRect(sf::Vector2i(_frameIndex * _frameSize.x, 0),
		sf::Vector2i(_frameSize.x, _frameSize.y))
	);
}
