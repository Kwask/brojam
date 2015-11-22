#ifndef PLANET_H
#define PLANET_H

#include "Atom.h"

class Planet : public Atom
{
protected:
	float radius = 100;

	void generateVertices();

public:
	Planet();
};

#endif
