#include "Masteroids.h"
#include "Collectable.h"

Masteroids::Masteroids(int width, int height, std::string const & title) : GameEntity(width, height, title) { 
	//universe.getPlayers().push_back(new Player(universe));
	universe.addEntity(PhysicalEntity::EntityType::Player, new Player(universe));
	MathVector * newPos = new MathVector {rand() % 200, rand() % 400};
<<<<<<< HEAD
	universe.addEntity(PhysicalEntity::EntityType::Asteroid, new Asteroid(*newPos, universe, Asteroid::Type::INDESTRUCTIBLE));
	newPos = new MathVector {rand() % 200 + 100, rand() % 400};
	universe.addEntity(PhysicalEntity::EntityType::Asteroid, new Asteroid(*newPos, universe, Asteroid::Type::INDESTRUCTIBLE));
=======
	//universe.addEntity(PhysicalEntity::EntityType::Asteroid, new Asteroid(*newPos, universe, Asteroid::Type::FOLLOWER));
	//newPos = new MathVector {rand() % 200 + 100, rand() % 400};
	//universe.addEntity(PhysicalEntity::EntityType::Asteroid, new Asteroid(*newPos, universe, Asteroid::Type::FOLLOWER));
	//newPos = new MathVector {rand() % 200 + 100, rand() % 400};
	//universe.addEntity(PhysicalEntity::EntityType::Asteroid, new Asteroid(*newPos, universe, Asteroid::Type::FOLLOWER));
	//newPos = new MathVector {rand() % 200 + 100, rand() % 400};
	//universe.addEntity(PhysicalEntity::EntityType::Asteroid, new Asteroid(*newPos, universe, Asteroid::Type::FOLLOWER));
>>>>>>> 12c2345365d859055c9a80aa5b201ec110509888
	newPos = new MathVector {rand() % 200 + 100, rand() % 400};
	universe.addEntity(PhysicalEntity::EntityType::Asteroid, new Asteroid(*newPos, universe, Asteroid::Type::INDESTRUCTIBLE));
	newPos = new MathVector {rand() % 200 + 100, rand() % 400};
<<<<<<< HEAD
	universe.addEntity(PhysicalEntity::EntityType::Asteroid, new Asteroid(*newPos, universe, Asteroid::Type::INDESTRUCTIBLE));
	newPos = new MathVector {rand() % 200 + 100, rand() % 400};
	universe.addEntity(PhysicalEntity::EntityType::Asteroid, new Asteroid(*newPos, universe, Asteroid::Type::INDESTRUCTIBLE));
=======
	universe.addEntity(PhysicalEntity::EntityType::Collectable, new Collectable(Collectable::CollectableType::DamageUp, *newPos, universe));
>>>>>>> 12c2345365d859055c9a80aa5b201ec110509888
	//universe.getAsteroids().push_back(new Asteroid(*newPos, universe));
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
