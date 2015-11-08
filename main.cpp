#include "include/Engine.h"
#include "include/helpers/debug.h"

int main( int argc, char** argv)
{
	debugging( "ENGINE INSTANCING..." );
	Engine* engine = Engine::getInstance();

	engine->handle();

	debugging( "ENGINE DELETING..." );
	Engine::resetInstance();
	debugging( "ENGINE DELETED." );
}
