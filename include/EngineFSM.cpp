#include "EngineFSM.h"
#include "EngineStates.h"
#include "patterns/State.h"

EngineFSM::EngineFSM( State* const state )
{
	state_ = state;
}

EngineStart EngineFSM::start;
EngineProcess EngineFSM::process;
EnginePoll EngineFSM::poll;
EngineRender EngineFSM::render;
EngineStop EngineFSM::stop;

