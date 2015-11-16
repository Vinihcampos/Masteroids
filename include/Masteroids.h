#ifndef _MAST_
#define _MAST_

#include "GameEntity.h"
#include "Player.h"

class Masteroids : public GameEntity {
	
	public:
		Masteroids(int width, int height, std::string const & title) : GameEntity(width, height, title) { /* Empty */ }
		
		virtual void proccessEvents();
		virtual void update(sf::Time deltaTime);
		virtual void render(); 
	
	public:
		Player spaceship;
};

#endif
