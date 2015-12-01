#ifndef _BSHIP_
#define _BSHIP_

#include "Bullet.h"


class BulletShip : public Bullet {

	public:
		enum Type {
			SIMPLE = 2,
			POWERFULL = 5,
			LASER = 10
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
		void onCollide(PhysicalEntity &);
		bool isClosing(const PhysicalEntity &) const{ return false;};
		void onClose(PhysicalEntity &){return;};
		void setDamage(int _damage);
		bool slowAsteroidEffect() const;

		Player * _player;
	private:
		Type type;
		SpawnPoint spawnPoint;
};

#endif
