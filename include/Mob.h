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

	float max_speed = 500; // Maximum speed in any direction
	float angular_speed = 0; // Positive is countercolockwise, negative is clockwise

	Coord speed; // Vector of speeed

	float calcAngle();

public:
	static void processMobs( double update_multiplier );

	Mob( Rect& bnds, Color& clr );
	~Mob();

	void handle( double update_multiplier );
	void addXSpeed( float speed_x );
	void addYSpeed( float speed_y );
	void addAngSpeed( float ang_speed );
};

#endif
