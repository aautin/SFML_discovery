#ifndef ANIMATION_HPP
# define ANIMATION_HPP

# include <SFML/Graphics.hpp>

class Animation
{
	public:
		Animation(size_t frameTime, size_t framesNbs, std::string texturePath, unsigned long startTimestamp);
		~Animation();

		sf::Sprite		getFrame() const;
		void			setFrame();
		
	private:
		sf::Texture	_texture;
		sf::Sprite	_obj;

		unsigned long		_startTimestamp;
		size_t				_frameIndex;
		sf::Vector2u		_frameSize;
		size_t const		_frameTime;
		size_t const		_framesNbs;
};

#endif