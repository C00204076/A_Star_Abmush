//
// C00204076
// Brandon Seah-Dempsey
// Started at 
// Finished at
// Time taken:
// Known bugs:

#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <SDL.h>
#include "Vector2.h"

//
class Primitive
{
public:
	Primitive() :
		m_red(0),
		m_green(0),
		m_blue(0),
		m_alpha(255)
	{

	}

	~Primitive() = default;

	virtual void draw(SDL_Renderer* renderer) = 0;

	// Get methods
	//
	int getRed()
	{
		return m_red;
	}
	//
	int getGreen()
	{
		return m_green;
	}
	//
	int getBlue()
	{
		return m_blue;
	}
	//
	int getAplha()
	{
		return m_alpha;
	}
	//
	const Vector2& getPosition()
	{
		return m_position;
	}
	//
	const Vector2& getOrigin()
	{
		return m_origin;
	}
	//

	// Set methods
	//
	void setRGBA(int r, int g, int b, int a)
	{
		m_red = r;
		m_green = g;
		m_blue = b; 
		m_alpha = a;
	}

	//
	void setPosition(Vector2 position)
	{
		m_position = position;
	}
	//
	void setPosition(float x, float y)
	{
		m_position = Vector2(x, y);
	}

	//
	void setOrigin(Vector2 origin)
	{
		m_origin = origin;
	}
	//
	void setOrigin(float x, float y)
	{
		m_origin = Vector2(x, y);
	}

	//


protected:
	int m_red, m_green, m_blue, m_alpha;
	Vector2 m_position = Vector2(0.0f, 0.0f);
	Vector2 m_origin = Vector2(0.0f, 0.0f); 
};


#endif // !PRIMITIVE_H

