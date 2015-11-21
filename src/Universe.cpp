#include "Universe.h"

Universe::Universe() {};

void Universe::draw(sf::RenderTarget & target, 
				  sf::RenderStates states) const {
	for (auto e : bulletList)
		target.draw(*e, states);
	for (auto e : playersList)
		target.draw(*e, states);
	for (auto e : asteroidList)
		target.draw(*e, states);
}

std::list<Player*> & Universe::getPlayers() {
	return playersList;
}

std::list<Bullet*> & Universe::getBullets() {
	return bulletList;
}

std::list<Asteroid*> & Universe::getAsteroids() {
	return asteroidList;
}

void Universe::proccessEvents() {
	for (auto p : playersList)
		p->proccessEvents();
}

void Universe::update(sf::Time deltaTime) {
	for (auto p : playersList)
		p->update(deltaTime);
	for (auto p : bulletList)
		p->update(deltaTime);
	for (auto p : asteroidList)
		p->update(deltaTime);

	// Collisions
	for (auto i = asteroidList.begin(); i != asteroidList.end(); i++) {
		for (auto j = bulletList.begin(); j != bulletList.end(); j++) {
			//if ((*i)->isAlive() && (*i)->isColliding(**j)) (*i)->onCollide(**j);
			if ((*j)->isAlive() && (*j)->isColliding(**i)) { 
				(*j)->onCollide(**i);
				(*i)->onCollide(**j);
			}	
		}
	}

	for (auto i = bulletList.begin(); i != bulletList.end();) {
		if (not ((*i)->isAlive())) {
			delete *i;
			i = bulletList.erase(i);
		} else i++;
	}
	
	for (auto i = asteroidList.begin(); i != asteroidList.end();) {
		if (not ((*i)->isAlive())) {
			delete *i;
			i = asteroidList.erase(i);
		} else i++;
	}
}

