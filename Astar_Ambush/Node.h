//
// C00204076
// Brandon Seah-Dempsey
// Started at 
// Finished at
// Time taken:
// Known bugs:

#ifndef NODE_H
#define NODE_H


#include "Vector2.h"
#include "Square.h"

//
class Node
{
public:
	Node(Vector2 position, Vector2 size, int id);


	void draw(SDL_Renderer* renderer);

	//
	Vector2 getPosition();
	int getID();
	bool getBlocked();
	bool getPlayer();
	bool getGoal();
	bool getVisited();
	//

	//
	void setRGBA(int r, int g, int b, int a);
	void setPosition(Vector2 position);
	void setID(int id);
	void setBlocked(bool blocked);
	void setPlayer(bool player);
	void setGoal(bool goal);
	void setVisited(bool visited);
	//

	std::vector<std::shared_ptr<Node>> m_adjacentSet;

private:
	Vector2 m_position;
	std::unique_ptr<Square> m_square;
	int m_id;
	bool m_blocked, m_player, m_goal, m_visited;
	
};

#endif // !NODE_H
