#ifndef _PENTITY_
#define _PENTITY_

#include "MathVector.h"
#include "GeneralEntity.h"

class Universe;

class PhysicalEntity : public GeneralEntity, public sf::Drawable {

	protected:
		MathVector velocity;
		MathVector position;
		MathVector acceleration;
		double angleVelocity;	
		double angle;
		int radius;
		bool exploded;
		
		Universe & universe;		

		sf::Sprite sprite;

	public:
	
		enum class EntityType : int {
			Player,
			Asteroid,
			Bullet
		};

		PhysicalEntity(Universe &);
		MathVector getPosition() const;
		MathVector getVelocity() const;
		double getRotationRad() const;
		double getRotationDegree() const;
		double getWidth() const;
		double getHeigth() const;
		virtual void update(sf::Time deltaTime) = 0;
		bool isAlive() const;	
	
		virtual bool isColliding(const PhysicalEntity &) const = 0;
		virtual void onCollide(const PhysicalEntity &) = 0;

		virtual bool isClosing(const PhysicalEntity &) const = 0;
		virtual void onClose(PhysicalEntity &) = 0;
		bool isExploded() const;
		void killEntity();
		bool isInsideWindow();

	protected:
		bool alive;
	private:
		friend class Universe;
		virtual void draw(sf::RenderTarget & target, 
				  sf::RenderStates states) const override;
};

#endif

