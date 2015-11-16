#ifndef _ACTION_
#define _ACTION_
#include <string.h>
#include <SFML/Window/Event.hpp>

class Action {
	
	public:
		enum Type {
			RealTime = 1,
			Pressed = 1 << 1,
			Released = 1 << 2
		};
	
		Action(const Action & other);
		
		/*! \brief Copy operator */
		Action & operator=(const Action & other);
	
		Action(const sf::Keyboard::Key & key, int type = Type::RealTime | Type::Pressed);
		Action(const sf::Mouse::Button & button, int type = Type::RealTime | Type::Pressed);
	
		
		/*! \brief Comparison operator, by events */
		bool operator==(const sf::Event & event) const;
		bool operator==(const Action & other) const;

		/*! \brief For testing real-time events */	
		bool test() const;
	
	private:
		friend class ActionTarget;
		sf::Event _event;
		int _type;

};

#endif
