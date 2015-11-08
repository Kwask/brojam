#ifndef ENGINEFSM_H
#define ENGINEFSM_H

#include "patterns/FSM.h"
#include "EngineStates.h"

class EngineFSM : public FSM
{
public:
	static EngineStart start;
	static EngineProcess process;
	static EnginePoll poll;
	static EngineRender render;
	static EngineStop stop;
};

#endif
