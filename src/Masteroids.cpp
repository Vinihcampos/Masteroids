#include "Masteroids.h"

void Masteroids::run(int minFramesPerSec) {
	sf::Clock clock;
	sf::Time timeSinceLastUpdate;
	sf::Time timePerFrame = sf::seconds(1.f / minFramesPerSec);
	while (isOpen()) {
		proccessEvents();
		timeSinceLastUpdate = clock.restart();
		
		while (timeSinceLastUpdate > timePerFrame) {
			timeSinceLastUpdate -= timePerFrame;
			update(timePerFrame);
		}	
		
		update(timeSinceLastUpdate);
		render();
	}
}

void Masteroids::proccessEvents() {
	sf::Event e;
	while (pollEvent(e)) {
		//switch (e) {
			
		//}
	}
	player.proccessEvents();
}

void Masteroids::update (sf::Time deltaTime) {
	player.update(deltaTime);

}

void Masteroids::render() {
	clear();
	draw(player);
	display();
}
