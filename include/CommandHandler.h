#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include "PlayerCommands.h"

class CommandHandler
{
protected:
	PlayerCommand* w_press = nullptr;
	PlayerCommand* a_press = nullptr;
	PlayerCommand* s_press = nullptr;
	PlayerCommand* d_press = nullptr;
	PlayerCommand* space_press = nullptr;

public:
	CommandHandler( PlayerCommand* w_press = nullptr, 
					PlayerCommand* a_press = nullptr, 
					PlayerCommand* s_press = nullptr, 
					PlayerCommand* d_press = nullptr, 
					PlayerCommand* space_press = nullptr );
	PlayerCommand* handleInput( int key, int scancode, int action, int mods );
};

#endif
