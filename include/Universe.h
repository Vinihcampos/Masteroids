#ifndef _UNIVERSE_
#define _UNIVERSE_

#include "Player.h"
#include "Bullet.h"
#include "PhysicalEntity.h"

class Universe : public sf::Drawable {
	
	public:
		Universe(const Universe &) = delete;
		Universe & operator=(const Universe &) = delete;
	
		Universe();

		void proccessEvents();
		void update(sf::Time deltaTime);
		std::list<Player*> & getPlayers();
		std::list<Bullet*> & getBullets();

	private:
		virtual void draw(sf::RenderTarget & target, 
				  sf::RenderStates states) const override;
		
		std::list<Bullet*> bulletList;	
		std::list<Player*> playersList;	
};

#endif
