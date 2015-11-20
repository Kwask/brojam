#ifndef PLANET_H
#define PLANET_H

#include "Atom.h"

class Planet : public Atom
{
protected:
	float radius = 10;

	void generateVertices();

public:
	Planet();

};

#endif
