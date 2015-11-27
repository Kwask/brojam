#ifndef ENGINESTATES_H
#define ENGINESTATES_H

#include <vector>
#include <GLFW/glfw3.h>
#include "patterns/State.h"
#include "Atom.h"
#include "Coord.h"
#include "Creature.h"
#include "Planet.h"
#include "CommandHandler.h"

class EngineStart : public State
{
public:
	EngineStart();
	~EngineStart();
	
	State* handle();
};

class EnginePoll : public State
{
protected:
	CommandHandler handler;

public:
	EnginePoll();
	~EnginePoll();

	void keyboardInput( int key, int scancode, int action, int mods );

	State* handle();
};

class EngineProcess : public State
{
protected:
	const double FRAMES_PER_SECOND = 60.0;
	const double SEC_PER_TICK = 1.0/FRAMES_PER_SECOND;

	double archived_time = glfwGetTime();
	double time_lag = 0;

public:
	Creature* player;
	Planet* planet;

	EngineProcess();
	~EngineProcess();
	
	void process( double update_multiplier ); // Processes a single tick of the game

	State* handle();
};

class EngineRender : public State
{
protected:
	Rect camera;

	GLFWwindow* window = nullptr;

	std::vector<float> vertices;

	Color background;

public:
	EngineRender( int width, int height ); // Window width and height
	~EngineRender();

	void updateCamera();
	void setWindow( GLFWwindow* window );
	void destroyWindow();

	int getWindowWidth();
	int getWindowHeight();

	GLFWwindow* getWindow();

	State* handle();
};

class EngineStop : public State
{
public:
	EngineStop();
	~EngineStop();

	void cleanup();

	State* handle();
};

#endif
