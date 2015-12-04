#ifndef _STAGE_
#define _STAGE_

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>

class Universe;
class Player;

class Stage{

	protected:
		sf::Texture background;
		Universe * universe;
		int type;
		int createdAliens;
		Player * player;
		sf::Time currentDuration;

	public:
		enum Stages{
			EARTH,
			MOON,
			MARS
		};

		Stage();
		Stage(Universe * _universe, int _type, Player * _player);
		virtual void update(sf::Time deltaTime);

};

#endif