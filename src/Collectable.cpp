#include "Collectable.h"
#include "Universe.h"
#include "CollisionTools.h"
#include "MathVector.h"

Collectable::Collectable(Collectable::CollectableType _type, MathVector & initialPos, sf::Texture & _texture, Universe & _universe, double _frameW, double _frameH, sf::Time _frameDuration) : AnimatedPhysicalEntity(_texture, _universe, _frameW, _frameH, _frameDuration), type {_type} {
	position = initialPos;
	setCurrentFrame(_type);	
}

void Collectable::update(sf::Time deltaTime) {
	sprite.setPosition(position.horizontal, position.vertical);
}

bool Collectable::isColliding(const PhysicalEntity & other) const {
	if (dynamic_cast<const Player*>(&other) != nullptr) {
		std::cout << "colidindo" << std::endl;
		if (CollisionTools::circleCollision(*this, other)) {
			return true;
		}
	}
	return false;
}

void Collectable::onCollide(PhysicalEntity & other) {
	if (dynamic_cast<const Player*>(&other) != nullptr) { 
		Player * p = dynamic_cast<Player*>(&other); 
		switch(type) {
			case CollectableType::DamageUp:
				p->setBonusDamage(10);	
			break;
			case CollectableType::PrecisionUp:
				p->setBonusPrecision(10);
			break;
			case CollectableType::Indestructible:
				p->setIndestructible(true);
			break;
			case CollectableType::SlowAsteroid:
				p->setSlowingAsteroids(true);
			break;
			case CollectableType::ByPass:
				p->setByPassing(true);
			break;
		}
		alive = false;
	}
}

bool Collectable::isClosing(const PhysicalEntity & other) const { 
	return false;  
}

void Collectable::onClose(PhysicalEntity & other) {
	return;
}
