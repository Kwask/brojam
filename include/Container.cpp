#include <forward_list>
#include "Container.h"

Container::Container() {}

Container::~Container() 
{
	eraseAllContents();
}

void Container::addToContents( Object* object )
{
	contents.push_front( object );
}

void Container::eraseFromContents( Object* object )
{
	removeFromContents( object );
	delete object;
}

void Container::removeFromContents( Object* object )
{
	contents.remove( object );
}

void Container::eraseAllContents()
{
	while( contents.front() )
	{
		delete contents.front();
		contents.pop_front();
	}
}

Object* Container::takeFromContents( Object* object )
{
	removeFromContents( object );

	return object;
}

Object* Container::pickFromContents()
{
	Object* object = contents.front();
	contents.pop_front();

	return object;
}

