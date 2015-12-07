#include "Menu.h"
#include "Configuration.h"
#include <iostream>

Menu::Menu(Universe * _universe, int _type, sf::Texture & _texture, double _frameWidth, double _frameHeigth, sf::Time _frameDuration) : ActionTarget(Configuration::playerInputs) {
	type = Menu::Type::INITIAL;
	level = -1;
	
	universe = _universe;
	texture = _texture;
	frameWidth = _frameWidth;
	frameHeigth = _frameHeigth;
	frameDuration = _frameDuration;

	player = new Player(texture, *universe, frameWidth, frameHeigth, frameDuration);

	logo.setTexture(Configuration::textures.get(Configuration::Textures::MenuLogo));
	logo.setOrigin(logo.getGlobalBounds().width / 2, logo.getGlobalBounds().height / 2);	
	logo.setPosition(400, 200);

	start.setTexture(Configuration::textures.get(Configuration::Textures::MenuStart));
	start.setPosition(250, 400);

	_exit.setTexture(Configuration::textures.get(Configuration::Textures::MenuExit));
	_exit.setPosition(250, 500);

	earth.setTexture(Configuration::textures.get(Configuration::Textures::IconEarth));
	earth.setPosition(224, 152);

	kepler.setTexture(Configuration::textures.get(Configuration::Textures::IconKepler));
	kepler.setPosition(0, 446);

	blue.setTexture(Configuration::textures.get(Configuration::Textures::IconBlue));
	blue.setPosition(436, 0);

	bg.setTexture(Configuration::textures.get(Configuration::Textures::StagesBg));
	bg.setPosition(0, 0);

	bind(Configuration::PlayerInputs::Click, [this](const sf::Event & e) {
		switch(type){
			case Menu::Type::INITIAL:
				if(isInside(e, start)){
					type = Menu::Type::STAGE;
				}
			break;
			case Menu::Type::STAGE:
				if(isInside(e, earth)){
					level = Stage::Stages::EARTH;
					player = new Player(texture, *universe, frameWidth, frameHeigth, frameDuration);
					universe->addEntity(PhysicalEntity::EntityType::Player, player);
					stage = new Stage(universe, level, player);
					hud = new Hud(player);
				}else if(isInside(e, kepler)){
					level = Stage::Stages::KEPLER;
					player = new Player(texture, *universe, frameWidth, frameHeigth, frameDuration);
					universe->addEntity(PhysicalEntity::EntityType::Player, player);
					stage = new Stage(universe, level, player);
					hud = new Hud(player);
				}else if(isInside(e, blue)){
					level = Stage::Stages::BLUE;
					player = new Player(texture, *universe, frameWidth, frameHeigth, frameDuration);
					universe->addEntity(PhysicalEntity::EntityType::Player, player);
					stage = new Stage(universe, level, player);
					hud = new Hud(player);
				}
			break;
			case Menu::Type::GAMEOVER:
				delete stage;
				delete hud;
				universe->clear();
			break;
			case Menu::Type::PLAYERWINS:
				type = Menu::Type::INITIAL;				
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
		switch(level){
			case Stage::Stages::EARTH:
				if(player->getScore() > 500 && stage->getNumberAliens() >= 5){
					level = -1;
					delete stage;
					delete hud;
					universe->clear();
					type = Menu::Type::INITIAL;
				}
			break;
			case Stage::Stages::KEPLER:
				if(player->getScore() > 1000 && stage->getNumberAliens() >= 10){
					level = -1;
					delete stage;
					delete hud;
					universe->clear();
					type = Menu::Type::INITIAL;
				}
			break;
			case Stage::Stages::BLUE:
				if(player->getScore() > 1500 && stage->getNumberAliens() >= 15){
					level = -1;
					delete stage;
					delete hud;
					universe->clear();
					type = Menu::Type::INITIAL;
				}
			break;
			default:
			return;
		}
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
				target.draw(bg, states);
				target.draw(earth, states);
				target.draw(kepler, states);
				target.draw(blue, states);
			break;
			case Menu::Type::GAMEOVER:
			break;
			case Menu::Type::PLAYERWINS:
				target.draw(start, states);
				target.draw(_exit, states);
			break;
			default:
			break;
		}
	}
	
	std::cout<<type<<"\n";
}

bool Menu::isInside(const sf::Event & _mouse, sf::Sprite & sprite){
	if(_mouse.mouseButton.x >= sprite.getPosition().x && _mouse.mouseButton.x <= sprite.getPosition().x + sprite.getTexture()->getSize().x &&
	   _mouse.mouseButton.y >= sprite.getPosition().y && _mouse.mouseButton.y <= sprite.getPosition().y + sprite.getTexture()->getSize().y){
		return true;
	}else{
		return false;
	}
}
