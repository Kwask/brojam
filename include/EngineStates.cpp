#include <vector>
#include <GLFW/glfw3.h>
#include "EngineStates.h"
#include "EngineFSM.h"
#include "helpers/GLFWFuncs.h"
#include "helpers/debug.h"
#include "helpers/misc.h"

// Engine stop
EngineStart::~EngineStart() {}

void EngineStart::cleanup() {}

State* EngineStart::handle()
{
	glfwInit();
	debugging( "GLFW INITIALIZED" );

	EngineFSM::render.window = glfwCreateWindow( EngineFSM::render.window_width, EngineFSM::render.window_height, "Brojam", nullptr, nullptr );
	glfwMakeContextCurrent( EngineFSM::render.window );

	glfwSetWindowSizeCallback( EngineFSM::render.window, GLFWResize );
	GLFWResize( EngineFSM::render.window, EngineFSM::render.window_width, EngineFSM::render.window_height );

	glfwSwapInterval( 1 );

	return &EngineFSM::process;
}

// Engine process
EngineProcess::~EngineProcess() {}

void EngineProcess::cleanup() {}

State* EngineProcess::handle()
{
	return &EngineFSM::poll;
}

// EnginePoll
EnginePoll::~EnginePoll() {}

void EnginePoll::cleanup() {}

State* EnginePoll::handle()
{
	glfwPollEvents();

	// If the window exit button was pressed, tansition to stop
	if( glfwWindowShouldClose( EngineFSM::render.window ))
	{
		debugging("WINDOW CLOSING.");
		return &EngineFSM::stop;
	}

	return &EngineFSM::render;
}

// EngineRender
EngineRender::~EngineRender() {}

void EngineRender::cleanup() {}

void EngineRender::populateVerticeVector()
{
	
}

State* EngineRender::handle()
{
	int dimensions = 2; // how many dimensions are we working in?

	// Populates the vector of vertices to be drawn
	populateVerticeVector();

	// Moves everything backward by -1 opengl unit
	glTranslatef( 0.f, 0.f, -1.f );

	glEnableClientState( GL_VERTEX_ARRAY );

	// Specifies the vertice data
	glVertexPointer( dimensions, GL_FLOAT, 0, vertices.data() );
	// Draws the given vertice data
	glDrawArrays( GL_TRIANGLES, 0, vertices.size()/dimensions );

	glDisableClientState( GL_VERTEX_ARRAY );

	// Displays what was just drawn to the screen
	glfwSwapBuffers( window );

	return &EngineFSM::process;
}

// EngineStop
EngineStop::~EngineStop() {}

void EngineStop::cleanup() {}

State* EngineStop::handle()
{
	debugging("ENGINE STOPPING...");

	// If there's a window, destroy it and terminate GLFW
	if( EngineFSM::render.window )
	{
		glfwDestroyWindow( EngineFSM::render.window );
		glfwTerminate();
		debugging("GLFW TERMINATED.");
	}

	debugging("ENGINE STOPPED.");
	return nullptr;
}
