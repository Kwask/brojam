#include <cmath>
#include "Gravity.h"
#include "Mob.h"
#include "helpers/misc.h"

std::vector<Gravity*> &Gravity::gravity_wells()
{
	static std::vector<Gravity*>* gravity_wells = new std::vector<Gravity*>;
	return *gravity_wells;
}

void Gravity::gravitate( Mob* mob, double multiplier )
{
	float distance = getDistance( mob );
	float x_displacement = holder->getXPos() - mob->getXPos();
	float y_displacement = holder->getYPos() - mob->getYPos();
	float x_speed = ( x_displacement/distance )*multiplier*acceleration;
	float y_speed = ( y_displacement/distance )*multiplier*acceleration;

	
	if( fabs( distance ) < min_force_distance )
	{
		x_speed = 0;
		y_speed = 0;
	}

	if( max_force_distance )
	{
		if( fabs( distance ) >= max_force_distance )
		{
			x_speed = 0;
			y_speed = 0;
		}
	}

	if( fabs( distance ) >= falloff_distance )
	{
		float distance_multiplier = sqrt( 1/distance );
		x_speed *= distance_multiplier;
		y_speed *= distance_multiplier;
	}

	mob->addXSpeed( x_speed );
	mob->addYSpeed( y_speed );	
}

float Gravity::getDistance( Atom* atom )
{
	float x_displacement = holder->getXPos() - atom->getXPos();
	float y_displacement = holder->getYPos() - atom->getYPos();

	return sqrt( pow( x_displacement, 2) + pow( y_displacement, 2 ));
}

void Gravity::processGravity( double update_multiplier )
{
	for( std::vector<Gravity*>::iterator it = gravity_wells().begin(); it != gravity_wells().end(); ++it )
	{
		(*it)->handle( update_multiplier );
	}
}

Gravity::Gravity( float accel, Atom* holder )
	: holder( holder ), acceleration( accel )
{
	gravity_wells().push_back( this );
}

Gravity::~Gravity()
{
	eraseRemove( gravity_wells(), this );
}

void Gravity::handle( double update_multiplier )
{
	for( std::vector<Mob*>::iterator it = Mob::mobs().begin(); it != Mob::mobs().end(); ++it )
	{
		gravitate( *it, update_multiplier );
	}
}

