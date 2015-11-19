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

	protected:
		int bulletLevel;
		sf::Time timeToLive;

};

#endif
