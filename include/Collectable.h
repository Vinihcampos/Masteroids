#ifndef _COLLECT_
#define _COLLECT_

#include "AnimatedPhysicalEntity.h"

class Universe;

class Collectable : public AnimatedPhysicalEntity {
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
		Collectable(CollectableType, MathVector &, sf::Texture &, Universe &, double, double, sf::Time);
		
		void update(sf::Time deltaTime);
		bool isColliding(const PhysicalEntity &) const;
		void onCollide(PhysicalEntity &);
		void onClose(PhysicalEntity &);
		bool isClosing(const PhysicalEntity &) const;
		
		private:
			CollectableType type;
				
};

#endif
