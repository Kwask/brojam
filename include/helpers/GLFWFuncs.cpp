#include <GLFW/glfw3.h>
#include "GLFWFuncs.h"

void GLFWResize( GLFWwindow *window, int width, int height )
{
	glViewport( 0, 0, (GLsizei)width, (GLsizei)height );
	glMatrixMode( GL_PROJECTION );
	
	glLoadIdentity();
	
	glOrtho( 0, width, 0, height, 1.0f, 100.0f );
	glMatrixMode( GL_MODELVIEW );
}
