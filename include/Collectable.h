#ifndef _COLLECT_
#define _COLLECT_

#include "PhysicalEntity.h"

class Universe;

class Collectable : public PhysicalEntity {
	public:
		enum CollectableType {
			DamageUp = 0,			/*!< Increase player's damage */
			PrecisionUp,			/*!< Increase bullet's precision */
			Indestructible,			/*!< Makes players indestructible */
			SlowAsteroid,			/*!< Slow asteroids */
			ByPass				/*!< Player can pass through asteroids */
		};

		Collectable(const Collectable &) = delete;	
		Collectable & operator=(const Collectable &) = delete;
		Collectable(CollectableType, MathVector &, Universe &);
		
		void update(sf::Time deltaTime);
		bool isColliding(const PhysicalEntity &) const;
		void onCollide(const PhysicalEntity &);
		void onClose(const PhysicalEntity &);
		bool isClosing(const PhysicalEntity &) const;
		
		private:
			CollectableType type;
				
};

#endif
