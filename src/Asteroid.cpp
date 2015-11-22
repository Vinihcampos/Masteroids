#include "Asteroid.h"
#include "MathVector.h"
#include "Universe.h"
#include "PhysicalEntity.h"
#include "CollisionTools.h"

Asteroid::Asteroid(MathVector & _position, Universe & _universe, int _type) : Enemy(_universe) {
	alive = true;
	sprite.setTexture(Configuration::textures.get(Configuration::Textures::ClassicAsteroid));
	// Setting movement direction
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	sprite.setRotation(0.0);
	// Setting position
	position = _position;
	// Setting velocity;
	velocity.horizontal = .5;
	velocity.vertical = .5;
	// Setting angle
	angleVelocity = 1;
	// Setting the type of asteroid
	type = _type;

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
}

void Asteroid::update(sf::Time deltaTime) {
	sprite.rotate(angleVelocity);

	// Updating position
	position.horizontal = (position.horizontal + velocity.horizontal); //% Configuration::WINDOW_WIDTH;// * seconds;
	position.vertical = (position.vertical + velocity.vertical); //% Configuration::WINDOW_HEIGHT;// seconds;
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
