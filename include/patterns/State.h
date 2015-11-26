#ifndef STATE_H
#define STATE_H

class State
{
public:
	virtual ~State();

	virtual State* handle() = 0; // Handles all actions of the current state and transition to the next state
};

#endif
