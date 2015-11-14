#ifndef _GENTITY_
#define _GENTITY_

class GameEntity : public GeneralEntity, sf::RenderWindow {

	public:
		GameEntity (int width, int height, std::string const & title) : 
				GameEntity(), 
			   	sf::RenderWindow (width, height, title) { /* Empty */ }; 
		
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

