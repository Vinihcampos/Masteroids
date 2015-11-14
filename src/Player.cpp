#include "Player.h"

Player::Player() : PhysicalEntity(), ActionTarget() {

	// Thrust
	bind(Action(PlayerInputs::Up, [this](const sf::Events &)) {
		
	});
	
	// Turn left	
	bind(Action(PlayerInputs::Left, [this](const sf::Events &) {

	});
	
	// Turn right
	bind(Action(PlayerInputs::Right, [this](const sf::Events &) {

	});
}

void Player::setDefaultInputs() {
	_playerInputs.map(PlayerInputs::Up, Action(sf::Keyboard::Up));
	_playerInputs.map(PlayerInputs::Left, Action(sf::Keyboard::Left));
	_playerInputs.map(PlayerInputs::Right, Action(sf::Keyboard::Right));
}

Player::proccessEvents() {
	// set initial variable states
	ActionTarget::proccessEvents();	
}

Player::update() {
	
}
