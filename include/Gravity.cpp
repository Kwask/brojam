#include "Gravity.h"
#include "Mob.h"
#include "helpers/misc.h"

std::vector<Gravity*> Gravity::gravity_wells;

void Gravity::processGravity( double update_multiplier )
{
	for( std::vector<Gravity*>::iterator it = gravity_wells.begin(); it != gravity_wells.end(); ++it )
	{
		(*it)->handle( update_multiplier );
	}
}

Gravity::Gravity( float accel )
	: acceleration( accel ) 
{
	gravity_wells.push_back( this );
}

Gravity::~Gravity()
{
	eraseRemove( gravity_wells, this );
}

void Gravity::handle( double update_multiplier )
{
	for( std::vector<Mob*>::iterator it = Mob::mobs.begin(); it != Mob::mobs.end(); ++it )
	{
		gravitate( *it, update_multiplier );
	}
}

void Gravity::gravitate( Mob* mob, double multiplier )
{
	mob->addXSpeed( getPull( mob->getXPos(), holder->getXPos(), multiplier ));
	mob->addXSpeed( getPull( mob->getYPos(), holder->getYPos(), multiplier ));	
}

float Gravity::getPull( float obj_pos, float grav_pos, double multiplier )
{
	float distance = obj_pos-grav_pos;
	if( distance < 1 )
	{
		return acceleration*multiplier;
	}
	else
	{	
		return ( 1/sqrt( obj_pos-grav_pos ))*acceleration*multiplier;
	}
}
