#include "Masteroids.h"

void Masteroids::proccessEvents() {
	sf::Event e;
	while (pollEvent(e)) {
		//switch (e) {
			
		//}
	}
	player.proccessEvents();
}

void Masteroids::update (sf::Time deltaTime) {


}

void Masteroids::render() {
	display();
}
