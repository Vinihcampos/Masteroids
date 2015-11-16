#ifndef _ENTITY_
#define _ENTITY_

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <string>

class GeneralEntity {
	public:
		virtual void update(int minFramesPerSec);
		
};

#endif
