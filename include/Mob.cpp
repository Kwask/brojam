#include <vector>
#include "helpers/misc.h"
#include "Mob.h"

std::vector<Mob*> Mob::mobs;

void Mob::processMobs()
{
	for( std::vector<Mob*>::iterator it = mobs.begin(); it != mobs.end(); ++it )
	{
		(*it)->handle();
	}
}

Mob::Mob()
{
	mobs.push_back( this );
}

Mob::~Mob()
{
	eraseRemove( mobs, this );
}

void Mob::handle()
{

}
