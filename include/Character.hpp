#include <SFML/Graphics.hpp>

#define MOVE_SIZE			8
#define STEP_SIZE			32
#define IDLE_FRAME_TIME		128
#define WALKING_FRAME_TIME	64
#define ATTACK_FRAME_TIME	128
#define FRAME_SIZE			32

#define MAP_WIDTH			20
#define MAP_HEIGHT			20

#define COOLDOWN			3000

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
		Character(const sf::Texture& walking, const sf::Texture& idle,
				  const sf::Texture& arrow, const sf::Texture& shoot);
		~Character();

		bool		isOnCooldown();
		void		updateArrow(direction dir);

		bool		isMoving();
		bool		isShooting();
		bool		isIdle();

		void		move();
		void		shoot();
		void		idle();

		void		setMove(direction dir);
		void		setShoot();
		void		setIdle();

		void		updateSprites();

		sf::Sprite	getCurrentSprite();
		sf::Sprite	getArrowSprite();

	private:
		float			_position[2];
		sf::Sprite		_idle;
		sf::Sprite		_arrow;
		
		direction		_move_direction;
		int				_move_length;
		unsigned long	_move_timestamp;
		sf::Sprite		_walking;

		direction		_shoot_direction;
		int				_shoot_length;
		unsigned long	_shoot_timestamp;
		sf::Sprite		_shoot;
	
		unsigned long	_cooldown;

		int				_anim_index;
		sf::Sprite		_current;
};
