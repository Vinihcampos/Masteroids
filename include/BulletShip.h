#ifndef _BSHIP_
#define _BSHIP_

#include "Bullet.h"


class BulletShip : public Bullet {

	public:
		BulletShip(const BulletShip &) = delete;
		BulletShip & operator=(const BulletShip &) = delete;

		BulletShip(Player &, Universe &);

		virtual void update(sf::Time deltaTime);
		bool isColliding(const PhysicalEntity &) const;
		void onCollide(const PhysicalEntity &);
		bool isClosing(const PhysicalEntity &) const{ return false;};
		void onClose(PhysicalEntity &){return;};
};

#endif
