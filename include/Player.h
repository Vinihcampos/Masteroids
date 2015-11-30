#ifndef _PLAYER_
#define _PLAYER_

#include "ActionTarget.h"
#include "AnimatedPhysicalEntity.h"

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
class BulletShip;
class AnimatedPhysicalEntity;

class Player : public AnimatedPhysicalEntity, public ActionTarget<int> {
	public:
		enum ShotLevel {
			SIMPLE = 0,
			DOUBLE,
			TRIPLE,
			POWERFULL,
			LASER
		};

		Player(const Player &) = delete;
		Player & operator=(const Player &) = delete;

		Player(sf::Texture &, Universe &, double, double, sf::Time);

		virtual void update(sf::Time deltaTime);
		virtual void proccessEvents();
		bool isColliding(const PhysicalEntity &) const;
		void onCollide(PhysicalEntity &);
		bool isClosing(const PhysicalEntity &) const;
		void onClose(PhysicalEntity &);
		void decreaseShotLevel();
		void shot();
		int getScore() const;
		void increaseScore(int points);

		int getBonusDamage() const;
		void setBonusDamage(int);
		int getBonusPrecision() const;
		void setBonusPrecision(int);
		bool isIndestructible() const;
		void setIndestructible(bool);
		bool isSlowingAsteroids() const;
		void setSlowingAsteroids(bool);
		bool isByPassing() const;		
		void setByPassing(bool);

	private:
		bool thrusting;	
		bool hasShot;
		bool isInHyperspace;
		float randX;
		float randY;
		sf::Time timeLastShot;
		int shotLevel;
		int score;
		int bonusDamage;
		int bonusPrecision;
		bool indestructible;
		bool slowingAsteroids;
		bool byPassing;

}; 

#endif
