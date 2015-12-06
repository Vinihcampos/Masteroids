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
		
		enum Textures : int {
			Player,
			SimpleBullet,
			ClassicAsteroid,
			ExplosiveAsteroid,
			FollowerAsteroid,
			IndestructibleAsteroid,
			Collectables,
			DamageUp,
			PrecisionUp,
			Indestructible,
			SlowAsteroid,
			ByPass,
			SimpleShot,
			PowerfullShot,
			LaserShot,
			ShooterAlien,
			ClassicAlien,
			SimpleAlienShot,
			ExplosionA,
			ExplosionB,
			ExplosionC,
			Earth,
			Kepler,
			Blue
		};
		
		static ResourceManager<sf::Texture, int> textures;

		enum PlayerInputs : int { 
			Thrust, 
			TurnLeft, 
			TurnRight, 
			Shoot,
			Hyperspace,
			ActivatePowerUp
		};

		static ActionMap<int> playerInputs;
		static void initialize();

	private:
		static void initTextures();
		static void initPlayerInputs();

};

#endif

