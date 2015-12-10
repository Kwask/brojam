#ifndef CREATURE_H
#define CREATURE_H

#include "Mob.h"
#include "Rect.h"
#include "helpers/Color.h"

class Creature : public Mob
{
protected:
	float health = 100;
	float max_health = 100;
	float move_speed = 0.05; // OpenGL units / second

public:
	Creature( Color& clr, Rect& bnds );

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	float dirUp();
	float dirDown();
	float dirLeft();
	float dirRight();

};

#endif
