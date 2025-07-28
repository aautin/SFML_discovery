#ifndef AACTION_HPP
# define AACTION_HPP

# include <vector>
# include <SFML/Graphics.hpp>

# include "Animation.hpp"

# define NEVER 0

class Character;
class Game;
class AAction
{
	public:
		AAction(size_t frameTime, size_t framesNbs, std::string texturePath, 
                std::vector<unsigned long> executeTimestamps, unsigned long endTimestamp);
		~AAction();

		void			update(Game& game, Character& actor);
		sf::Sprite		getFrame() const;
		
		virtual bool	isFinished() const = 0;

	protected:
		virtual void	execute(Game& game, Character& actor) = 0;

	private:
		std::vector<unsigned long>	_executeTimestamps;
		unsigned long				_endTimestamp;
		Animation					_animation;
};

#endif