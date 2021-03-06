#include "Creature.h"
#include "Mob.h"
#include "helpers/misc.h"
#include "helpers/defines.h"

Creature::Creature( Color& clr, Rect& bnds )
	: Mob( clr, bnds ) {}

void Creature::moveUp()
{
	//addXSpeed( cosd( dirUp() )*move_speed );
	//addYSpeed( sind( dirUp() )*move_speed );
	speed.y += move_speed;
}

void Creature::moveDown()
{
	//addXSpeed( cosd( dirDown() )*move_speed );
	//addYSpeed( sind( dirDown() )*move_speed );
	speed.y -= move_speed;
}

void Creature::moveLeft()
{
	//addXSpeed( cosd( dirLeft() )*move_speed );
	//addYSpeed( sind( dirLeft() )*move_speed );
	speed.x -= move_speed;
}

void Creature::moveRight()
{
	//addXSpeed( cosd( dirRight() )*move_speed );
	//addYSpeed( sind( dirRight() )*move_speed );
	speed.x += move_speed;
}

// Returns the local up direction
float Creature::dirUp()
{
	return angle+DIR_UP_OFFSET;
}

// Returns the local down direction
float Creature::dirDown()
{
	return angle+DIR_DOWN_OFFSET;
}

// Returns the local left direction
float Creature::dirLeft()
{
	return angle+DIR_LEFT_OFFSET;
}

// Returns the local right direction
float Creature::dirRight()
{
	return angle+DIR_RIGHT_OFFSET;
}

