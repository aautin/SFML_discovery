#include "Animation.hpp"
#include "utils.hpp"

// ------------------- Constructor & Destructor -------------------
Animation::Animation(size_t frameTime, size_t framesNbs,
					 std::string texturePath, unsigned long startTimestamp, sf::Vector2f tileSize)
	: _texture(loadTexture(texturePath)),
	  _obj(_texture),
	  _startTimestamp(startTimestamp),
	  _frameIndex(0),
	  _frameTime(frameTime),
	  _framesNbs(framesNbs)
{
	_frameSize = sf::Vector2f(_texture.getSize().x / _framesNbs, _texture.getSize().y);
	scale(_obj, _texture, tileSize);
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
	if (this->_frameTime == INFINITE)
		return;

	unsigned long timeSinceStart = getCurrentTimeMillisecond() - _startTimestamp;
	_frameIndex = (timeSinceStart / _frameTime) % _framesNbs;
	_obj.setTextureRect(
		sf::IntRect(sf::Vector2i(_frameIndex * _frameSize.x, 0),
		sf::Vector2i(_frameSize.x, _frameSize.y))
	);
}

void Animation::setDirection(sf::Angle angle, sf::Vector2f offset)
{
	_obj.setScale(sf::Vector2f(0.5f, 0.5f));
	offset += sf::Vector2f(_frameSize.x / 4.0f, _frameSize.y / 4.0f);

	_obj.setOrigin(sf::Vector2f(_frameSize.x / 2.0f, _frameSize.y / 2.0f));
	_obj.setRotation(angle);
	_obj.setPosition(offset);
}
