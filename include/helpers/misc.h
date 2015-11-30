#ifndef HELPER_MISC_H
#define HELPER_MISC_H

#include <algorithm>
#include <vector>
#include <cmath>
#include "defines.h"
#include "debug.h"

// A function that uses the erase-remove idiom to remove the given value from the given vector
template<typename T>
inline void eraseRemove( std::vector<T> &vec, const T &value )
{
	vec.erase(std::remove(vec.begin(), vec.end(), value), vec.end());
}

// A function that returns true if the given value is in the given vector
template<typename T>
inline bool findInVector( std::vector<T> &vec, const T &value )
{
	if( std::find( vec.begin(), vec.end(), value ) != vec.end() )
	{
		return true;
	}
	
	return false;
}

template <typename T> 
inline int sign( T val ) 
{
    return (T(0) < val) - (val < T(0));
}

template <typename T>
inline T radToDeg( T parameter )
{
	return parameter*( 180/PI );
}

/*
template <typename T>
inline T sind( T parameter )
{
	return sin( parameter*( PI/180.f ));
}

template <typename T>
inline T cosd( T parameter )
{
	return cos( parameter*( PI/180.f ));
}

template <typename T>
inline T tand( T parameter )
{
	return tan( parameter*( PI/180.f ));
}

template <typename T>
inline T asind( T parameter )
{
	return asin( parameter )*180.f/PI;
}

template <typename T>
inline T acosd( T parameter )
{
	return acos( parameter )*180.f/PI;
}

template <typename T>
inline T atand( T parameter )
{
	return atan( parameter )*180.f/PI;
}
*/

#endif
