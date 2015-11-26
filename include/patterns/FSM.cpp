#include "FSM.h"
#include "State.h"

FSM::FSM()
	: state_( nullptr ) {}

FSM::FSM( State* const state )
	: state_( state ) {};

FSM::~FSM() {}

void FSM::changeState()
{
	if( state_ )
	{
		state_ = state_->handle();
	}
}

void FSM::forceState( State* const state )
{
	state_ = state;
}

State* FSM::currentState() const
{
	return state_;
}

