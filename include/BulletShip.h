#ifndef _BSHIP_
#define _BSHIP_

#include "Bullet.h"


class BulletShip : public Bullet {

	public:
		enum Type {
			SIMPLE = 5,
			POWERFULL = 10,
			LASER = 20
		};

		enum SpawnPoint {
			FRONT = 0,
			LEFT,
			RIGHT
		};

		BulletShip(const BulletShip &) = delete;
		BulletShip & operator=(const BulletShip &) = delete;

		BulletShip(Player &, Type, SpawnPoint, Universe &);

		virtual void update(sf::Time deltaTime);
		bool isColliding(const PhysicalEntity &) const;
		void onCollide(const PhysicalEntity &);
		bool isClosing(const PhysicalEntity &) const{ return false;};
		void onClose(PhysicalEntity &){return;};
		void setDamage(int _damage);
	private:
		Type type;
		SpawnPoint spawnPoint;
};

#endif
