#include "Rect.h"
#include "Coord.h"

Rect::Rect() {}

Rect::Rect( Rect& copy )
	: origin( copy.origin ), bounds( copy.bounds ) {}

Rect::Rect( int xPos, int yPos, int width, int height )
	: origin( xPos, yPos ), bounds( width, height ) {}

Rect::Rect( const Coord orig, const Coord bnds )
	: origin( orig ), bounds( bnds ) {}

Rect::~Rect() {}

Coord Rect::getOrigin() const
{
	return origin;
}

Coord Rect::getBounds() const
{
	return bounds;
}

void Rect::setOrigin( const Coord origin )
{
	this->origin = origin;
}

void Rect::setBounds( const Coord bounds )
{
	this->bounds = bounds;
}

