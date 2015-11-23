#ifndef ATOM_H
#define ATOM_H

#include <string>
#include <vector>
#include <GLFW/glfw3.h>
#include "Rect.h"

// Abstract class used as the base for all objects
class Atom
{
protected:
	static std::vector<Atom*> atoms;

	bool visible = true; // should this be drawn?

	int draw_mode = GL_TRIANGLE_FAN;

	std::string name;

	std::vector<float> vertices;

	Rect bounds; // Used for object placement + collision detection

public:
	static void renderAtoms();
	static void deleteAtoms();

	Atom();
	Atom( Rect& bnds );	
	~Atom();

	void render();
	void del();
	void removeAndDel();
};

#endif
