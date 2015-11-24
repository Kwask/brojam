#ifndef MOB_H
#define MOB_H

#include <vector>
#include "Coord.h"
#include "Atom.h"

class Mob : public Atom
{
	friend class Gravity;

protected:
	static std::vector<Mob*> mobs;

	Coord speed; // Vector of speed

public:
	static void processMobs( double update_multiplier );

	Mob( Color& clr );
	~Mob();

	void handle( double update_multiplier );
	void addXSpeed( float speed_x );
	void addYSpeed( float speed_y );
};

#endif
