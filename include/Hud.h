#ifndef _HUD_
#define _HUD_

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>

class Player;

class Hud : public sf::Drawable{

	protected:

		Player * player;
		sf::RectangleShape maxLife;
		sf::RectangleShape currentLife;
		int scorePoints;
		sf::Text score;
		sf::Text weaponLevel;
		sf::Font font;

		void draw(sf::RenderTarget & target, 
				  sf::RenderStates states) const override;

	public:

		Hud();
		Hud(Player * _player);
		void update();

};

#endif
