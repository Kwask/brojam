#include <cmath>
#include <vector>
#include "Planet.h"
#include "Atom.h"
#include "Rect.h"
#include "helpers/defines.h"

Planet::Planet( Color& clr )
	: Atom( clr )
{
	generateVertices();
}

Planet::Planet( Rect& bnds, Color& clr )
	: Atom( bnds, clr )
{
	generateVertices();
}	

void Planet::generateVertices()
{
	for( float i = 0; i < 2*PI; i+=0.01f )
	{
		vertices.push_back( cos( i )*radius );
		vertices.push_back( sin( i )*radius );
	}
}

