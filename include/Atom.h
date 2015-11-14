#ifndef ATOM_H
#define ATOM_H

#include <string>
#include <vector>
#include "Rect.h"

// Abstract class used as the base for all objects
class Atom
{
protected:
	Rect origin; // Used to draw any textures
	Rect bounds; // Used for collision detection

	std::string name;
	static std::vector<Atom*> atoms;

public:
	Atom();
	Atom( Rect orig, Rect bnds ); 
	~Atom();

};

#endif
