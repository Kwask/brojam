#include "misc.h"
#include "../Rect.h"
#include "../Coord.h"

void rectCenter( Rect& given, const Coord& center )
{
	given.origin.x = center.x-( given.bounds.x/2 );
	given.origin.y = center.y-( given.bounds.y/2 );
}

