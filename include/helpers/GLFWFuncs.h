#ifndef GLFWFUNC_H
#define GLFWFUNC_H

#include <GLFW/glfw3.h>
#include "Color.h"

void GLFWResize( GLFWwindow *window, int width, int height );

void glColor3f( Color& color );

#endif
