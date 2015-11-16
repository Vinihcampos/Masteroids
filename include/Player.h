#ifndef _PLAYER_
#define _PLAYER_

#include "ActionTarget.h"
#include "PhysicalEntity.h"

/*! \brief Represents the player of the game.
 */

template<typename T>
class ActionTarget;

class Player : public PhysicalEntity, public ActionTarget<int> {
	public:
		Player(const Player &) = delete;
		Player & operator=(const Player &) = delete;

		Player();

		virtual void update(sf::Time deltaTime);
		virtual void proccessEvents();
		
		enum PlayerInputs { Up, Left, Right };
		static void setDefaultInputs();
	private:
		virtual void draw(sf::RenderTarget & target, 
				  sf::RenderStates states) const override;
		bool _thrusting;	
		static ActionMap<int> _playerInputs;
}; 

#endif
