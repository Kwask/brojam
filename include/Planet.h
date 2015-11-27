#ifndef PLANET_H
#define PLANET_H

#include <string>
#include "Atom.h"
#include "Rect.h"

class Planet : public Atom
{
protected:
	float radius = 100;

	void generateVertices();	

public:
	Planet( Color& clr, Rect &bnds );
};

#endif
