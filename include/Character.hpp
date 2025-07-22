#include <SFML/Graphics.hpp>

#define MOVE_SIZE			8
#define STEP_SIZE			32
#define IDLE_FRAME_TIME		128
#define WALKING_FRAME_TIME	64
#define FRAME_SIZE			32

typedef enum eDirection {
	LEFT1 = static_cast<int>(sf::Keyboard::Key::A),
	RIGHT1 = static_cast<int>(sf::Keyboard::Key::D),
	UP1 = static_cast<int>(sf::Keyboard::Key::W),
	DOWN1 = static_cast<int>(sf::Keyboard::Key::S),
	LEFT2 = static_cast<int>(sf::Keyboard::Key::Left),
	RIGHT2 = static_cast<int>(sf::Keyboard::Key::Right),
	UP2 = static_cast<int>(sf::Keyboard::Key::Up),
	DOWN2 = static_cast<int>(sf::Keyboard::Key::Down)
}	direction;

class Character
{
	public:
		Character(const sf::Texture& walking, const sf::Texture& idle);
		~Character();

		unsigned long	getCurrentTimeMillisecond();

		bool		isMoving();
		void		setDirection(direction dir);
		void		move();
		void		idle();
		void		setSprite();
		sf::Sprite	getSprite();

	private:
		float			_position[2];

		direction		_move_direction;
		float			_move_distance;
		unsigned long	_move_timestamp;

		int				_anim_index;
		bool			_flip;

		sf::Sprite		_walking;
		sf::Sprite		_idle;
		sf::Sprite		_current;
};
