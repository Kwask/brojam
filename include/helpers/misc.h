#ifndef HELPER_MISC_H
#define HELPER_MISC_H

#include <vector>

// A function that uses the erase-remove algorithm to remove the given value from the given vector
template<typename T>
bool eraseRemove( std::vector<T>* vec, T value );  

#endif
