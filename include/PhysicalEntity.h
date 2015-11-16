#ifndef _PENTITY_
#define _PENTITY_

#include "MathVector.h"

class PhysicalEntity : public GeneralEntity, sf::Drawable {

	private:
		MathVector velocity;
		MathVector position;
		MathVector acceleration;
		MathVector angleAcceleration;	

	public:
		PhysicalEntity() : GeneralEntity(), sf::Drawable() { /* Empty */ };

	protected:

};

#endif

