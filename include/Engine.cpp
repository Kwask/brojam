#include "helpers/debug.h"
#include "Engine.h"
#include "patterns/FSM.h"
#include "patterns/State.h"
#include "EngineFSM.h"
#include "EngineStates.h"

Engine* Engine::instance = nullptr;

Engine::Engine()
	: state_machine( &EngineFSM::start ) {}

Engine* Engine::getInstance()
{
	if( !instance )
	{
		instance = new Engine;
	}

	return instance;
}

void Engine::resetInstance()
{
	delete instance;
	instance = nullptr;
}

Engine::~Engine()
{
	instance = nullptr;
}

void Engine::handle()
{
	while( !shouldStop() )
	{
		state_machine.changeState();
	}
}

bool Engine::shouldStop()
{
	if( state_machine.currentState() == nullptr )
	{
		return true;
	}

	return false;
}

