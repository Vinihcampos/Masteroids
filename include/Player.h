#ifndef _PLAYER_
#define _PLAYER_

#include "ActionTarget.h"
#include "PhysicalEntity.h"

/*! \brief Represents the player of the game.
 *  \details As it reacts to actions, extends from
 *  ActionTarget.
 *  \authors Vitor Greati, Vinicius Campos
 *  \date 16/11/2015
 *  \version 1.0
 */
template<typename T>
class ActionTarget;

class Universe;

class Player : public PhysicalEntity, public ActionTarget<int> {
	public:
		Player(const Player &) = delete;
		Player & operator=(const Player &) = delete;

		Player(Universe &);

		virtual void update(sf::Time deltaTime);
		virtual void proccessEvents();
		
	private:
		bool thrusting;	
		
}; 

#endif
