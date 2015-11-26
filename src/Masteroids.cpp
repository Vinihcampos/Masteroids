#include "Masteroids.h"
#include "Collectable.h"

Masteroids::Masteroids(int width, int height, std::string const & title) : GameEntity(width, height, title) { 
	//universe.getPlayers().push_back(new Player(universe));
	Player * player = new Player(universe);
	universe.addEntity(PhysicalEntity::EntityType::Player, player);
	MathVector * newPos = new MathVector {rand() % 200, rand() % 400};
	universe.addEntity(PhysicalEntity::EntityType::Asteroid, new Asteroid(*newPos, universe, Asteroid::Type::CLASSIC));
	//newPos = new MathVector {rand() % 200 + 100, rand() % 400};
	//universe.addEntity(PhysicalEntity::EntityType::Asteroid, new Asteroid(*newPos, universe, Asteroid::Type::FOLLOWER));
	newPos = new MathVector {200,200};
	universe.addEntity(PhysicalEntity::EntityType::Collectable, new Collectable(Collectable::CollectableType::DamageUp, *newPos, universe));
	//universe.getAsteroids().push_back(new Asteroid(*newPos, universe));

	hud = new Hud(player);
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
		//switch (e) {
			
		//}
	}
	universe.proccessEvents();
}

void Masteroids::update (sf::Time deltaTime) {
	universe.update(deltaTime);
	hud->update();
}

void Masteroids::render() {
	clear();
	draw(universe);
	draw(*hud);
	display();
}
