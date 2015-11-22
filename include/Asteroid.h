#ifndef _ASTEROID_
#define _ASTEROID_

#include "Enemy.h"

class MathVector;
class Universe;
class PhysicalEntity;

class Asteroid : public Enemy {
	public:
		enum Type{
			CLASSIC,
			EXPLOSIVE,
			FOLLOWER,
			INDESTRUCTIBLE
		};

		Asteroid(const Asteroid &) = delete;
		Asteroid & operator=(const Asteroid &) = delete;

		Asteroid(MathVector & position, Universe & _universe, int _type);
		Asteroid(MathVector & position, Universe & _universe, int _type, float _velX, float _velY, int _life);

		void update(sf::Time deltaTime);
		bool isColliding(const PhysicalEntity &) const;
		void onCollide(const PhysicalEntity &);

	private:
		int type;
		int life;
};

#endif