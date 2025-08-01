#ifndef ANIMATION_HPP
# define ANIMATION_HPP

# include <SFML/Graphics.hpp>

class Animation
{
	public:
		Animation(size_t frameTime, std::string texturePath);
		~Animation() {}

		sf::Sprite		getFrame();

	private:
		sf::Texture	_texture;

		unsigned long		_startTimestamp;
		size_t				_frameIndex;
		sf::Vector2u		_frameSize;
		size_t const		_frameTime;
		size_t const		_framesNb;
};

#endif