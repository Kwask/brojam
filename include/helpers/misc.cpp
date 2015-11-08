#include <vector>
#include <algorithm>
#include "misc.h"

template<typename T>
bool eraseRemove( std::vector<T>* vec, T value )
{
	vec->erase(std::remove(vec->begin(), vec->end(), value), vec->end());
}
