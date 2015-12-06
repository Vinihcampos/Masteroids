#ifndef _MENU_
#define _MENU_

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "ActionTarget.h"
#include "Universe.h"
#include "Hud.h"
#include "Stage.h"

template<typename T>
class ActionTarget;

class Stage;

class Menu : public sf::Drawable, public ActionTarget<int>{

	public:
		enum Type{
			INITIAL,
			STAGE,
			GAMEOVER,
			PLAYERWINS
		};

		Menu(Universe * _universe, int _type, Player * _player);
		bool isInside(const sf::Event & _mouse, sf::Sprite & sprite);
		void update(sf::Time deltaTime);

	protected:

		sf::Sprite logo;
		sf::Sprite start;
		sf::Sprite _exit;
		sf::Sprite gameover;
		sf::Sprite playerwins;

		Universe * universe;
		Player * player;

		int type;
		int level;
		Stage * stage;
		Hud * hud;	
		void draw(sf::RenderTarget & target, 
				  sf::RenderStates states) const override;
};

#endif