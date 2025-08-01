#include "Animation.hpp"
#include "utils.hpp"

// ------------------- Constructor & Destructor -------------------
Animation::Animation(size_t frameTime, std::string texturePath)
	: _texture(loadTexture(texturePath)),
	  _startTimestamp(getCurrentTimeMillisecond()),
	  _frameIndex(0),
	  _frameTime(frameTime),
	  _frameSize(getFramesSize(_texture.getSize())),
	  _framesNb(getFramesNb(_texture.getSize()))
{}


// ------------------- Frame -------------------
sf::Sprite Animation::getFrame()
{
	unsigned long timeSinceStart = getCurrentTimeMillisecond() - _startTimestamp;
	_frameIndex = (timeSinceStart / _frameTime) % _framesNb;

	sf::Sprite sprite(_texture);
	sprite.setTextureRect(sf::IntRect(
		sf::Vector2i(_frameIndex * _frameSize.x, 0),
		sf::Vector2i(_frameSize.x, _frameSize.y)
	));
	sprite.setOrigin(sf::Vector2f(_frameSize.x / 2.0f, _frameSize.y / 2.0f));
	return sprite;
}
