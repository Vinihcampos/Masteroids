#include "PhysicalEntity.h"
#include "Universe.h"

PhysicalEntity::PhysicalEntity(Universe & _universe) : GeneralEntity(), sf::Drawable(), universe (_universe) { /* Empty */ };

MathVector PhysicalEntity::getPosition() const {
	return position;
}

double PhysicalEntity::getRotationRad() const {
	return sprite.getRotation() / 180 * M_PI;
}

double PhysicalEntity::getWidth() const {
	return sprite.getGlobalBounds().width; 
}

double PhysicalEntity::getHeight() const {
	return sprite.getGlobalBounds().height; 
}

void PhysicalEntity::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	target.draw(sprite, states);
}
