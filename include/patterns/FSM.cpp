#include "Debug.h"
#include "FSM.h"
#include "State.h"

FSM::FSM()
{
	state_ = nullptr;
}

FSM::FSM( State* const state )
{
	state_ = state;
}

FSM::~FSM()
{
	cleanup();
}

void FSM::cleanup()
{
	if( state_ )
	{
		state_->cleanup();
		state_ = nullptr;
	}
}

void FSM::changeState()
{
	if( state_ )
	{
		state_ = state_->handle();
	}
}

void FSM::forceState( State* const state )
{
	cleanup();
	state_ = state;
}

State* const FSM::currentState()
{
	return state_;
}

char const* FSM::getStateName()
{
	return state_->getName();
}
