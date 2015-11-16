#include "Player.h"

ActionMap<int> Player::_playerInputs;

Player::Player() : PhysicalEntity(), ActionTarget(_playerInputs) {
	// Set initial states if necessary

	// Thrust
	bind(PlayerInputs::Up, [this](const sf::Events &) {
		
	});
	
	// Turn left	
	bind(PlayerInputs::Left, [this](const sf::Events &) {

	});
	
	// Turn right
	bind(PlayerInputs::Right, [this](const sf::Events &) {

	});
}

void Player::setDefaultInputs() {
	_playerInputs.map(PlayerInputs::Up, Action(sf::Keyboard::Up));
	_playerInputs.map(PlayerInputs::Left, Action(sf::Keyboard::Left));
	_playerInputs.map(PlayerInputs::Right, Action(sf::Keyboard::Right));
}

Player::proccessEvents() {
	// set initial variable states
	//ActionTarget<T>::proccessEvents();	
}

Player::update(sf::Time deltaTime) {
	
}
