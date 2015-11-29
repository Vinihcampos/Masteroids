#ifndef _ANIMATED_
#define _ANIMATED_

#include "PhysicalEntity.h"

class AnimatedPhysicalEntity : public PhysicalEntity {
	public:
		AnimatedPhysicalEntity(const AnimatedPhysicalEntity &) = delete;
		AnimatedPhysicalEntity & operator=(const AnimatedPhysicalEntity &) = delete;
		AnimatedPhysicalEntity(sf::Texture & _texture, Universe &, double, double, sf::Time _frameDuration);
		void play();
		void stop();
		void pause();
		bool isPlaying() const;
		bool isPaused() const;
		void setLooping(bool);
		bool isLooping() const;
		void setAnimation(sf::Texture & _texture, double _frameWidth, double _frameHeigth, sf::Time _frameDuration);
		void setFrameDuration(sf::Time frameDuration);
		int countFrames() const;
		virtual void update(sf::Time deltaTime);
	private:
		std::vector<sf::IntRect> framesRects;
		bool on;
		bool paused;
		bool looping;
		double frameWidth;
		double frameHeigth;
		int currentFrame;
		sf::Time currentTime;
		sf::Time frameDuration;

		void draw(sf::RenderTarget & target, sf::RenderStates states) const;
};

#endif
