#ifndef AACTION_HPP
# define AACTION_HPP

# include <vector>
# include <SFML/Graphics.hpp>

# include "Animation.hpp"
# include "Character.hpp"
# include "Game.hpp"

class AAction
{
	public:
		AAction(Animation animation, std::vector<unsigned long> actionTimestamps, unsigned long endTimestamp);
		~AAction();

		sf::Sprite		update(Game& game, Character& actor);
		void			reset();
		sf::Sprite		getFrame() const;
		bool			isFinished() const;

	private:
		virtual void	execute(Game& game, Character& actor) = 0;

		std::vector<unsigned long>	_actionTimestamps;
		unsigned long				_lastUpdateTimestamp;
		unsigned long				_endTimestamp;
		Animation					_animation;
};

#endif