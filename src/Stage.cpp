#include "Stage.h"
#include "Player.h"
#include "Universe.h"
#include "PhysicalEntity.h"
#include "Asteroid.h"
#include "Alien.h"
#include "CollisionTools.h"
#include <iostream>

Stage::Stage(){ 
	//STUB 
}

Stage::Stage(Universe * _universe, int _type, Player * _player) : 
universe {_universe}, type {_type}, player{_player}{
	createdAliens = 0;
	currentDuration = sf::Time::Zero;
}

void Stage::update(sf::Time deltaTime){
	switch(type){
		case Stages::EARTH:
			if(currentDuration <= sf::Time::Zero){
				MathVector * newPos = new MathVector {rand() % 700 + 100, rand() % 500 + 100};
				while(std::sqrt(std::pow(newPos->horizontal - player->getPosition().horizontal, 2) + 
				      std::pow(newPos->vertical - player->getPosition().vertical, 2)) < 2 * player->getHeigth()){
					newPos = new MathVector {rand() % 700 + 100, rand() % 500 + 100};
				}
				MathVector * auxVel = new MathVector {rand() % 2, rand() % 2};
				MathVector * newVel = new MathVector {1.0 / (rand() % 10) + .5, 1.0 / (rand() % 10) + .5};
				//std::cout<<"X: "<<newVel->horizontal<<", Y: "<<newVel->vertical<<std::endl;
				if((int)auxVel->horizontal % 2 != 0)
					newVel->horizontal *= -1;
				if((int)auxVel->vertical % 2 != 0)
					newVel->vertical *= -1;
				universe->addEntity(PhysicalEntity::EntityType::Asteroid, new Asteroid(*newPos, *universe, Asteroid::Type::CLASSIC, *newVel));
				currentDuration = sf::seconds(0.5);

				if(player->getScore() / 100 > createdAliens){
					newPos = new MathVector {rand() % 700 + 100, rand() % 500 + 100};
					while(std::sqrt(std::pow(newPos->horizontal - player->getPosition().horizontal, 2) + 
					      std::pow(newPos->vertical - player->getPosition().vertical, 2)) < 2 * player->getHeigth()){
						newPos = new MathVector {rand() % 700 + 100, rand() % 500 + 100};
					}
					auxVel = new MathVector {rand() % 2, rand() % 2};
					newVel = new MathVector {1.0 / (rand() % 10) + .5, 1.0 / (rand() % 10) + .5};
					if((int)auxVel->horizontal % 2 != 0)
						newVel->horizontal *= -1;
					if((int)auxVel->vertical % 2 != 0)
						newVel->vertical *= -1;
					universe->addEntity(PhysicalEntity::EntityType::Alien, new Alien(*newPos, *universe, Alien::Type::CLASSIC, *auxVel));
					++createdAliens;
				}

				delete newPos;
				delete auxVel;
				delete newVel;
			}else{
				currentDuration -= deltaTime;
			}				
		break;
		case Stages::MOON:
		break;
		case Stages::MARS:
		break;
		default:
		break;
	}
}


