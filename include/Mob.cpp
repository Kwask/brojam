#include <vector>
#include "helpers/misc.h"
#include "Mob.h"
#include "helpers/Color.h"

std::vector<Mob*> Mob::mobs;

void Mob::processMobs( double update_multiplier )
{
	for( std::vector<Mob*>::iterator it = mobs.begin(); it != mobs.end(); ++it )
	{
		(*it)->handle( update_multiplier );
	}
}

Mob::Mob( Color& clr )
	: Atom( clr )
{
	mobs.push_back( this );
}

Mob::~Mob()
{
	eraseRemove( mobs, this );
}

void Mob::handle( double update_multiplier )
{
	bounds.origin.x += speed.x*update_multiplier;
	bounds.origin.y += speed.y*update_multiplier;
}

void Mob::addXSpeed( float speed_x )
{
	speed.x += speed_x;
}

void Mob::addYSpeed( float speed_y )
{
	speed.y += speed_y;
}

