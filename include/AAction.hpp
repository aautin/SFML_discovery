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

		void			update(Game& game, Character& actor);
		sf::Sprite		getFrame() const;
		bool			isFinished() const;

	protected:
		virtual void	execute(Game& game, Character& actor) = 0;

	private:
		std::vector<unsigned long>	_actionTimestamps;
		unsigned long				_lastUpdateTimestamp;
		unsigned long				_endTimestamp;
		Animation					_animation;
};

#endif