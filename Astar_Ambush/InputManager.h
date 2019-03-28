//
// C00204076
// Brandon Seah-Dempsey
// Started at 
// Finished at
// Time taken:
// Known bugs:

#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SDL.h>
#include <iostream>

//
class InputManager
{
public:
	InputManager();

	void update(float delatTime);

private:
	SDL_Event m_event;
	SDL_Keycode m_key;
};

#endif // !INPUTMANAGER_H