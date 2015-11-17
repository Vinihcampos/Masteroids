#include "Masteroids.h"
#include "Configuration.h"

int main() {
	
	Configuration::initialize();	

	Masteroids masteroids(800, 600, "Masteroids");
	masteroids.run(60);

	return 0;
}
