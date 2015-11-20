#ifndef MOB_H
#define MOB_H

#include <vector>
#include "Coord.h"
#include "Atom.h"

class Mob : public Atom
{
protected:
	unsigned char direction; // what direction are we facing?

	static std::vector<Mob*> mobs;

	Coord speed;

public:
	static void processMobs();

	Mob();
	~Mob();

	void handle();
	void render();
};

#endif
