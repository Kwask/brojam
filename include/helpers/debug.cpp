#include <iostream>
#include <string>
#include "debug.h"
 
void debugging( std::string message )
{
    if( DEBUG )
    {
        fprintf( stdout, "%s\n", message.c_str() );
    }
}

