#ifndef CLIENT_H
#define CLIENT_H

#include <string>

#include "RakNet/RakPeerInterface.h"
#include "RakNet/RakNetTypes.h"
#include "RakNet/MessageIdentifiers.h"
#include "RakNet/BitStream.h"

class Client
{
private:
	std::string username;

	RakNet::RakNetGUID guid;
	
	Client();

public:
	Client( RakNet::RakNetGUID passed_ID );
	
	RakNet::RakNetGUID rakGetGUID() const;
};

#endif
