#ifndef COORD_H
#define COORD_H

struct Coord
{
	Coord();
	Coord( Coord* copy );
	Coord( float x, float y );
	~Coord();

	float x;
	float y;

	bool operator==( Coord const b ) const;

	Coord operator+( Coord const b ) const;
	Coord operator-( Coord const b ) const;
	Coord operator=( Coord const b ) const;
};

#endif
