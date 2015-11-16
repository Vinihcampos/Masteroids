#ifndef _GENTITY_
#define _GENTITY_

#include "GeneralEntity.h"

class GameEntity : public GeneralEntity, sf::RenderWindow {

	public:
		GameEntity (int width, int height, std::string const & title) : 
				GeneralEntity(), 
			   	sf::RenderWindow (sf::VideoMode(width, height), title) { /* Empty */ }; 
		
		virtual void setup();
		virtual void run(int minFramesPerSec);
		virtual void proccessEvents();
		virtual void update(sf::Time deltaTime);
		virtual void render();
		virtual void teardown();
};

#endif

