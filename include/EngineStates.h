#ifndef ENGINESTATES_H
#define ENGINESTATES_H

#include <vector>
#include <GLFW/glfw3.h>
#include "patterns/State.h"

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
	
	State* handle();
};

class EnginePoll : public State
{
public:
	~EnginePoll();

	void cleanup();
	
	State* handle();
};

class EngineRender : public State
{
private:
	std::vector<float> vertices;

public:
	int window_width = 800;
	int window_height = 600;

	GLFWwindow* window = nullptr;

	~EngineRender();

	void cleanup();
	void populateVerticeVector();

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
