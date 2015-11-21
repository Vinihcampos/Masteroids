#ifndef _ASTEROID_
#define _ASTEROID_

#include "Enemy.h"

class MathVector;
class Universe;
class PhysicalEntity;

class Asteroid : public Enemy {
	public:
		Asteroid(const Asteroid &) = delete;
		Asteroid & operator=(const Asteroid &) = delete;

		Asteroid(MathVector & position, Universe & _universe);

		void update(sf::Time deltaTime);
		bool isColliding(const PhysicalEntity &) const;
		void onCollide(const PhysicalEntity &);

};

#endif
