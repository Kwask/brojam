#ifndef COORD_H
#define COORD_H

struct Coord
{
	Coord();
	Coord( Coord* copy );
	Coord( int x, int y );
	~Coord();

	int x;
	int y;

	bool operator==( Coord const b ) const;

	Coord operator+( Coord const b ) const;
	Coord operator-( Coord const b ) const;
	Coord operator=( Coord const b ) const;
};

#endif
