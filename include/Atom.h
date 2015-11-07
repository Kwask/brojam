#ifndef ATOM_H
#define ATOM_H

#include "RakNet/RakPeerInterface.h"
#include "RakNet/NetworkIDObject.h"
#include "RakNet/BitStream.h"
#include "Rect.h"

// Abstract class used as the base for all objects
class Atom
{
protected:
	Rect origin; // Used to draw any textures
	Rect bounds; // Used for collision detection
	
	RakNet::NetworkIDObject rakNetworkID;

public:
	Atom();
	Atom( Rect orig, Rect bnds ); 
	~Atom();

	void rakSetNetworkIDManager( RakNet::NetworkIDManager* manager );
	void rakSendUpdate( RakNet::RakPeerInterface* peer ); // Updates the object to the network
	virtual void rakRecieveUpdate( RakNet::BitStream* update ) = 0;

	virtual RakNet::BitStream* rakMakeBitstream() = 0; // Creates a standardized bitstream of the object

};

#endif
