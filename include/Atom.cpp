#include <vector>
#include <GLFW/glfw3.h>
#include "Atom.h"
#include "EngineFSM.h"
#include "helpers/GLFWFuncs.h"
#include "helpers/misc.h"
#include "helpers/debug.h"

std::vector<Atom*> Atom::atoms;

void Atom::renderAtoms()
{
	for( std::vector<Atom*>::iterator it = atoms.begin(); it != atoms.end(); ++it )
	{
		if( (*it)->visible )
		{
			//debugging( "Rendering " + (*it)->name );
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

Atom::Atom( Color& clr )
   : color( clr )	
{
	atoms.push_back( this );
}

Atom::Atom( Rect& bnds, Color& clr )
	: bounds( bnds ), color( clr )
{
	atoms.push_back( this );
}

Atom::~Atom() {}

void Atom::render()
{
	glPushAttrib( GL_COLOR_BUFFER_BIT );
	glPushMatrix();
	glEnableClientState( GL_VERTEX_ARRAY );

	glColor3f( color );

	glTranslatef( bounds.getOrigin().x, bounds.getOrigin().y, 0.f );

	glVertexPointer( 2, GL_FLOAT, 0, vertices.data() );
	glDrawArrays( draw_mode, 0, vertices.size()/2 );

	glDisableClientState( GL_VERTEX_ARRAY );
	glPopMatrix();
	glPopAttrib();
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

