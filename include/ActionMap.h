#ifndef _ACTIONMAP_
#define _ACTIONMAP_

#include <unordered_map>

template <typename T = int>
class ActionMap {
	public:
		ActionMap(const ActionMap<T> &) = delete;
	
		ActionMap<T> & operator=(const ActionMap<T> &) = delete;

		ActionMap() = default;
	
		void map(const T & key, const Action & action);
		
		const Action & get (const T & key) const;

	private:
		std::unordered_map<T, Action> _map;
		

};

#include "../src/ActionMap.tpl"

#endif
