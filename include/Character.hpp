#include <SFML/Graphics.hpp>

#define MOVE_SIZE			8
#define STEP_SIZE			32
#define IDLE_FRAME_TIME		128
#define WALKING_FRAME_TIME	64
#define FRAME_SIZE			32

#define MAP_WIDTH			20
#define MAP_HEIGHT			20

typedef enum eDirection {
	LEFT_MOVE = static_cast<int>(sf::Keyboard::Key::A),
	RIGHT_MOVE = static_cast<int>(sf::Keyboard::Key::D),
	UP_MOVE = static_cast<int>(sf::Keyboard::Key::W),
	DOWN_MOVE = static_cast<int>(sf::Keyboard::Key::S),
	LEFT_ARROW = static_cast<int>(sf::Keyboard::Key::Left),
	RIGHT_ARROW = static_cast<int>(sf::Keyboard::Key::Right),
	UP_ARROW = static_cast<int>(sf::Keyboard::Key::Up),
	DOWN_ARROW = static_cast<int>(sf::Keyboard::Key::Down)
}	direction;

class Character
{
	public:
		Character(const sf::Texture& walking, const sf::Texture& idle, const sf::Texture& arrow);
		~Character();

		unsigned long	getCurrentTimeMillisecond();

		bool		isMoving();
		void		move();
		void		idle();

		void		setMove(direction dir);
		void		setArrow(direction dir);
		void		setCurrentSprite();
		void		setArrowSprite();
		
		sf::Sprite	getCurrentSprite();
		sf::Sprite	getArrowSprite();

	private:
		float			_position[2];

		direction		_arrow_direction;
		direction		_move_direction;
		float			_move_distance;
		unsigned long	_move_timestamp;

		int				_anim_index;

		sf::Sprite		_arrow;

		sf::Sprite		_walking;
		sf::Sprite		_idle;
		sf::Sprite		_current;
};
