#ifndef COLOR_H
#define COLOR_H

struct Color
{
	const float MAX_COLOR_INT = 255.f;

	float red = 1.f;
	float green = 1.f;
	float blue = 1.f;
	float alpha = 1.f;

	Color();
	Color( Color& copy );
	Color( int r, int g, int b, int p = 255 );
	Color( float r, float g, float b, float p = 1.f );

	void setColorI( int r, int g, int b, int p = 255 );
	void setColorF( float r, float g, float b, float p = 1.f );

};

#endif
