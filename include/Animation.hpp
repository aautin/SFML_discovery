#ifndef ANIMATION_HPP
# define ANIMATION_HPP

# include <SFML/Graphics.hpp>

class Animation
{
	public:
		Animation(size_t frameSize, size_t frameTime, size_t framesNbs, const sf::Texture& texture, unsigned long startTimestamp);
		~Animation();

		void			update();
		void			reset(unsigned long startTimestamp = 0);
		sf::Sprite		getFrame() const;

	private:
		void			setFrame();

		unsigned long		_startTimestamp;
		size_t				_frameIndex;
		size_t const		_frameSize;
		size_t const		_frameTime;
		size_t const		_framesNbs;
		sf::Sprite			_obj;
};

#endif