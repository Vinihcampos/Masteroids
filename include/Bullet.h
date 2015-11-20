#ifndef _BULLET_
#define _BULLET_

#include "PhysicalEntity.h"

class Player;
class Universe;

class Bullet : public PhysicalEntity {
	public:
		Bullet(const Bullet &) = delete;
		Bullet & operator=(const Bullet &) = delete;

		Bullet(Player &, Universe &);
		virtual void update(sf::Time deltaTime) = 0;	

	protected:
		int bulletLevel;
		sf::Time timeToLive;

};

#endif
