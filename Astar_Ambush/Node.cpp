//
// C00204076
// Brandon Seah-Dempsey
// Started at 
// Finished at
// Time taken:
// Known bugs:

#include "Node.h"

Node::Node(Vector2 position, int id) :
	m_position(position),
	m_id(id)
{

}




// Get methods
//
Vector2 Node::getPosition()
{
	return m_position;
}

//
int Node::getID()
{
	return m_id;
}

//
bool Node::getBlocked()
{
	return m_blocked;
}

//
bool Node::getPlayer()
{
	return m_player;
}

//
bool Node::getGoal()
{
	return m_goal;
}

//
bool Node::getVisited()
{
	return m_visited;
}
//

// Set methods
//
void Node::setRGBA(int r, int g, int b, int a)
{
	m_square->setRGBA(r, g, b, a);
}

//
void Node::setPosition(Vector2 position)
{
	m_position = position;
}

//
void Node::setID(int id)
{
	m_id = id;
}

//
void Node::setBlocked(bool blocked)
{
	m_blocked = blocked;
}

//
void Node::setPlayer(bool player)
{
	m_player = player;
}

//
void Node::setGoal(bool goal)
{
	m_goal = goal;
}

//
void Node::setVisited(bool visited)
{
	m_visited = visited;
}
//