#include "BulletShip.h"
#include "Player.h"
#include "Universe.h"
#include <cmath>

BulletShip::BulletShip(Player & player, Universe & _universe) : Bullet { player, _universe } { 
	position.horizontal = player.getPosition().horizontal + player.getWidth() * std::cos(player.getRotationRad()) / 2;
	position.vertical = player.getPosition().vertical + player.getWidth() * std::sin(player.getRotationRad()) / 2;
	sprite.setRotation(player.getRotationDegree());
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	velocity.horizontal = std::cos(getRotationRad()) * 10;
	velocity.vertical = std::sin(getRotationRad()) * 10;
}

void BulletShip::update(sf::Time deltaTime) {
	// Updating position
	position.horizontal = (position.horizontal + velocity.horizontal); //% Configuration::WINDOW_WIDTH;// * seconds;
	position.vertical = (position.vertical + velocity.vertical); //% Configuration::WINDOW_HEIGHT;// seconds;
	sprite.setPosition(position.horizontal, position.vertical);
}
