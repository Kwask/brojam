#ifndef GRAVITY_H
#define GRAVITY_H

#include <vector>
#include "Atom.h"
#include "Mob.h"

class Gravity
{
private:
	static std::vector<Gravity*> &gravity_wells();

	Atom* holder; // What holds this?

	float acceleration = 1; // How much pull does this gravity well have?
	float falloff_distance = 1; // What radius does the gravity start falling off?
	float min_force_distance = 1; // The distance from the gravity well where gravitation force begins
	float max_force_distance = 0; // The maximum force distance from the gravity well, 0 for no cap

	void gravitate( Mob* mob, double multiplier );

	float getDistance( Atom* atom );

public:
	static void processGravity( double update_multiplier );

	Gravity( float accel, Atom* holder );
	~Gravity();

	void handle( double update_multiplier );	
};

#endif
