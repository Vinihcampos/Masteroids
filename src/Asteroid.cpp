#include "Asteroid.h"
#include "MathVector.h"
#include "Universe.h"
#include "BulletShip.h"
#include "PhysicalEntity.h"
#include "CollisionTools.h"
#include "Collectable.h"
#include "Configuration.h"
#include <cmath>
#include <cstdlib>
#include <iostream>

Asteroid::Asteroid(MathVector & _position, Universe & _universe, int _type) : Enemy(_universe) {
	alive = true;
	sprite.setTexture(Configuration::textures.get(Configuration::Textures::ClassicAsteroid));
	// Setting movement direction
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	sprite.setRotation(0.0);
	// Setting position
	position = _position;
	// Setting velocity;
	velocity.horizontal = 1;
	velocity.vertical = 1;
	// Setting angle
	angleVelocity = 1;
	// Setting the type of asteroid
	type = _type;
	radius = 200;
	angle.horizontal = 1;
	angle.vertical = 1;
	switch(type){
		case Type::CLASSIC:
			currentLifePoints = 4;
			maxLifePoints = 4;
			break;
		case Type::EXPLOSIVE:
			currentLifePoints = 6;
			maxLifePoints = 6;
			break;
		case Type::FOLLOWER:
			currentLifePoints = 3;
			maxLifePoints = 3;
			break;
		case Type::INDESTRUCTIBLE:
			currentLifePoints = 500;
			maxLifePoints = 500;
			break;
		default:
			currentLifePoints = 1;
			maxLifePoints = 1;
	}
}

Asteroid::Asteroid(int h, int v, Universe & _universe, int _type, float _velX, float _velY, int _LifePoints) : Enemy(_universe) {
	alive = true;
	sprite.setTexture(Configuration::textures.get(Configuration::Textures::ClassicAsteroid));
	// Setting movement direction
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	sprite.setRotation(0.0);
	// Setting position
	position.horizontal = h;
	position.vertical = v;
	// Setting velocity;
	velocity.horizontal = _velX;
	velocity.vertical = _velY;
	// Setting angle
	angleVelocity = 1;
	// Setting the type of asteroid
	type = _type;
	currentLifePoints = _LifePoints;	
	maxLifePoints = 4;
	radius = 200;
	angle.horizontal = 1;
	angle.vertical = 1;

	std::cout<<"Chegou no final"<<std::endl;
}

void Asteroid::update(sf::Time deltaTime) {
	sprite.rotate(angleVelocity);
	if (isFollowing) {
		double _angle = std::atan2(toFollow->getPosition().vertical - position.vertical,
							   toFollow->getPosition().horizontal - position.horizontal);
		velocity.horizontal = std::cos(_angle) * 1;
		velocity.vertical = std::sin(_angle) * 1;
	}
	// Updating position
	position.horizontal += velocity.horizontal; //* angle.horizontal; //% Configuration::WINDOW_WIDTH;// * seconds;
	position.vertical += velocity.vertical; //* angle.vertical; //% Configuration::WINDOW_HEIGHT;// seconds;
	sprite.setPosition(position.horizontal, position.vertical);
	
	//Lifebar update
	lifeBar.setPosition(position.horizontal, position.vertical + 30);	
	lifeBar.setSize(sf::Vector2f(currentLifePoints*30/3, 3)); // curLife * BAR_SIZE / MAX_LIFE

	if (currentLifePoints <= 0) alive = false;
}

bool Asteroid::isColliding(const PhysicalEntity & other) const {
	if (dynamic_cast<const Enemy*>(&other) == nullptr
	    && dynamic_cast<const Collectable*>(&other) == nullptr) {
		if (CollisionTools::circleCollision(*this, other))
			return true;
	}
	return false;
}

void Asteroid::onCollide(PhysicalEntity & other) {
	bool bullet = false;
	if (dynamic_cast<const BulletShip*>(&other) != nullptr) {
		currentLifePoints -= other.getDamagePoints();
		bullet = true;
	} else if (dynamic_cast<const Player*>(&other) != nullptr) {
		currentLifePoints = 0;
	}

	switch(type){
		case Type::CLASSIC:
			if(currentLifePoints > 1 && bullet){
				universe.addEntity(PhysicalEntity::EntityType::Asteroid, new Asteroid(position.horizontal, position.vertical, universe, type, velocity.horizontal, velocity.vertical * (-1), currentLifePoints - 1));
				universe.addEntity(PhysicalEntity::EntityType::Asteroid, new Asteroid(position.horizontal, position.vertical, universe, type, velocity.horizontal * (-1), velocity.vertical, currentLifePoints - 1));
				alive = false;
				currentLifePoints = 0;
			}			
		break;
		case Type::EXPLOSIVE:
			if(currentLifePoints <= 0){
				exploded = true;
			}
		break;
		case Type::FOLLOWER:
			if(currentLifePoints <= 0){
				alive = false;
				std::cout<<"entrou aqui! pre-atribuição"<<std::endl;
				std::cout<<"Bullet: " <<bullet<<std::endl;
			}
		break;
		case Type::INDESTRUCTIBLE:
			break;
		default:
			alive = false;
	}

	if(bullet && currentLifePoints <= 0){
		std::cout<<"entrou aqui! atribuição"<<std::endl;
		dynamic_cast<const BulletShip*>(&other)->_player->increaseScore(maxLifePoints);
	}
}

bool Asteroid::isClosing(const PhysicalEntity & other) const {
	float dist = std::sqrt(std::pow(position.horizontal - other.getPosition().horizontal, 2) + 
						  	   std::pow(position.vertical - other.getPosition().vertical, 2));	
	if (dynamic_cast<const Asteroid*>(&other) == nullptr || type == Type::EXPLOSIVE) {
		if(dist <= radius)
			return true;	
	}

	return false;
}

void Asteroid::onClose(PhysicalEntity & other) {
	switch(type){
		case Type::FOLLOWER:
			if (dynamic_cast<const Player*>(&other) != nullptr) {
				toFollow = dynamic_cast<const Player*>(&other);
				isFollowing = true;
			}
			break;
		case Type::EXPLOSIVE:
			if(exploded){
				other.killEntity();
			}
			break;
		default:
			return; 
	}
}
