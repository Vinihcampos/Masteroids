#ifndef _PENTITY_
#define _PENTITY_

#include "MathVector.h"
#include "GeneralEntity.h"

class PhysicalEntity : public GeneralEntity, public sf::Drawable {

	protected:
		MathVector velocity;
		MathVector position;
		MathVector acceleration;
		MathVector angleAcceleration;	
		double angle;

	public:
		PhysicalEntity() : GeneralEntity(), sf::Drawable() { /* Empty */ };

	protected:

};

#endif

