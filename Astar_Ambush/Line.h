//
// C00204076
// Brandon Seah-Dempsey
// Started at 
// Finished at
// Time taken:
// Known bugs:

#ifndef LINE_H
#define LINE_H

#include "Primitive.h"

class Line : public Primitive
{
public:
	Line(Vector2 pointOne, Vector2 pointTwo)
	{
		m_pointOne = pointOne;
		m_pointTwo = pointTwo;
	}

	~Line() = default;

	void draw(SDL_Renderer* renderer) override
	{
		SDL_SetRenderDrawColor(renderer, m_red, m_green, m_blue, m_alpha);
		SDL_RenderDrawLine(renderer, m_pointOne.x, m_pointOne.y, m_pointTwo.x, m_pointTwo.y);
	}

	//Set methods
	//
	void setPointOne(Vector2 point)
	{
		m_pointOne = point;
	}
	//
	void setPointOne(float x, float y)
	{
		m_pointOne = Vector2(x, y);
	}

	//
	void setPointTwo(Vector2 point)
	{
		m_pointTwo = point;
	}
	//
	void setPointTwo(float x, float y)
	{
		m_pointTwo = Vector2(x, y);
	}
	//

private:
	Vector2 m_pointOne, m_pointTwo;

};

#endif // !LINE_H