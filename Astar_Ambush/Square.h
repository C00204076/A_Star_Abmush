//
// C00204076
// Brandon Seah-Dempsey
// Started at 
// Finished at
// Time taken:
// Known bugs:

#ifndef SQUARE_H
#define SQUARE_H

#include "Primitive.h"
#include "Line.h"

#include <vector>
#include <memory>

class Square : public Primitive
{
public:
	Square()
	{
		m_active = true;
	}

	~Square() = default;

	void draw(SDL_Renderer* renderer) override
	{
		SDL_Rect fill = { m_position.x - m_origin.x, m_position.y - m_origin.y, m_size.x, m_size.x };
		SDL_SetRenderDrawColor(renderer, m_red, m_green, m_blue, m_alpha);
		SDL_RenderFillRect(renderer, &fill);

		//
		for (auto & line : m_lines)
		{
			line->draw(renderer);
		}
	}

	//Set methods
	//
	void setSize(Vector2 size)
	{
		if (m_active == true)
		{
			m_size = size;
			setBoundaryLines();
		}
	}

	//
	void setSize(float width, float height)
	{
		if (m_active == true)
		{
			m_size = Vector2(width, height);
			setBoundaryLines();
		}
	}

	//
	void setPosition(Vector2 position)
	{
		if (m_active == true)
		{
			m_position = position;
			setBoundaryLines();
		}
	}

	//
	void setPosition(float x, float y)
	{
		if (m_active == true)
		{
			m_position = Vector2(x, y);
			setBoundaryLines();
		}
	}
	//

	//Get methods
	Vector2 getSize()
	{
		return m_size;
	}
	//

private:
	Vector2 m_size = Vector2(25, 25);
	std::vector<std::unique_ptr<Line>> m_lines;
	bool m_active = true;

	//
	void setBoundaryLines()
	{
		m_lines.clear();
		// Top left corner to bottom left corner
		m_lines.push_back( std::make_unique<Line>( Line( Vector2(m_position.x, m_position.y), Vector2(m_position.x, m_position.y + m_size.y) ) ) );
		// Top left corner to top right corner
		m_lines.push_back( std::make_unique<Line>( Line( Vector2(m_position.x, m_position.y), Vector2(m_position.x + m_size.x, m_position.y) ) ) );
		// Bottom left corner to bottom right corner
		m_lines.push_back( std::make_unique<Line>( Line( Vector2(m_position.x, m_position.y + m_size.y), Vector2(m_position.x + m_size.x, m_position.y + m_size.y) ) ) );
		// Top right corner to  to bottom right corner
		m_lines.push_back( std::make_unique<Line>( Line( Vector2(m_position.x + m_size.x, m_position.y), Vector2(m_position.x + m_size.x, m_position.y + m_size.y) ) ) );
	}

};

#endif // !SQUARE_H
