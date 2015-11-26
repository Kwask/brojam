#ifndef PLAYERCOMMANDS_H
#define PLAYERCOMMANDS_H

#include "Creature.h"
#include "patterns/Command.h"

class PlayerJump : public Command
{
public:
	using Command::execute;
	void execute( Creature& creature );
};

class PlayerLeft : public Command 
{
public:
	using Command::execute;
	void execute( Creature& creature );
};

class PlayerRight : public Command 
{
public:
	using Command::execute;
	void execute( Creature& creature );
};

class PlayerShoot: public Command 
{
public:
	using Command::execute;
	void execute( Creature& creature );
};

#endif
