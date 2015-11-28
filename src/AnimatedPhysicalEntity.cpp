#include "AnimatedPhysicalEntity.h"

AnimatedPhysicalEntity::AnimatedPhysicalEntity(sf::Texture & _texture, Universe & _universe, double _frameWidth, double _frameHeigth, sf::Time _frameDuration)				:PhysicalEntity {_universe}, frameWidth {_frameWidth}, frameHeigth {_frameHeigth}, frameDuration {_frameDuration} {
	on = false;
	paused = false;
	looping = true;	
	currentFrame = 0;
	sprite.setTexture(_texture);
}



void AnimatedPhysicalEntity::play() {
	on = true;
}

void AnimatedPhysicalEntity::stop() {
	on = false;
}

void AnimatedPhysicalEntity::pause() {
	on = false;
	paused = true;
}

bool AnimatedPhysicalEntity::isPlaying() const {
	return on;
}

bool AnimatedPhysicalEntity::isPaused() const {
	return paused;
}

void AnimatedPhysicalEntity::setLooping(bool _looping) {
	looping = _looping;
}

bool AnimatedPhysicalEntity::isLooping() const {
	return looping;
}

void AnimatedPhysicalEntity::setFrameDuration(sf::Time _frameDuration) {
	frameDuration = _frameDuration;
}

void AnimatedPhysicalEntity::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	sprite.setTextureRect(getRectFromFrame(currentFrame));
	target.draw(sprite, states);
}
