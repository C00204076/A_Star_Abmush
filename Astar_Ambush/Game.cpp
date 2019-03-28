//
// C00204076
// Brandon Seah-Dempsey
// Started at 
// Finished at
// Time taken:
// Known bugs:

#include "Game.h"

//
Game::Game() :
	m_fps(1.0),
	m_window(NULL),
	m_surface(NULL),
	m_isRunning(false)
{
	m_inputManager = new InputManager();
}

//
Game::~Game()
{

}

//
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen)
{
	int flags = 0;

	if (fullScreen == true)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	//
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		m_window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		m_renderer = SDL_CreateRenderer(m_window, -1, 0);
		if (m_renderer)
		{
			SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
		}


		m_isRunning = true;
	}

	//
	else
	{
		m_isRunning = false;
	}
}

//
void Game::loadFiles()
{

}

//
void Game::processEvents(SDL_Event& e)
{
	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
		{
			m_isRunning = false;
		}

		if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_ESCAPE)
			{
				m_isRunning = false;
			}
		}
	}
}

//
void Game::run()
{
	SDL_Event e;
	double deltaTime = 0, frameTime = 0;
	int frames = 0, counter = 0;
	auto current = std::chrono::system_clock::now(), previous = std::chrono::system_clock::now();

	//
	while (m_isRunning == true)
	{
		current = std::chrono::system_clock::now();
		deltaTime = std::chrono::duration<double>(current - previous).count();
		frameTime += deltaTime;
		counter += deltaTime;

		update(deltaTime);

		if (frameTime >= m_fps)
		{
			processEvents(e);

			draw();

			frameTime -= m_fps;
		}

		frames++;

		// If one second has passed
		if (counter >= 1.0f)
		{
			counter -= 1; // Removes 1 second
			std::cout << "Frames per second: " << frames << "\n";
			frames = 0; // Reset frames
		}

		previous = current;
	}

	//
	//close();
}

//
void Game::update(double deltaTime)
{
	m_inputManager->update(deltaTime);
}

//
void Game::draw()
{
	SDL_RenderClear(m_renderer);



	SDL_RenderPresent(m_renderer);
}

//
void Game::close()
{
	//Destroy window
	SDL_DestroyWindow(m_window);

	m_window = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}