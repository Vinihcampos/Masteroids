#ifndef _MAST_
#define _MAST_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Masteroids : public GameEntity {
	
	public:
		Masteroids(int width, int height, std::string const & title) : GameEntity(width, height, title) { /* Empty */ }
		
		virtual void onMouseMove(sf::Event::MouseMoveEvent);		
		virtual void onMouseDown(sf::Event::MouseButtonEvent);		
		virtual void onMouseUp(sf::Event::MouseButtonEvent);		
		virtual void onKeyDown(sf::Event::KeyEvent);		
		virtual void onKeyUp(sf::Event::KeyEvent);		
		
		virtual void setup();
		virtual void run(int minFramesPerSec);
		virtual void processEvents();
		virtual void update(int minFramesPerSec);
		virtual void render();
		virtual void teardown();
	
};

#endif
