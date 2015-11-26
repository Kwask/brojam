#ifndef GLFWINPUT_H
#define GLFWINPUT_H

#include <GLFW/glfw3.h>

static void keyCallback( GLFWwindow* window, int key, int scancode, int action, int mods )
{
	EngineFSM::poll.keyboardInput( key, scancode, action, mods );
}

#endif

