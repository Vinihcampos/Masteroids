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
			lifePoints = 4;
			break;
		case Type::EXPLOSIVE:
			lifePoints = 6;
			break;
		case Type::FOLLOWER:
			lifePoints = 3;
			break;
		case Type::INDESTRUCTIBLE:
			lifePoints = 500;
			break;
		default:
			lifePoints = 1;
	}
}

Asteroid::Asteroid(MathVector & _position, Universe & _universe, int _type, float _velX, float _velY, int _lifePoints) : Enemy(_universe) {
	alive = true;
	sprite.setTexture(Configuration::textures.get(Configuration::Textures::ClassicAsteroid));
	// Setting movement direction
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	sprite.setRotation(0.0);
	// Setting position
	position = _position;
	// Setting velocity;
	velocity.horizontal = _velX;
	velocity.vertical = _velY;
	// Setting angle
	angleVelocity = 1;
	// Setting the type of asteroid
	type = _type;
	lifePoints = _lifePoints;
	radius = 200;
	angle.horizontal = 1;
	angle.vertical = 1;
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
	lifeBar.setSize(sf::Vector2f(lifePoints*30/3, 3)); // curLife * BAR_SIZE / MAX_LIFE

	if (lifePoints <= 0) alive = false;
}

bool Asteroid::isColliding(const PhysicalEntity & other) const {
	if (dynamic_cast<const Enemy*>(&other) == nullptr
	    && dynamic_cast<const Collectable*>(&other) == nullptr) {
		if (CollisionTools::circleCollision(*this, other))
			return true;
	}
	return false;
}

void Asteroid::onCollide(const PhysicalEntity & other) {
	if (dynamic_cast<const Bullet*>(&other) != nullptr) {
		lifePoints -= other.getDamagePoints();
	} else if (dynamic_cast<const Player*>(&other) != nullptr) {
		lifePoints = 0;
	}

	switch(type){
		case Type::CLASSIC:
			if(lifePoints > 1){
				universe.addEntity(PhysicalEntity::EntityType::Asteroid, new Asteroid(position, universe, type, velocity.horizontal, velocity.vertical * (-1), lifePoints - 1));
				universe.addEntity(PhysicalEntity::EntityType::Asteroid, new Asteroid(position, universe, type, velocity.horizontal * (-1), velocity.vertical, lifePoints - 1));
			}
			break;
		case Type::EXPLOSIVE:
			exploded = true;
			break;
		case Type::INDESTRUCTIBLE:
			return;
		default:
			alive = false;
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
