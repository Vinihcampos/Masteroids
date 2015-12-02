#include "Stage.h"
#include "Player.h"
#include "Universe.h"
#include "PhysicalEntity.h"
#include "Asteroid.h"

Stage::Stage(){ 
	//STUB 
}

Stage::Stage(Universe * _universe, int _type, Player * _player) : 
universe {_universe}, type {_type}, player{_player} {}

void Stage::update(){
	switch(type){
		case Stages::EARTH:
			if(universe->getEntities().size() < 2){
				MathVector * newPos = new MathVector {rand() % 200, rand() % 400};
				universe->addEntity(PhysicalEntity::EntityType::Asteroid, new Asteroid(*newPos, *universe, Asteroid::Type::CLASSIC));
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