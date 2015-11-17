#include "Player.h"
#include <iostream>

Player::Player() : PhysicalEntity(), ActionTarget(Configuration::playerInputs) {
	angle = 0.0;
	thrusting = false;
	ship.setTexture(Configuration::textures.get(Configuration::Textures::Player));
	ship.setOrigin(ship.getGlobalBounds().width / 2,
		       ship.getGlobalBounds().height / 2);
	// Thrust
	bind(Configuration::PlayerInputs::Thrust, [this](const sf::Event &) {
		thrusting = true;	
	});
	
	// Stop Thrust
	bind(Configuration::PlayerInputs::StopThrust, [this](const sf::Event &) {
		thrusting = false;	
	});
	
	// Turn left	
	bind(Configuration::PlayerInputs::TurnLeft, [this](const sf::Event &) {
		angle -= angleAcceleration.horizontal;
	});
	
	// Turn right
	bind(Configuration::PlayerInputs::TurnRight, [this](const sf::Event &) {
		angle += angleAcceleration.vertical;
	});
}

void Player::proccessEvents() {
	// set initial variable states
	ActionTarget::proccessEvents();	
}

void Player::update(sf::Time deltaTime) {
	if (thrusting) {
		std::cout << "oiaushiauhsaiuh!" << std::endl;
		acceleration.horizontal += 5;
		acceleration.vertical += 5;
	} else {
		std::cout << "oi!" << std::endl;
		acceleration.horizontal = 0;
		acceleration.vertical = 0;
	} 

	// Updating velocity
	velocity.horizontal += acceleration.horizontal;
	velocity.vertical += acceleration.vertical;

	// Updating position
	position.horizontal += velocity.horizontal;		
	position.vertical += velocity.vertical;		

	ship.setRotation(angle);
	ship.setPosition(position.horizontal, position.vertical);	
}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	target.draw(ship, states);
}
