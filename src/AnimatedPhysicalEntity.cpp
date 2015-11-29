#include "AnimatedPhysicalEntity.h"

AnimatedPhysicalEntity::AnimatedPhysicalEntity(sf::Texture & _texture, Universe & _universe, double _frameWidth, double _frameHeigth, sf::Time _frameDuration)				:PhysicalEntity {_universe}, frameWidth {_frameWidth}, frameHeigth {_frameHeigth}, frameDuration {_frameDuration} {
	on = false;
	paused = false;
	looping = true;	
	currentFrame = 0;
	currentTime = sf::Time::Zero;
	setAnimation(_texture, _frameWidth, _frameHeigth, _frameDuration);
}

void AnimatedPhysicalEntity::setAnimation(sf::Texture & _texture, double _frameWidth, double _frameHeigth, sf::Time _frameDuration) {
	framesRects.clear();
	sprite.setTexture(_texture);
	frameWidth = _frameWidth;
	frameHeigth = _frameHeigth;
	frameDuration = _frameDuration;
	currentFrame = 0;
	int countX = _texture.getSize().x / _frameWidth;	
	int countY = _texture.getSize().y / _frameHeigth;	
	for (int i = 0; i < countX; ++i) {
		for (int j = 0; j < countY; ++j) {
			framesRects.push_back(sf::IntRect(i * _frameWidth, j * _frameHeigth, _frameWidth, _frameHeigth));	
		}
	}
	sprite.setTextureRect(framesRects[currentFrame]);
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

int AnimatedPhysicalEntity::countFrames() const {
	return framesRects.size();
}

void AnimatedPhysicalEntity::setFrameDuration(sf::Time _frameDuration) {
	frameDuration = _frameDuration;
}

void AnimatedPhysicalEntity::update(sf::Time deltaTime) {	
	if (on and not paused) {
		currentTime += deltaTime;
		if (currentTime >= frameDuration) {
			currentFrame = (currentFrame + 1) % countFrames(); 
			sprite.setTextureRect(framesRects[currentFrame]);
			std::cout << currentFrame << std::endl;
			currentTime = sf::Time::Zero;
		}
	}
}

void AnimatedPhysicalEntity::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	target.draw(sprite, states);
}
