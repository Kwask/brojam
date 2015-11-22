#include <vector>
#include <GLFW/glfw3.h>
#include "Atom.h"
#include "EngineFSM.h"
#include "helpers/misc.h"
#include "helpers/debug.h"

std::vector<Atom*> Atom::atoms;

void Atom::renderAtoms()
{
	for( std::vector<Atom*>::iterator it = atoms.begin(); it != atoms.end(); ++it )
	{
		if( (*it)->visible )
		{
			(*it)->render();
		}
	}	
}

void Atom::deleteAtoms()
{
	for( std::vector<Atom*>::iterator it = atoms.begin(); it != atoms.end(); ++it )
	{
		(*it)->del();
	}

	atoms.clear();
}

Atom::Atom() 
{
	atoms.push_back( this );
}

Atom::Atom( Rect bnds )
	: bounds( bnds )
{
	atoms.push_back( this ); // Adding this object to the global list of atoms
	debugging( "Atom created!" );
}

Atom::~Atom() {}

void Atom::render()
{
	glColor3f( 0.5f, 0.5f, 0.5f );

	glEnableClientState( GL_VERTEX_ARRAY );

	glVertexPointer( 2, GL_FLOAT, 0, vertices.data() );
	glDrawArrays( draw_mode, 0, vertices.size()/2 );

	glDisableClientState( GL_VERTEX_ARRAY );
	glColor3f( 1.0f, 1.0f, 1.0f );
}

void Atom::del()
{
	delete this;
}

void Atom::removeAndDel()
{
	if( findInVector( atoms, this ))
	{
		eraseRemove( atoms, this ); // Removing this object from the atoms list	
	}

	del();
}

