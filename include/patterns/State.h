#ifndef STATE_H
#define STATE_H

class State
{
protected:
	char const* name = ""; 

public:
	virtual ~State();
	
	virtual void cleanup() = 0;

	virtual State* handle() = 0; // Handles all actions of the current state and transition to the next state
	
	virtual char const* getName();
};

#endif