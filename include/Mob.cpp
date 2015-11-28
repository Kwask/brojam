#include <vector>
#include <cmath>
#include "Mob.h"
#include "helpers/misc.h"
#include "helpers/Color.h"
#include "helpers/debug.h"

std::vector<Mob*> &Mob::mobs()
{
	static std::vector<Mob*>* mobs = new std::vector<Mob*>;
	return *mobs;
}

float Mob::calcAngle()
{
	return asind( speed.y/speed.x );
}

void Mob::generateVertices()
{
	vertices.push_back( -bounds.bounds.x/2 );
	vertices.push_back( -bounds.bounds.y/2 );

	vertices.push_back( bounds.bounds.x/2 );
	vertices.push_back( -bounds.bounds.y/2 );

	vertices.push_back( bounds.bounds.x/2 );
	vertices.push_back( bounds.bounds.y/2 );

	vertices.push_back( -bounds.bounds.x/2 );
	vertices.push_back( bounds.bounds.y/2 );
}

void Mob::addToMobs()
{
	mobs().push_back( this );
}

void Mob::processMobs( double update_multiplier )
{
	for( std::vector<Mob*>::iterator it = mobs().begin(); it != mobs().end(); ++it )
	{
		(*it)->handle( update_multiplier );
	}
}

Mob::Mob( Color& clr, Rect& bnds )
	: Atom( clr, bnds ) 
{
	this->generateVertices();
	addToMobs();
}

Mob::~Mob()
{

}

void Mob::handle( double update_multiplier )
{
//	debugging( std::string( "Speed X: " ) + std::to_string( speed.x )); 
//	debugging( std::string( "Speed Y: " ) + std::to_string( speed.y )); 

	bounds.origin.x += speed.x*update_multiplier;
	bounds.origin.y += speed.y*update_multiplier;

	angle = calcAngle();  
}

void Mob::addXSpeed( float speed_x )
{
	speed.x += speed_x;
	
	if( fabs( speed.x ) > max_speed )
	{
		speed.x = sign( speed.x )*max_speed;
	}
}

void Mob::addYSpeed( float speed_y )
{
	speed.y += speed_y;
	
	if( fabs( speed.y ) > max_speed )
	{
		speed.y = sign( speed.y )*max_speed;
	}
}

void Mob::addAngSpeed( float ang_speed )
{
	angular_speed += ang_speed;

	if( fabs( angular_speed ) > max_speed )
	{
		angular_speed = sign( angular_speed )*max_speed;
	}
}

void Mob::removeAndDel()
{
/*	if( findInVector( atoms, this ))
	{
		eraseRemove( atoms, this ); // Removing this object from the atoms list	
	} */

	if( findInVector( mobs(), this ))
	{
		eraseRemove( mobs(), this );
	}

	del();
}

