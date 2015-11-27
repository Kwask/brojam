#include <GLFW/glfw3.h>
#include "GLFWFuncs.h"
#include "Color.h"

void GLFWResize( GLFWwindow *window, int width, int height )
{
	glViewport( 0, 0, (GLsizei)width, (GLsizei)height );
	glMatrixMode( GL_PROJECTION );
	
	glLoadIdentity();
	
	glOrtho( -width/2, width/2, -height/2, height/2, 1.0f, 100.0f );
	glMatrixMode( GL_MODELVIEW );
}

void glColor3f( Color& color )
{
	glColor3f( color.red, color.green, color.blue );
}

