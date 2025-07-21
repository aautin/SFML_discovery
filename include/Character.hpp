#include <SFML/Graphics.hpp>

#define MOVE_SIZE	5
#define STEP_SIZE	50
#define FRAME_SIZE	32

// typedef enum eDirection {
// 	LEFT,
// 	RIGHT,
// 	UP,
// 	DOWN
// }	direction;

class Character
{
	public:
		Character(const sf::Texture& texture);
		~Character();

		bool		isMoving();
		void		setDirection(float x, float y);
		void		move();
		void		setSprite();
		sf::Sprite	getSprite();

	private:
		float			_position[2];
		float			_direction[2];
		unsigned int	_anim_index;
		sf::Sprite		_sprite;
};
