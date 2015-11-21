#include "PhysicalEntity.h"
#include "Universe.h"

PhysicalEntity::PhysicalEntity(Universe & _universe) : GeneralEntity(), sf::Drawable(), universe (_universe) { 
	alive = true;
};

MathVector PhysicalEntity::getPosition() const {
	return position;
}

MathVector PhysicalEntity::getVelocity() const {
	return velocity;
}

double PhysicalEntity::getRotationRad() const {
	return sprite.getRotation() / 180 * M_PI;
}

double PhysicalEntity::getRotationDegree() const {
	return sprite.getRotation();
}

double PhysicalEntity::getWidth() const {
	return sprite.getTextureRect().width * sprite.getScale().x; 
}

double PhysicalEntity::getHeigth() const {
	return sprite.getTextureRect().height * sprite.getScale().y; 
}

bool PhysicalEntity::isAlive() const {
	return alive;
}

void PhysicalEntity::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	target.draw(sprite, states);
}
