#ifndef _ATARGET_
#define _ATARGET_

#include <functional>
#include <utility>
#include <list>
#include "ActionMap.h"

template <typename T = int>
class ActionTarget {

	public:
		
		ActionTarget(const ActionTarget<T> &) = delete;
		ActionTarget<T> & operator=(const ActionTarget<T> &) = delete;

		using FuncType = std::function<void (const sf::Event &) >;	
		
		ActionTarget(const ActionMap<T> & map);

		/*! For non-real-time events  */
		bool proccessEvent(const sf::Event & event) const;
		
		/*! For real-time events  */
		void proccessEvents() const;

		void bind(const T & key, const FuncType & callback);
		void unbind(const T & key);
		
	private:
		std::list<std::pair<T, FuncType>> _eventsRealTime;
		std::list<std::pair<T, FuncType>> _eventsPoll;

		const ActionMap<T> & _actionMap;

};

#include "../src/ActionTarget.inl"

#endif
