#include "Enemy.h"
#include "PhysicalEntity.h"

void Enemy::onDestroy() {
	alive = false;
	// raise score
}

int Enemy::getPoints() const {
	return points;
}

void Enemy::setPoints(int _points) {
	points = _points;
}
