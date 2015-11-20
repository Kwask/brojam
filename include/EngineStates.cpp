#include <vector>
#include <GLFW/glfw3.h>
#include "EngineStates.h"
#include "EngineFSM.h"
#include "helpers/GLFWFuncs.h"
#include "helpers/debug.h"
#include "helpers/misc.h"
#include "Mob.h"
#include "Atom.h"
#include "Planet.h"

// Engine stop
EngineStart::~EngineStart() {}

void EngineStart::cleanup() {}

State* EngineStart::handle()
{
	glfwInit();
	debugging( "GLFW INITIALIZED" );

	GLFWwindow* window = glfwCreateWindow( EngineFSM::render.getWindowWidth(), 
												 EngineFSM::render.getWindowHeight(), 
												 "Brojam", 
												 nullptr, 
												 nullptr );
	EngineFSM::render.setWindow( window );

	glfwMakeContextCurrent( EngineFSM::render.getWindow() );

	glfwSetWindowSizeCallback( EngineFSM::render.getWindow(), GLFWResize );
	GLFWResize( EngineFSM::render.getWindow(),
				EngineFSM::render.getWindowWidth(), 
				EngineFSM::render.getWindowHeight() );


	glfwSwapInterval( 1 );

	new Planet;

	return &EngineFSM::process;
}

// Engine process
EngineProcess::~EngineProcess() {}

void EngineProcess::cleanup() {}

State* EngineProcess::handle()
{
	Mob::processMobs(); // Does all of the processing for mobs

	return &EngineFSM::poll;
}

// EnginePoll
EnginePoll::~EnginePoll() {}

void EnginePoll::cleanup() {}

State* EnginePoll::handle()
{
	glfwPollEvents();

	// If the window exit button was pressed, tansition to stop
	if( glfwWindowShouldClose( EngineFSM::render.getWindow() ))
	{
		debugging("WINDOW CLOSING.");
		return &EngineFSM::stop;
	}

	return &EngineFSM::render;
}

// EngineRender
EngineRender::EngineRender( int width, int height )
	: dimensions( width, height ) {}

EngineRender::~EngineRender() {}

void EngineRender::cleanup() {}

void EngineRender::populateVerticeVector()
{
	
}

void EngineRender::setWindow( GLFWwindow* window )
{
	destroyWindow();
	this->window = window;
}

void EngineRender::destroyWindow()
{
	if( window )
	{
		glfwDestroyWindow( window );
		window = nullptr;
	}
}

int EngineRender::getWindowWidth()
{
	return dimensions.x;
}

int EngineRender::getWindowHeight()
{
	return dimensions.y;
}

GLFWwindow* EngineRender::getWindow()
{
	return window;
}

State* EngineRender::handle()
{
	int dimensions = 2; // how many dimensions are we working in?

	// Moves everything backward by -1 opengl unit
	glTranslatef( 0.f, 0.f, -1.f );

	// Draw all atoms
	Atom::renderAtoms();

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

	EngineFSM::render.destroyWindow();
	glfwTerminate();
	debugging("GLFW TERMINATED.");

	debugging("ENGINE STOPPED.");
	return nullptr;
}
