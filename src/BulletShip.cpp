#include "BulletShip.h"
#include "Player.h"
#include "Universe.h"
#include <cmath>

BulletShip::BulletShip(Player & player, Universe & _universe) : Bullet { player, _universe } { 
	position.horizontal = player.getPosition().horizontal + player.getWidth() * std::cos(player.getRotationRad()) / 2;
	position.vertical = player.getPosition().vertical + player.getWidth() * std::sin(player.getRotationRad()) / 2;
}

void BulletShip::update(sf::Time deltaTime) {

}
