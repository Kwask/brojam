#include <iostream>
#include <string>
#include "Debug.h"
 
void debugging( std::string message )
{
    if( DEBUG )
    {
        fprintf( stdout, "%s\n", message.c_str() );
    }
}

