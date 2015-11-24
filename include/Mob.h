#ifndef MOB_H
#define MOB_H

#include <vector>
#include "Coord.h"
#include "Atom.h"

class Mob : public Atom
{
protected:
	static std::vector<Mob*> mobs;

	Coord speed; // Vector of speed

public:
	static void processMobs();

	Mob( Color& clr );
	~Mob();

	void handle();
	void render();
};

#endif
