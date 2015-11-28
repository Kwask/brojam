#ifndef PLAYERCOMMANDS_H
#define PLAYERCOMMANDS_H

#include "Creature.h"
#include "patterns/Command.h"

class PlayerCommand : public Command
{
public:
	using Command::execute;
	virtual void execute( Creature& creature ) = 0;	
};

class PlayerJump : public PlayerCommand
{
public:
	void execute( Creature& creature );
};

class PlayerLeft : public PlayerCommand 
{
public:
	void execute( Creature& creature );
};

class PlayerRight : public PlayerCommand 
{
public:
	void execute( Creature& creature );
};

class PlayerDown : public PlayerCommand
{
public:
	void execute( Creature& creature );
};

class PlayerShoot: public PlayerCommand 
{
public:
	void execute( Creature& creature );
};

#endif
