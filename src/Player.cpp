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
	ship.setPosition(100.0,100.0);
	angle = ship.getRotation();

	// Thrust
	bind(Configuration::PlayerInputs::Thrust, [this](const sf::Event &) {
		thrusting = true;	
	});
	
	// Turn left	
	bind(Configuration::PlayerInputs::TurnLeft, [this](const sf::Event &) {
		angleVelocity = .05;
	});
	
	// Turn right
	bind(Configuration::PlayerInputs::TurnRight, [this](const sf::Event &) {
		angleVelocity = -.05;
	});
	
}

void Player::proccessEvents() {
	thrusting = false;
	angleVelocity = 0.0;
	ActionTarget::proccessEvents();	
}

void Player::update(sf::Time deltaTime) {
	float seconds = deltaTime.asSeconds();

	// Angle update
	std::cout << "Angle: " << angle << std::endl;
	angle += angleVelocity;
	
	if (thrusting) {
		angle = ship.getRotation() / 180 * M_PI - M_PI / 2; 
		acceleration.horizontal = std::cos(angle) * .1;
		acceleration.vertical = std::sin(angle) *.1;
	} else {
		acceleration.horizontal = 0;
		acceleration.vertical = 0;
	} 

	// Updating velocity
	velocity.horizontal += acceleration.horizontal;
	velocity.vertical += acceleration.vertical;

	// Updating position
	position.horizontal += velocity.horizontal;// * seconds;
	position.vertical += velocity.vertical;// seconds;

	// Decrease velocity
	velocity.horizontal *= .99;
	velocity.vertical *= .99;

	// Apply changes every loop
	ship.rotate(2 * M_PI -  angle * M_PI / 180);
	ship.setPosition(position.horizontal, position.vertical);
//	ship.move(velocity.horizontal * seconds, velocity.vertical * seconds);	
}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	target.draw(ship, states);
}
