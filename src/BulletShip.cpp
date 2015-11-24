#include "BulletShip.h"
#include "Player.h"
#include "Universe.h"
#include "CollisionTools.h"
#include <cmath>

BulletShip::BulletShip(Player & player, BulletShip::Type _type, BulletShip::SpawnPoint _spawnPoint, Universe & _universe) 
					   : Bullet { player, _universe }, type {_type}, spawnPoint {_spawnPoint} { 
	switch (spawnPoint) {
		case BulletShip::SpawnPoint::FRONT:
			// Setting initial position
			position.horizontal = player.getPosition().horizontal + player.getWidth() * std::cos(player.getRotationRad()) / 2;
			position.vertical = player.getPosition().vertical + player.getWidth() * std::sin(player.getRotationRad()) / 2;
		break;
		case BulletShip::SpawnPoint::LEFT:
			// Setting initial position
			position.horizontal = player.getPosition().horizontal + player.getWidth() * std::cos(player.getRotationRad()) / 2;
			position.vertical = player.getPosition().vertical + player.getWidth() * std::sin(player.getRotationRad()) / 2;
		break;
		case BulletShip::SpawnPoint::RIGHT:
			// Setting initial position
			position.horizontal = player.getPosition().horizontal + player.getWidth() * std::cos(player.getRotationRad()) / 2;
			position.vertical = player.getPosition().vertical + player.getWidth() * std::sin(player.getRotationRad()) / 2;
		break;
		default: return;
	}

	//switch (type) {

	//}

	// Setting movement direction
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	sprite.setRotation(player.getRotationDegree());
	// Setting velocity
	velocity.horizontal = std::cos(getRotationRad()) * 10;
	velocity.vertical = std::sin(getRotationRad()) * 10;
	// Setting duration
	currentDuration = sf::seconds(0.5);
}

void BulletShip::update(sf::Time deltaTime) {
	currentDuration -= deltaTime;
	if (currentDuration < sf::Time::Zero) {
		alive = false;
	}
	// Updating position
	position.horizontal = (position.horizontal + velocity.horizontal); 
	position.vertical = (position.vertical + velocity.vertical); 
	sprite.setPosition(position.horizontal, position.vertical);
}

bool BulletShip::isColliding(const PhysicalEntity & other) const {
	if (dynamic_cast<const BulletShip*>(&other) == nullptr) {
		if (CollisionTools::circleCollision(*this, other))
			return true;
	}
	return false;
}

void BulletShip::onCollide(const PhysicalEntity & other) {
	alive = false;
}


