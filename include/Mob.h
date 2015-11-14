#ifndef MOB_H
#define MOB_H

#include <vector>
#include "Atom.h"

class Mob : public Atom
{
protected:
	static std::vector<Mob*> mobs;

public:
	static void processMobs();

	Mob();
	~Mob();

	void handle();

};

#endif
