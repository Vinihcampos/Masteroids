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
		
		Universe & universe;		

		sf::Sprite sprite;

	public:
		PhysicalEntity(Universe &);
		MathVector getPosition() const;
		MathVector getVelocity() const;
		double getRotationRad() const;
		double getRotationDegree() const;
		double getWidth() const;
		double getHeight() const;
		virtual void update(sf::Time deltaTime) = 0;
	
	private:
		friend class Universe;
		virtual void draw(sf::RenderTarget & target, 
				  sf::RenderStates states) const override;
};

#endif

