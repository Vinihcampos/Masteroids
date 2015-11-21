#ifndef _ENEMY_
#define _ENEMY_

#include "PhysicalEntity.h"

class Enemy : public PhysicalEntity {

	public:
		Enemy(const Enemy &) = delete;
		Enemy & operator=(const Enemy &) = delete;

		Enemy(Universe & _universe) : PhysicalEntity{ _universe } {};
	
		virtual void onDestroy();
		virtual int getPoints() const;
		virtual void setPoints(int);
	private:
		int points;

};

#endif
