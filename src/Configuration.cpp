#include "Configuration.h"

ResourceManager<sf::Texture, int> Configuration::textures;
ActionMap<int> Configuration::playerInputs;

void Configuration::initialize() {
	initTextures();
	initPlayerInputs();
}

void Configuration::initTextures() {
	textures.load(Textures::Player, "media/Player/spaceship.png");
}

void Configuration::initPlayerInputs() {
	playerInputs.map(PlayerInputs::Thrust, Action(sf::Keyboard::Up));
	playerInputs.map(PlayerInputs::TurnLeft, Action(sf::Keyboard::Left));
	playerInputs.map(PlayerInputs::TurnRight, Action(sf::Keyboard::Right));
	playerInputs.map(PlayerInputs::StopThrust, Action(sf::Keyboard::Up, Action::Type::Released | Action::Type::RealTime));
}
