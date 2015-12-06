#include "Masteroids.h"
#include "Collectable.h"

Masteroids::Masteroids(int width, int height, std::string const & title) : GameEntity(width, height, title) { 
	//universe.getPlayers().push_back(new Player(universe));
	Player * player = new Player(Configuration::textures.get(Configuration::Textures::Player), universe, 128, 128, sf::seconds(0.08));
	universe.addEntity(PhysicalEntity::EntityType::Player, player);
	//MathVector * newPos = new MathVector {rand() % 200, rand() % 400};
	//universe.addEntity(PhysicalEntity::EntityType::Asteroid, new Asteroid(*newPos, universe, Asteroid::Type::CLASSIC));
	//universe.addEntity(PhysicalEntity::EntityType::Collectable, new Collectable(Collectable::CollectableType::DamageUp, *newPos, universe));
	//newPos = new MathVector {rand() % 200 + 100, rand() % 400};
	//universe.addEntity(PhysicalEntity::EntityType::Asteroid, new Asteroid(*newPos, universe, Asteroid::Type::FOLLOWER));
	MathVector * newPos = new MathVector {200,200};
	//universe.addEntity(PhysicalEntity::EntityType::Collectable, new Collectable(Collectable::CollectableType::DamageUp, *newPos, universe));
	//universe.getAsteroids().push_back(new Asteroid(*newPos, universe));

	universe.addEntity(PhysicalEntity::EntityType::Collectable, new Collectable (Collectable::CollectableType::DamageUp, *newPos, Configuration::textures.get(Configuration::Textures::Collectables), universe, 35, 35, sf::seconds(1)));

	//newPos = new MathVector {0,300};
	//universe.addEntity(PhysicalEntity::EntityType::Alien, new Alien(*newPos, universe, Alien::Type::SHOOTER));

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
	universe.proccessEvents();
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
