#ifndef ENGINESTATES_H
#define ENGINESTATES_H

#include <vector>
#include <GLFW/glfw3.h>
#include "patterns/State.h"
#include "Atom.h"
#include "Coord.h"

class EngineStart : public State
{
public:
	~EngineStart();
	
	void cleanup();
	
	State* handle();
};

class EngineProcess : public State
{
public:
	~EngineProcess();
	
	void cleanup();
	void addToContents( Atom* atom );
	void removeFromContents( Atom* atom );

	State* handle();
};

class EnginePoll : public State
{
public:
	~EnginePoll();

	void cleanup();
	void rakHandleNetwork();

	State* handle();
};

class EngineRender : public State
{
private:
	Coord dimensions;

	GLFWwindow* window = nullptr;

	std::vector<float> vertices;

public:
	EngineRender( int width, int height ); // Window width and height
	~EngineRender();

	void cleanup();
	void populateVerticeVector();
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
	~EngineStop();

	void cleanup();

	State* handle();
};

#endif
