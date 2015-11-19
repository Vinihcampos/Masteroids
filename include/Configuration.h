#ifndef _CONFIG_
#define _CONFIG_

#include "ResourceManager.h"
#include "ActionTarget.h"

class Configuration {

	public:

		static int WINDOW_WIDTH;
		static int WINDOW_HEIGHT;
		static std::string GAME_TITLE;
		static int GAME_FPS;

		Configuration() = delete;
		Configuration(const Configuration &) = delete;
		Configuration & operator=(const Configuration &) = delete;
		
		enum Textures : int {Player};
		static ResourceManager<sf::Texture, int> textures;

		enum PlayerInputs : int { 
			Thrust, 
			TurnLeft, 
			TurnRight, 
			Shoot,
			Hyperspace
		};

		static ActionMap<int> playerInputs;
		static void initialize();

	private:
		static void initTextures();
		static void initPlayerInputs();

};

#endif

