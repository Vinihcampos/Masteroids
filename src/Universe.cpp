#include "Universe.h"

Universe::Universe() {};

void Universe::draw(sf::RenderTarget & target, 
				  sf::RenderStates states) const {
	for (auto e : bulletList)
		target.draw(*e, states);
	for (auto e : playersList)
		target.draw(*e, states);
}


std::list<Player*> & Universe::getPlayers() {
	return playersList;
}

std::list<Bullet*> & Universe::getBullets() {
	return bulletList;
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
}

