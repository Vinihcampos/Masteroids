#include "Player.h"
#include <cmath>
#include <iostream>

Player::Player() : PhysicalEntity(), ActionTarget(Configuration::playerInputs) {
	angleVelocity = 0.0;
	thrusting = false;
	
	position.vertical = 100;
	position.horizontal = 100;
	
	ship.setTexture(Configuration::textures.get(Configuration::Textures::Player));
	ship.setOrigin(ship.getGlobalBounds().width / 2,
		       ship.getGlobalBounds().height / 2);
	ship.setRotation(0);


	// Thrust
	bind(Configuration::PlayerInputs::Thrust, [this](const sf::Event &) {
		thrusting = true;	
	});
	
	// Turn left	
	bind(Configuration::PlayerInputs::TurnLeft, [this](const sf::Event &) {
		angleVelocity = -1;
	});
	
	// Turn right
	bind(Configuration::PlayerInputs::TurnRight, [this](const sf::Event &) {
		angleVelocity = 1;
	});
	
}

void Player::proccessEvents() {
	thrusting = false;
	angleVelocity = 0.0;
	ActionTarget::proccessEvents();	
}

void Player::update(sf::Time deltaTime) {
	float seconds = deltaTime.asSeconds();
	
	if (thrusting) {
		angle = ship.getRotation() / 180 * M_PI; 
		acceleration.horizontal = std::cos(angle) * .1;
		acceleration.vertical = std::sin(angle) *.1;
	} else {
		acceleration.horizontal = 0;
		acceleration.vertical = 0;
	} 

	// Angle update
	ship.rotate(angleVelocity);

	// Updating velocity
	velocity.horizontal += acceleration.horizontal;
	velocity.vertical += acceleration.vertical;

	// Updating position
	position.horizontal = (position.horizontal + velocity.horizontal); //% Configuration::WINDOW_WIDTH;// * seconds;
	position.vertical = (position.vertical + velocity.vertical); //% Configuration::WINDOW_HEIGHT;// seconds;
	ship.setPosition(position.horizontal, position.vertical);

	// Setting Euclidean Torus
	if (position.horizontal <= ship.getGlobalBounds().width / 2) 
		position.horizontal = Configuration::WINDOW_WIDTH - ship.getGlobalBounds().width / 2; 
	else if (position.horizontal >= Configuration::WINDOW_WIDTH - ship.getGlobalBounds().width / 2) 
		position.horizontal = ship.getGlobalBounds().width / 2; 

	if (position.vertical <= ship.getGlobalBounds().height / 2) 
		position.vertical =  Configuration::WINDOW_HEIGHT - ship.getGlobalBounds().height / 2; 
	else if (position.vertical >= Configuration::WINDOW_HEIGHT - ship.getGlobalBounds().height / 2) 
		position.vertical = ship.getGlobalBounds().height / 2; 
	
	// Decrease velocity
	velocity.horizontal *= .99;
	velocity.vertical *= .99;

}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	target.draw(ship, states);
}
