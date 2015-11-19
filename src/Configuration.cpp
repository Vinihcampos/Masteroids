#include "Configuration.h"

int Configuration::WINDOW_WIDTH = 800;
int Configuration::WINDOW_HEIGHT = 600;
std::string Configuration::GAME_TITLE = "Masteroids";
int Configuration::GAME_FPS = 60;

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
	playerInputs.map(PlayerInputs::StopTurnLeft, Action(sf::Keyboard::Left, Action::Type::Released | Action::Type::RealTime));
	playerInputs.map(PlayerInputs::TurnRight, Action(sf::Keyboard::Right));
	playerInputs.map(PlayerInputs::StopTurnRight, Action(sf::Keyboard::Right, Action::Type::Released | Action::Type::RealTime));
	playerInputs.map(PlayerInputs::StopThrust, Action(sf::Keyboard::Up, Action::Type::Released | Action::Type::RealTime));
}
