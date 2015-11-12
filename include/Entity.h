#ifndef _ENTITY_
#define _ENTITY_

class GeneralEntity {
	public:
		virtual void onMouseMove(sf::Event::MouseMoveEvent);		
		virtual void onMouseDown(sf::Event::MouseButtonEvent);		
		virtual void onMouseUp(sf::Event::MouseButtonEvent);		
		virtual void onKeyDown(sf::Event::KeyEvent);		
		virtual void onKeyUp(sf::Event::KeyEvent);		
};

#endif
