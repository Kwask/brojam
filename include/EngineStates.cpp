#include <vector>
#include <algorithm>
#include <thread>
#include <GLFW/glfw3.h>
#include "EngineStates.h"
#include "EngineFSM.h"
#include "helpers/GLFWFuncs.h"
#include "helpers/debug.h"
#include "helpers/misc.h"
#include "helpers/defines.h"
#include "Mob.h"
#include "Atom.h"
#include "Planet.h"
#include "Rect.h"

// Engine start
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

	Rect planet( 300, 300, 0, 0 );
	Color clr( 0, 255, 0 );
	new Planet( planet, clr );

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

	return &EngineFSM::process;
}

// Engine process
EngineProcess::~EngineProcess() {}

void EngineProcess::cleanup() {}

void EngineProcess::process( double update_multiplier )
{
	Mob::processMobs(); // Does all of the processing for mobs

}

// This processes the game in ticks, every tick should take less than MS_PER_TICK, but if it takes more, this state will process continually until the game is caught up
State* EngineProcess::handle()
{
	double current_tick = glfwGetTime();
	double elapsed_time = current_tick-last_tick;
	last_tick = current_tick;

	time_lag += elapsed_time; // Time since we last processed

	// If we're no longer playing catchup, we can sleep for however long we need
	if( time_lag < MS_PER_TICK )
	{
		std::this_thread::sleep_for( std::chrono::milliseconds( (int)( MS_PER_TICK-time_lag )));
	} 

	// This will process the game, by passing a normalized value as a multiplier
	// Inside here is an if-else statement, and the result of the if-else statement is being divided by the max number of milliseconds per tick
	process((( time_lag>MS_PER_TICK ) ? MS_PER_TICK : time_lag )/MS_PER_TICK );

	time_lag = std::max( 0.0, time_lag-MS_PER_TICK ); // Take away time this process should take

	if( !time_lag )
	{
		return &EngineFSM::render;
	}

	return &EngineFSM::process;
}

// EngineRender
EngineRender::EngineRender( int width, int height )
	: dimensions( width, height ), background( 0.f, 0.33f, 0.4f, 1.f ) {}

EngineRender::~EngineRender() {}

void EngineRender::cleanup() {}

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
	glLoadIdentity();
	glClear( GL_COLOR_BUFFER_BIT );
	glClearColor( background.red, background.green, background.blue, background.alpha );

	// Moves everything backward by -1 opengl unit
	glTranslatef( 0.f, 0.f, -1.f );

	// Draw all atoms
	Atom::renderAtoms();

	// Displays what was just drawn to the screen
	glfwSwapBuffers( window );

	return &EngineFSM::poll;
}

// EngineStop
EngineStop::~EngineStop() {}

void EngineStop::cleanup() {}

State* EngineStop::handle()
{
	debugging("ENGINE STOPPING...");

	Atom::deleteAtoms();

	EngineFSM::render.destroyWindow();
	glfwTerminate();
	debugging("GLFW TERMINATED.");

	debugging("ENGINE STOPPED.");
	return nullptr;
}
