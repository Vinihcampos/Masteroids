#include "Asteroid.h"
#include "MathVector.h"
#include "Universe.h"
#include "PhysicalEntity.h"
#include "CollisionTools.h"
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
			life = 4;
			break;
		default:
			life = 1;
	}
}

Asteroid::Asteroid(MathVector & _position, Universe & _universe, int _type, float _velX, float _velY, int _life) : Enemy(_universe) {
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
	life = _life;
	radius = 200;
	angle.horizontal = 1;
	angle.vertical = 1;
}

void Asteroid::update(sf::Time deltaTime) {
	sprite.rotate(angleVelocity);
	// Updating velocity
	velocity.horizontal += acceleration.horizontal;
	velocity.vertical += acceleration.vertical;
	// Updating position
	position.horizontal += velocity.horizontal * angle.horizontal; //% Configuration::WINDOW_WIDTH;// * seconds;
	position.vertical += velocity.vertical * angle.vertical; //% Configuration::WINDOW_HEIGHT;// seconds;
	sprite.setPosition(position.horizontal, position.vertical);
}

bool Asteroid::isColliding(const PhysicalEntity & other) const {
	if (dynamic_cast<const Asteroid*>(&other) == nullptr) {
		if (CollisionTools::circleCollision(*this, other))
			return true;
	}
	return false;
}

void Asteroid::onCollide(const PhysicalEntity & other) {
	switch(type){
		case Type::CLASSIC:
			if(life > 1){
				universe.addEntity(PhysicalEntity::EntityType::Asteroid, new Asteroid(position, universe, type, velocity.horizontal, velocity.vertical * (-1), life - 1));
				universe.addEntity(PhysicalEntity::EntityType::Asteroid, new Asteroid(position, universe, type, velocity.horizontal * (-1), velocity.vertical, life - 1));
			}
			life = 0;
			alive = false;
			break;
		default:
			alive = false;
	}
}

bool Asteroid::isClosing(const PhysicalEntity & other) const {
	
	if (dynamic_cast<const Player*>(&other) != nullptr) {
		float dist = std::sqrt(std::pow(position.horizontal - other.getPosition().horizontal, 2) + 
						  	   std::pow(position.vertical - other.getPosition().vertical, 2));
		if(dist <= radius)
			return true;	
	}
	return false;
}

void Asteroid::onClose(const PhysicalEntity & other) {
	double _angle = std::atan2(other.getPosition().vertical - position.vertical,
							   other.getPosition().horizontal - position.horizontal);

	std::cout<<_angle<<"\n";

	switch(type){
		case Type::FOLLOWER:
			//angle.horizontal = std::sin(-1 * _angle);
			//angle.vertical = std::cos(-1 * _angle);
			acceleration.horizontal = std::cos(_angle) * .01;
			acceleration.vertical = std::sin(_angle) *.01;
			break;
		default:
			return; 
	}
}
