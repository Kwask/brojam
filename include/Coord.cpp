#include "Coord.h"

Coord::Coord() 
	: x( 0 ), y( 0 ) {}

Coord::Coord( const Coord& copy )
	: x( copy.x ), y( copy.y ) {}

Coord::Coord( float xPos, float yPos )
	: x( xPos ), y( yPos ) {}

Coord::~Coord() {}

bool Coord::operator==( Coord const b ) const
{
	if( this->x != b.x )
	{
		return false;
	}
	else if( this->y == b.y )
	{
		return false;
	}

	return true;
}

Coord Coord::operator+( Coord const b ) const
{
	Coord a;
	a.x = this->x + b.x;
	a.y = this->y + b.y;
	return a;
}

Coord Coord::operator-( Coord const b ) const
{
	Coord a;
	a.x = this->x - b.x;
	a.y = this->y - b.y;
	return a; 
}

Coord Coord::operator=( Coord const b ) const
{
	Coord a;
	a.x = b.x;
	a.y = b.y;
	return a;
}
