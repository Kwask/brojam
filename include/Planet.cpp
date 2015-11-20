#include <cmath>
#include <vector>
#include "Planet.h"
#include "helpers/defines.h"

Planet::Planet()
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

