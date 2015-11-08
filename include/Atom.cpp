#include "Atom.h"
#include "EngineFSM.h"
#include "RakNet/RakPeerInterface.h"
#include "RakNet/NetworkIDObject.h"
#include "RakNet/BitStream.h"
#include "RakNet/MessageIdentifiers.h"

Atom::Atom() 
{
	EngineFSM::process.addToContents( this );
}

Atom::Atom( Rect orig, Rect bnds )
	: origin( orig ), bounds( bnds )
{
	EngineFSM::process.addToContents( this );
}

Atom::~Atom() {}

void Atom::rakSetNetworkIDManager( RakNet::NetworkIDManager* manager )
{
	rakNetworkID.SetNetworkIDManager( manager );	
}

void Atom::rakSendUpdate( RakNet::RakPeerInterface* peer )
{
	RakNet::BitStream* update = rakMakeBitstream();
	peer->Send( update, HIGH_PRIORITY, RELIABLE_ORDERED, 0, RakNet::UNASSIGNED_SYSTEM_ADDRESS, true ); 
}

