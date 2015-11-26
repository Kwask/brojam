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
#include "Gravity.h"
#include "Creature.h"
#include "patterns/CommandHandler.h"
#include "PlayerCommands.h"
#include "GLFWInput.h"

// Engine start
EngineStart::EngineStart() {}

EngineStart::~EngineStart() {}

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

	glfwSetKeyCallback( EngineFSM::render.getWindow(), keyCallback );

	return &EngineFSM::poll;
}

// EnginePoll
EnginePoll::EnginePoll()
	: handler( new PlayerJump,
			   new PlayerLeft, 
			   nullptr, 
			   new PlayerRight, 
	 		   nullptr ) 
{}

EnginePoll::~EnginePoll() {}

void EnginePoll::keyboardInput( int key, int scancode, int action, int mods )
{
	Command* command = handler.handleInput( key, scancode, action, mods );
	if( command )
	{
		command->execute();
	}
}

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
EngineProcess::EngineProcess()
{
	Rect pos( 300.f, 300.f, 0.f, 0.f );
	Color clr( 0, 255, 0 );
	planet = new Planet( clr, pos );	
}

EngineProcess::~EngineProcess() {}

void EngineProcess::process( double update_multiplier )
{
	Gravity::processGravity( update_multiplier );
	Mob::processMobs( update_multiplier	); // Does all of the processing for mobs

}

// This processes the game in ticks, every tick should take less than MS_PER_TICK, but if it takes more, this state will process continually until the game is caught up
State* EngineProcess::handle()
{
	double current_time = glfwGetTime();
	double elapsed_time = current_time-archived_time; // Time passed since we last processed
	archived_time = current_time;

	time_lag += elapsed_time; // Total amount of time that has to be caught up
	double process_time = ( time_lag>SEC_PER_TICK ) ? time_lag : SEC_PER_TICK; // Amount of game time this process will proceed by
	
	/*
	debugging( std::string( "current_tick: " ) + std::to_string( current_time ));
	debugging( std::string( "process_time: " ) + std::to_string( process_time ));
	debugging( std::string( "time_lag: " ) + std::to_string( time_lag ));
	*/

	// If we're no longer playing catch-up, we can sleep for however long we need
	if( time_lag < SEC_PER_TICK )
	{
		std::this_thread::sleep_for( std::chrono::milliseconds( (int)( process_time*1000 )));
	} 

	time_lag = std::max( 0.0, time_lag-process_time ); // Take away the amount of time this process took

	// This will process the game, by passing a normalized value as a multiplier
	// Inside here is an if-else statement, and the result of the if-else statement is being divided by the max number of milliseconds per tick
	process( process_time/SEC_PER_TICK );

	if( !time_lag )
	{
		return &EngineFSM::render;
	}

	return &EngineFSM::process;
}

// EngineRender
EngineRender::EngineRender( int width, int height )
	: camera( 0, 0, width, height ),
	  background( 0.f, 0.33f, 0.4f, 1.f )
{}

EngineRender::~EngineRender() {}

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
	return camera.bounds.x;
}

int EngineRender::getWindowHeight()
{
	return camera.bounds.y;
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
	glTranslatef( camera.origin.x, camera.origin.y, -1.f );

	// Draw all atoms
	Atom::renderAtoms();

	// Displays what was just drawn to the screen
	glfwSwapBuffers( window );

	return &EngineFSM::poll;
}

// EngineStop
EngineStop::EngineStop() {}

EngineStop::~EngineStop() {}

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
