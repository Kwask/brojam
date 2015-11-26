#include "PlayerCommands.h"
#include "patterns/Command.h"
#include "Creature.h"

void PlayerJump::execute( Creature& creature )
{
	creature.moveUp();
}

void PlayerLeft::execute( Creature& creature )
{
	creature.moveLeft();
}

void PlayerRight::execute( Creature& creature )
{
	creature.moveRight();
}

