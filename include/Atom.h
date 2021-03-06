#ifndef ATOM_H
#define ATOM_H

#include <string>
#include <vector>
#include <GLFW/glfw3.h>
#include "Rect.h"
#include "helpers/Color.h"

// Abstract class used as the base for all objects
class Atom
{
protected:
	static std::vector<Atom*> &atoms();

	bool visible = true; // should this be drawn?

	int draw_mode = GL_LINE_LOOP;

	float angle = 0; // 0 is facing right

	std::vector<float> vertices;

	Color color;
	
	Rect bounds; // Used for object placement + collision detection

	virtual void generateVertices(void) = 0;
	void initiliaze();

	Atom();

public:
	static void renderAtoms();
	static void deleteAtoms();

	Atom( Color& clr, Rect& bnds );	
	~Atom();

	virtual void render();
	virtual void del();
	virtual void removeAndDel();

	void setXPos( float x );
	void setYPos( float y );

	float getXPos();
	float getYPos();

	Coord getOrigin();
};

#endif
