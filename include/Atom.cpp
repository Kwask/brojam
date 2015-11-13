#include <vector>
#include "Atom.h"
#include "EngineFSM.h"
#include "helpers/misc.h"

std::vector<Atom*> Atom::atoms;

Atom::Atom() 
{
	atoms.push_back( this );
}

Atom::Atom( Rect orig, Rect bnds )
	: origin( orig ), bounds( bnds )
{
	atoms.push_back( this );	
}

Atom::~Atom()
{
	eraseRemove( atoms, this );	
}


