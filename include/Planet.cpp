#include <cmath>
#include <vector>
#include "Planet.h"
#include "Atom.h"
#include "Rect.h"
#include "helpers/defines.h"
#include "helpers/debug.h"

Planet::Planet( Color& clr, Rect& bnds )
	: Atom( clr, bnds ) 
{
	this->generateVertices();
}	

void Planet::generateVertices()
{
	for( float i = 0; i < 2*PI; i+=0.01f )
	{
		vertices.push_back( cos( i )*radius );
		vertices.push_back( sin( i )*radius );
	}
}

