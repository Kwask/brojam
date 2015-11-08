#include "Client.h"
#include "RakNet/RakNetTypes.h"

Client::Client() {}

Client::Client( RakNet::RakNetGUID passed_ID )
	: guid( passed_ID ) {}

RakNet::RakNetGUID Client::rakGetGUID() const
{
	return guid;
}

