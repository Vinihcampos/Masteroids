#include "Asteroid.h"
#include "MathVector.h"
#include "Universe.h"
#include "PhysicalEntity.h"
#include "CollisionTools.h"

Asteroid::Asteroid(MathVector & _position, Universe & _universe) : Enemy(_universe) {
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
}

void Asteroid::update(sf::Time deltaTime) {
	sprite.rotate(angleVelocity);
	sprite.move(velocity.horizontal, velocity.vertical);
}

bool Asteroid::isColliding(const PhysicalEntity & other) const {
	if (dynamic_cast<const Asteroid*>(&other) == nullptr) {
		if (CollisionTools::circleCollision(*this, other))
			return true;
	}
	return false;
}

void Asteroid::onCollide(const PhysicalEntity & other) {
	alive = false;
}
