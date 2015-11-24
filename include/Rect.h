#ifndef RECT_H
#define RECT_H

#include "Coord.h"

struct Rect
{
	Coord origin;
	Coord bounds;

	Rect();
	Rect( Rect& copy );
	Rect( int x, int y, int width, int height );
	Rect( const Coord origin, const Coord bound );
	~Rect();

	Coord getOrigin() const;
	Coord getBounds() const;

	void setOrigin( const Coord origin );
	void setBounds( const Coord bounds );
};

#endif
