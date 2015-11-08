#ifndef ENGINE_H
#define ENGINE_H

#include "EngineFSM.h"
#include "patterns/State.h"

class Engine
{
private:
	Engine();

	EngineFSM state_machine;

	static Engine* instance;

public:
	static Engine* getInstance();
	static void	resetInstance();

	virtual ~Engine();

	void handle();

	bool shouldStop();

};

#endif
