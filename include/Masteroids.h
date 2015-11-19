#ifndef _MAST_
#define _MAST_

#include <list>
#include "GameEntity.h"

#include "Universe.h"

class Masteroids : public GameEntity {
	
	public:
		Masteroids(int width, int height, std::string const & title);
		
		virtual void proccessEvents();
		virtual void update(sf::Time deltaTime);
		virtual void render(); 
		virtual void run(int minFramesPerSec); 
	
	private:
		Universe universe;
};

#endif
