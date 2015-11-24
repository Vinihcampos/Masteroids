#include "Player.h"
#include "Asteroid.h"
#include "BulletShip.h"
#include "Universe.h"
#include "Collectable.h"
#include "CollisionTools.h"
#include <cmath>
#include <iostream>

Player::Player(Universe & _universe) : PhysicalEntity(_universe), ActionTarget(Configuration::playerInputs) {
	angleVelocity = 0.0;
	thrusting = false;
	hasShot = false;
	alive = true;
	isInHyperspace = false;
	radius = 200;
	
	position.vertical = 100;
	position.horizontal = 100;
	
	sprite.setTexture(Configuration::textures.get(Configuration::Textures::Player));
	sprite.setRotation(0);
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	
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
	
	// Shoot
	bind(Configuration::PlayerInputs::Shoot, [this](const sf::Event &) {
		if (timeLastShot > sf::seconds(0.3)) {	
			universe.addEntity(PhysicalEntity::EntityType::Bullet, new BulletShip {*this, universe});	
			timeLastShot = sf::Time::Zero;
		}
	});

	bind(Configuration::PlayerInputs::Hyperspace, [this](const sf::Event &) {
		position.horizontal = rand() % 800;
		position.vertical = rand() % 600;
	});
}

void Player::proccessEvents() {
	thrusting = false;
	angleVelocity = 0.0;
	ActionTarget::proccessEvents();	
}

void Player::update(sf::Time deltaTime) {
	float seconds = deltaTime.asSeconds();
	
	timeLastShot += deltaTime;	

	if (thrusting) {
		angle = sprite.getRotation() / 180 * M_PI; 
		acceleration.horizontal = std::cos(angle) * .1;
		acceleration.vertical = std::sin(angle) *.1;
	} else {
		acceleration.horizontal = 0;
		acceleration.vertical = 0;
	} 

	// Angle update
	sprite.rotate(angleVelocity);

	// Updating velocity
	velocity.horizontal += acceleration.horizontal;
	velocity.vertical += acceleration.vertical;

	// Updating position
	position.horizontal = (position.horizontal + velocity.horizontal); //% Configuration::WINDOW_WIDTH;// * seconds;
	position.vertical = (position.vertical + velocity.vertical); //% Configuration::WINDOW_HEIGHT;// seconds;
	sprite.setPosition(position.horizontal, position.vertical);

	// Setting Euclidean Torus
	if (position.horizontal <= sprite.getGlobalBounds().width / 2) 
		position.horizontal = Configuration::WINDOW_WIDTH - sprite.getGlobalBounds().width / 2; 
	else if (position.horizontal >= Configuration::WINDOW_WIDTH - sprite.getGlobalBounds().width / 2) 
		position.horizontal = sprite.getGlobalBounds().width / 2; 

	if (position.vertical <= sprite.getGlobalBounds().height / 2) 
		position.vertical =  Configuration::WINDOW_HEIGHT - sprite.getGlobalBounds().height / 2; 
	else if (position.vertical >= Configuration::WINDOW_HEIGHT - sprite.getGlobalBounds().height / 2) 
		position.vertical = sprite.getGlobalBounds().height / 2; 
	
	// Decrease velocity
	velocity.horizontal *= .99;
	velocity.vertical *= .99;

}

bool Player::isColliding(const PhysicalEntity & other) const {
	if (dynamic_cast<const Player*>(&other) == nullptr && dynamic_cast<const BulletShip*>(&other) == nullptr) {
		if (CollisionTools::circleCollision(*this, other)) {
			std::cout << "ola" << std::endl;
			return true;
		}
	}
	return false;
}

void Player::onCollide(const PhysicalEntity & other) {
	if (dynamic_cast<const Collectable*>(&other) != nullptr) {
	
	} else alive = false;
}

bool Player::isClosing(const PhysicalEntity & other) const {
	if (dynamic_cast<const Asteroid*>(&other) != nullptr) {
		float dist = std::sqrt(std::pow(position.horizontal - other.getPosition().horizontal, 2) + 
						  	   std::pow(position.vertical - other.getPosition().vertical, 2));
		if(dist <= radius)
			return true;
	}
	return false;
}

void Player::onClose(const PhysicalEntity & other) {
	return;
}
