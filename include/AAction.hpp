#ifndef AACTION_HPP
# define AACTION_HPP

# include <vector>
# include <SFML/Graphics.hpp>

# include "Animation.hpp"

class Character;
class Game;
class AAction
{
	public:
		AAction(size_t frameTime, std::string texturePath);
		~AAction() {}

		void			update(Game& game, Character& actor);
		sf::Sprite		getFrame();
		
		virtual bool	isFinished() const = 0;

	protected:
		Animation					_animation;

		virtual void				execute(Game& game, Character& actor) = 0;
		std::vector<unsigned long>	_executeTimestamps;
};

#endif