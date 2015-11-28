#ifndef _ANIMATED_
#define _ANIMATED_

#include "PhysicalEntity.h"

class AnimatedPhysicalEntity : public PhysicalEntity {
	public:
		AnimatedPhysicalEntity(const AnimatedPhysicalEntity &) = delete;
		AnimatedPhysicalEntity & operator=(const AnimatedPhysicalEntity &) = delete;
		AnimatedPhysicalEntity(Universe &, double, double, sf::Time _frameDuration);
		void play();
		void stop();
		void pause();
		bool isPlaying() const;
		bool isPaused() const;
		void setLooping(bool);
		bool isLooping() const;
		void setFrameDuration(sf::Time frameDuration);
		virtual void update(sf::Time deltaTime) = 0;
	private:
		std::vector<sf::IntRect> framesRects;
		bool on;
		bool paused;
		bool looping;
		double frameWidth;
		double frameHeigth;
		int currentFrame;
		sf::Time frameDuration;

		void draw(sf::RenderTarget & target, sf::RenderStates states) const;
};

#endif
