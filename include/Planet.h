#ifndef PLANET_H
#define PLANET_H

#include <string>
#include "Atom.h"
#include "Rect.h"

class Planet : protected Atom
{
protected:
	float radius = 100;
	void generateVertices();

public:
	Planet( Color& clr );
	Planet( Rect &bnds, Color& clr );
};

#endif
