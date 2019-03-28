//
// C00204076
// Brandon Seah-Dempsey
// Started at 
// Finished at
// Time taken:
// Known bugs:

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Primitive.h"

class Circle : public Primitive
{
public:
	Circle(float radius) :
		m_radius(radius)
	{
		m_diameter = m_radius * 2;
	}

	~Circle() = default;

	//
	void draw(SDL_Renderer* renderer) override
	{
		SDL_SetRenderDrawColor(renderer, m_red, m_green, m_blue, m_alpha);

		for (int h = 0; h < m_diameter; h++)
		{
			for (int w = 0; w < m_diameter; w++)
			{
				float dx = m_radius - h, dy = m_radius - w;
				if ((dx * dx) + (dy * dy) <= (m_radius * m_radius))
				{
					SDL_RenderDrawPoint(renderer, m_position.x + dx, m_position.y + dy);
				}
			}
		}
		
	}

	// Get method
	float getRadius()
	{
		return m_radius;
	}

	// Set method
	void setRadiusAndDiameter(float radius)
	{
		m_radius = radius;
		m_diameter = radius * 2;
	}

private:
	float m_radius, m_diameter;

};

#endif // !CIRCLE_H
