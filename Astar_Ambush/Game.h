//
// C00204076
// Brandon Seah-Dempsey
// Started at 
// Finished at
// Time taken:
// Known bugs:

#ifndef GAME_H
#define GAME_H

#include "Primitive.h"
#include "Vector2.h"
#include "Circle.h"
#include "Line.h"
#include "Point.h"
#include "Square.h"
#include "Node.h"
#include "Grid.h"
#include "PathFinding.h"
#include "InputManager.h"

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <iostream>
#include <chrono>


//
class Game
{
public:
	Game();
	~Game();

	//
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen);
	void loadFiles();

	//
	void processEvents(SDL_Event& e);
	void run();
	void update(double deltaTime);
	void draw();
	void close();

private:
	//
	InputManager* m_inputManager;
	std::shared_ptr<Grid> m_grid;


	//
	SDL_Window* m_window;
	//
	SDL_Surface* m_surface;
	//
	SDL_Renderer* m_renderer;
	//
	bool m_isRunning;
	//
	float m_fps;
};

#endif // !GAME_H