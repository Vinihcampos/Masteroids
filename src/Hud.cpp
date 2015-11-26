#include "Hud.h"
#include "Player.h"
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

	score.setFont(font);
	score.setString(std::string("Score: " + std::to_string(player->getScore())));
	score.setPosition(600, 5);
	score.setColor(sf::Color::White);
	score.setCharacterSize(24);
	
}

void Hud::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	target.draw(maxLife, states);
	target.draw(currentLife, states);
	target.draw(score, states);
}

void Hud::update(){ 
	currentLife.setSize(sf::Vector2f(player->getCurrentLifePoints(), 10));
	score.setString(std::string("Score: " + std::to_string(player->getScore())));
}

