#ifndef GRAVITY_H
#define GRAVITY_H

#include <vector>
#include "Atom.h"
#include "Mob.h"

class Gravity
{
private:
	static std::vector<Gravity*> gravity_wells;

	Atom* holder; // What holds this?

	float acceleration = 10; // How much pull does this gravity well have?
	float falloff = 1; // What radius does the gravity start falling off?

	void gravitate( Mob* mob, double multiplier );

	float getPull( float obj_pos, float grav_pos, double multiplier );

public:
	static void processGravity( double update_multiplier );

	Gravity( float accel );
	~Gravity();

	void handle( double update_multiplier );	
};

#endif
