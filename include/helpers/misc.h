#ifndef HELPER_MISC_H
#define HELPER_MISC_H

#include <algorithm>
#include <vector>

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

#endif
