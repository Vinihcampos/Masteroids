#include "Masteroids.h"

Masteroids::Masteroids(int width, int height, std::string const & title) : GameEntity(width, height, title) { 
	universe.getPlayers().push_back(new Player(universe));
	std::cout << universe.getPlayers().size() << std::endl;
}

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
	universe.proccessEvents();
}

void Masteroids::update (sf::Time deltaTime) {
	universe.update(deltaTime);
}

void Masteroids::render() {
	clear();
	draw(universe);
	display();
}
