#ifndef CONTAINER_H
#define CONTAINER_H

#include <forward_list>
#include "Object.h"

class Container
{
private:
	std::forward_list<Object*> contents;
	

public:
	Container();
	~Container();


	void addToContents( Object* object );
	void eraseFromContents( Object* object ); // Removes the given object and calls its destructor
	void removeFromContents( Object* object ); // Removes the given object from the contents
	void eraseAllContents();

	Object* takeFromContents( Object* object ); // Takes a specific item from the contents
	Object* pickFromContents(); // Takes the first object from the front of the container

};


#endif
