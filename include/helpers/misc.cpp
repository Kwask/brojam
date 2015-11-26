#include "misc.h"
#include "../Rect.h"

Rect rectCenter( const Rect& given )
{
	Rect centered( given.origin.x-( given.bounds.x/2 ),
				   given.origin.y-( given.bounds.y/2 ),
				   given.origin.x+( given.bounds.x/2 ),
				   given.origin.y+( given.bounds.y/2 ));

	return centered;
}

