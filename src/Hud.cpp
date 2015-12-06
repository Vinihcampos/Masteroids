#include "Hud.h"
#include "Player.h"
#include "Collectable.h"
#include <string>
#include <iostream>

Hud::Hud(){}

Hud::Hud(Player * _player){
	player = _player;

	maxLife.setSize(sf::Vector2f(player->getMaxLifePoints(), 10));
	maxLife.setPosition(10,10);
	maxLife.setFillColor(sf::Color::Red);

	currentLife.setSize(sf::Vector2f(player->getCurrentLifePoints(), 10));
	currentLife.setPosition(10,10);
	currentLife.setFillColor(sf::Color::Green);

	font.loadFromFile("media/Colleged.ttf");

	scorePoints = player->getScore();
	score.setFont(font);
	score.setString(std::string("Score: " + std::to_string(scorePoints)));
	score.setPosition(600, 5);
	score.setColor(sf::Color::White);
	score.setCharacterSize(24);
	
	weaponLevel.setFont(font);
	weaponLevel.setString(std::string(std::to_string(player->getShotLevel())));
	weaponLevel.setPosition(600, 50);
	weaponLevel.setColor(sf::Color::White);
	weaponLevel.setCharacterSize(24);
	
}

void Hud::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	target.draw(maxLife, states);
	target.draw(currentLife, states);
	target.draw(score, states);
	target.draw(weaponLevel, states);
}

void Hud::update(){ 
	currentLife.setSize(sf::Vector2f(player->getCurrentLifePoints(), 10));
	scorePoints = player->getScore();
	score.setString(std::string("Score: " + std::to_string(scorePoints)));
	weaponLevel.setString(std::string(std::to_string(player->getShotLevel())));
	if (player->isAlive()) {
		if ((player->powersToUse).size() > 0) {
			((player->powersToUse).front())->setPosition({740, 5});
		}
		if ((player->powersToUse).size() > 1) {
			((player->powersToUse).back())->setPosition({700, 5});
		}
	}
}

