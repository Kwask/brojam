#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include <GLFW/glfw3.h>
#include "Command.h"

class CommandHandler
{
protected:
	Command* w_press = nullptr;
	Command* a_press = nullptr;
	Command* s_press = nullptr;
	Command* d_press = nullptr;
	Command* space_press = nullptr;

public:
	CommandHandler( Command* w_press = nullptr, 
					Command* a_press = nullptr, 
					Command* s_press = nullptr, 
					Command* d_press = nullptr, 
					Command* space_press = nullptr );
	Command* handleInput( int key, int scancode, int action, int mods );

};

#endif
