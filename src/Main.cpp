#include "Masteroids.h"

int main() {
	
	Player::setDefaultInputs();

	Masteroids masteroids(800, 600, "Masteroids");
	masteroids.run(60);

	return 0;
}
