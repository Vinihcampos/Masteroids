#include "Bullet.h"
#include "Player.h"
#include "Universe.h"

Bullet::Bullet(Player & player, Universe & _universe) : PhysicalEntity(_universe) { 
	//sprite.setTexture(Configuration::textures.get(Configuration::Textures::SimpleBullet));
}

