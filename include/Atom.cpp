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

Atom::Atom() {}

Atom::Atom( Color& clr, Rect& bnds )
	: color( clr ), bounds( bnds )
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

//	glRotatef( angle, 1.f, 0.f, 0.f );
	glTranslatef( bounds.getOrigin().x, bounds.getOrigin().y, -1.f );

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

void Atom::setXPos( float x )
{
	bounds.origin.x = x;
}

void Atom::setYPos( float y )
{
	bounds.origin.y = y;
}

float Atom::getXPos()
{
	return bounds.origin.x;
}

float Atom::getYPos()
{
	return bounds.origin.y;
}

Coord Atom::getOrigin()
{
//	debugging( std::string( "X: " ) + std::to_string( bounds.origin.x ));
//	debugging( std::string( "Y: " ) + std::to_string( bounds.origin.y ));
	return bounds.origin;
}

