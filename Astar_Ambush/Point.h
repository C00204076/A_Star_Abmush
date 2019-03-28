//
// C00204076
// Brandon Seah-Dempsey
// Started at 
// Finished at
// Time taken:
// Known bugs:

#ifndef POINT_H
#define POINT_H

#include "Primitive.h"

class Point : public Primitive
{
public:
	Point(float x, float y)
	{
		m_position = Vector2(x, y);
	}

	~Point() = default;

	void draw(SDL_Renderer* renderer) override
	{
		SDL_SetRenderDrawColor(renderer, m_red, m_green, m_blue, m_alpha);
		SDL_RenderDrawPoint(renderer, m_position.x, m_position.y);
	}

};

#endif // !POINT_H
