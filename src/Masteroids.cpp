#include "Masteroids.h"
#include "Collectable.h"

Masteroids::Masteroids(int width, int height, std::string const & title) : GameEntity(width, height, title) { 
	Player * player = new Player(Configuration::textures.get(Configuration::Textures::Player), universe, 128, 128, sf::seconds(0.08));
	universe.addEntity(PhysicalEntity::EntityType::Player, player);
	hud = new Hud(player);
	stage = new Stage(&universe, Stage::Stages::KEPLER, player);
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
	universe.proccessEvents();
	sf::Event e;
	while (pollEvent(e)) {
		if((e.type == sf::Event::Closed) || ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::Escape))){
			close();
		}
		auto range = universe.getEntities().equal_range(PhysicalEntity::EntityType::Player);
		for (auto ip (range.first); ip != range.second; ip++) {
			((Player*)((*ip)).second)->proccessEvent(e);
		}

		//switch (e) {
			
		//}
	}
}

void Masteroids::update (sf::Time deltaTime) {
	universe.update(deltaTime);
	stage->update(deltaTime);
	hud->update();	
}

void Masteroids::render() {
	clear();
	draw(*stage);
	draw(universe);
	draw(*hud);
	display();
}
