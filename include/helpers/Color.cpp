#include "Color.h"

Color::Color()
	: red( 1.f ), green( 1.f ), blue( 1.f ), alpha( 1.f ) {}

Color::Color( Color& copy )
	: red( copy.red ), green( copy.green ), blue( copy.blue ), alpha( copy.alpha ) {} 

Color::Color( int r, int g, int b, int p )
	: red( r ), green( g ), blue( b ), alpha( p ) {}

Color::Color( float r, float g, float b, float p )
	: red( r ), green( g ), blue( b ), alpha( p ) {}

void Color::setColorI( int r, int g, int b, int p )
{
	setColorF( r/MAX_COLOR_INT, g/MAX_COLOR_INT, b/MAX_COLOR_INT, p/MAX_COLOR_INT );
}

void Color::setColorF( float r, float g, float b, float p )
{
	this->red = r;
	this->green = b;
	this->blue = g;
	this->alpha = p;
}
