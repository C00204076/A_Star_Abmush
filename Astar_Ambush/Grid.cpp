//
// C00204076
// Brandon Seah-Dempsey
// Started at 
// Finished at
// Time taken:
// Known bugs:

#include "Grid.h"

Grid::Grid(float width, float height) 
{
	float totalCells = width * height, nodeSizeX = 1000 / width, nodeSizeY = 1000 / height;

	//
	int currentid = 0;
	//
	for (int i = 0; i < height * nodeSizeX; i += nodeSizeX) //col
	{
		for (int j = 0; j < width * nodeSizeY; j += nodeSizeY) //row
		{
			m_nodes.push_back(std::make_shared<Node>(Vector2(i, j), Vector2(nodeSizeX, nodeSizeY), currentid));
			currentid++;
		}
	}
	//
	for (int i = nodeSizeX; i < width * nodeSizeX; i += nodeSizeX) //col
	{
		m_lines.push_back(std::make_unique<Line>(Vector2(i, 0), Vector2(i, 1000)));
	}
	//
	for (int i = nodeSizeY; i < height * nodeSizeY; i += nodeSizeY) //col
	{
		m_lines.push_back(std::make_unique<Line>(Vector2(0, i), Vector2(1000, i)));
	}
	//
	m_gridSize = totalCells;
	checkAdjacentSquares();
}

//
void Grid::checkAdjacentSquares() 
{
	for (int i = 0; i < m_nodes.size(); i++)
	{
		auto& currentNode = m_nodes.at(i);
		currentNode->m_adjacentSet.clear();
		auto currentID = currentNode->getID();

		// Top cell check
		if (currentID != 0 && !m_nodes.at(currentID - 1)->getBlocked() && m_nodes.at(currentID - 1)->getPosition().y < currentNode->getPosition().y)
		{
			currentNode->m_adjacentSet.push_back(m_nodes.at(currentID - 1));
		}
		// Bottom cell check
		if (currentID != (m_gridSize - 1) && !m_nodes.at(currentID + 1)->getBlocked() && m_nodes.at(currentID + 1)->getPosition().y > currentNode->getPosition().y)
		{
			currentNode->m_adjacentSet.push_back(m_nodes.at(currentID - 1));
		}
		// Right cell check
		if ((currentID < m_gridSize - m_gridHeight) && (!m_nodes.at(currentID + m_gridHeight)->getBlocked()))
		{
			currentNode->m_adjacentSet.push_back(m_nodes.at(currentID + m_gridHeight));
		}
		// Left cell check
		if (currentID - m_gridHeight >= 0 && !m_nodes.at(currentID - m_gridHeight)->getBlocked())
		{
			currentNode->m_adjacentSet.push_back(m_nodes.at(currentID - m_gridHeight));
		}
	}
}

//
void Grid::draw(SDL_Renderer* renderer) 
{
	//
	for (auto& node : m_nodes)
	{
		node->draw(renderer);
	}
	//
	for (auto& line : m_lines)
	{
		line->draw(renderer);
	}
}

// Get methods
//
std::vector<std::shared_ptr<Node>> Grid::getNodes()
{
	return m_nodes;
}

//
std::vector<std::shared_ptr<Line>> Grid::getLines()
{
	return m_lines;
}

//
int Grid::getGridSize()
{
	return m_gridSize;
}

//
int Grid::getGridWidth()
{
	return m_gridWidth;
}

//
int Grid::getGridHeight()
{
	return m_gridHeight;
}
//

// Set methods
//
void Grid::setGridSize(int gridsize)
{
	m_gridSize = gridsize;
}

//
void Grid::setGridWidth(float gridwidth)
{
	m_gridWidth = gridwidth;
}

//
void Grid::setGridHeight(float gridheight)
{
	m_gridHeight = gridheight;
}
//