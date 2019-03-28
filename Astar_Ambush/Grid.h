//
// C00204076
// Brandon Seah-Dempsey
// Started at 
// Finished at
// Time taken:
// Known bugs:

#ifndef GRID_H
#define GRID_H

#include <memory>
#include "Line.h"


//
class Grid
{
public:
	Grid(float width, float height);

	void calculateAdjacentSquares();
	void draw(SDL_Renderer* renderer);

private:
	float m_gridWidth, m_gridHeight;
};

#endif // !GRID_H
