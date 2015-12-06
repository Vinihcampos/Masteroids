#include "Menu.h"
#include "Configuration.h"
#include <iostream>

Menu::Menu(Universe * _universe, int _type, Player * _player) : ActionTarget(Configuration::playerInputs) {
	type = Menu::Type::INITIAL;
	level = -1;
	universe = _universe;
	player = _player;
	stage = new Stage(_universe, _type, _player);
	hud = new Hud(_player);

	logo.setTexture(Configuration::textures.get(Configuration::Textures::MenuLogo));
	logo.setOrigin(logo.getGlobalBounds().width / 2, logo.getGlobalBounds().height / 2);	
	logo.setPosition(400, 200);

	start.setTexture(Configuration::textures.get(Configuration::Textures::MenuStart));
	start.setOrigin(start.getGlobalBounds().width / 2, start.getGlobalBounds().height / 2);
	start.setPosition(400, 400);

	_exit.setTexture(Configuration::textures.get(Configuration::Textures::MenuExit));
	_exit.setOrigin(_exit.getGlobalBounds().width / 2, _exit.getGlobalBounds().height / 2);
	_exit.setPosition(400, 500);

	bind(Configuration::PlayerInputs::Click, [this](const sf::Event & e) {
		std::cout<<"Entrou no bind!!\n";
		switch(type){
			case Menu::Type::INITIAL:
				if(isInside(e, start)){
					level = Stage::Stages::EARTH;
					stage = new Stage(universe, level, player);
				}else if(isInside(e, _exit)){

				}
			break;
			case Menu::Type::STAGE:
			break;
			case Menu::Type::GAMEOVER:
			break;
			case Menu::Type::PLAYERWINS:
			break;
			default:
			break;
		}
	});
}

void Menu::update(sf::Time deltaTime){
	if(level != -1){
		stage->update(deltaTime);
		hud->update();
	}
}

void Menu::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	if(level != -1){
		stage->draw(target, states);
		hud->draw(target, states);
	}else{
		switch(type){
			case Menu::Type::INITIAL:
				target.draw(logo, states);
				target.draw(start, states);
				target.draw(_exit, states);
			break;
			case Menu::Type::STAGE:
			break;
			case Menu::Type::GAMEOVER:
			break;
			case Menu::Type::PLAYERWINS:
			break;
			default:
			break;
		}
	}
}

bool Menu::isInside(const sf::Event & _mouse, sf::Sprite & sprite){
	std::cout<<"Entrou no inside!!\n";
	if(_mouse.mouseButton.x >= sprite.getPosition().x && _mouse.mouseButton.x <= sprite.getPosition().x + sprite.getTexture()->getSize().x &&
	   _mouse.mouseButton.y >= sprite.getPosition().y && _mouse.mouseButton.y <= sprite.getPosition().y + sprite.getTexture()->getSize().y){
		return true;
	}else{
		return false;
	}
}