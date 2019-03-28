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
#include "Node.h"


//
class Grid
{
public:
	Grid(float width, float height);

	void checkAdjacentSquares();
	void draw(SDL_Renderer* renderer);

	// Get methods
	std::vector<std::shared_ptr<Node>> getNodes();
	std::vector<std::shared_ptr<Line>> getLines();
	int getGridSize();
	int getGridWidth();
	int getGridHeight();
	//
	
	// Set methods
	void setGridSize(int gridsize);
	void setGridWidth(float gridwidth);
	void setGridHeight(float gridheight);
	//

private:
	std::vector<std::shared_ptr<Node>> m_nodes;
	std::vector<std::shared_ptr<Line>> m_lines;
	float m_gridWidth, m_gridHeight;
	int m_gridSize;
};

#endif // !GRID_H
