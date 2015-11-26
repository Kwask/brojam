#include "CommandHandler.h"
#include "Command.h"

Command* CommandHandler::handleInput( int key, int scancode, int action, int mods )
{
	if( action == GLFW_PRESS )
	{
		switch( key )
		{
			case( GLFW_KEY_W ):
				return w_press;
			case( GLFW_KEY_A ):
				return a_press;
			case( GLFW_KEY_S ):
				return s_press;
			case( GLFW_KEY_D ):
				return d_press;
			case( GLFW_KEY_SPACE ):
				return space_press;
		}	
	}

	return nullptr;
}

