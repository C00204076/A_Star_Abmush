//
// C00204076
// Brandon Seah-Dempsey
// Started at 
// Finished at
// Time taken:
// Known bugs:

#include "InputManager.h"

//
InputManager::InputManager()
{

}

//
void InputManager::update(float deltaTime)
{
	//
	while(SDL_PollEvent(&m_event))
	{
		//
		if (m_event.type == SDL_KEYDOWN)
		{
			//
			switch (m_event.key.keysym.sym)
			{
			case SDLK_SPACE:

				std::cout << "Space key pressed!" << std::endl;
				break;
			case SDLK_w:

				std::cout << "W key pressed!" << std::endl;
				break;
			case SDLK_a:

				std::cout << "A key pressed!" << std::endl;
				break;
			case SDLK_s:

				std::cout << "S key pressed!" << std::endl;
				break;
			case SDLK_d:

				std::cout << "D key pressed!" << std::endl;
				break;
			}
		}
	}
}
