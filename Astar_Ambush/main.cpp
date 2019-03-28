//
// C00204076
// Brandon Seah-Dempsey
// Started at 
// Finished at
// Time taken:
// Known bugs:

#pragma comment(lib,"SDL2.lib") 

#define SDL_MAIN_HANDLED

#include "Game.h"

int main(int argc, char* args[])
{
	Game *game = new Game();

	game->init("A* Ambush - Brandon Seah-Dempsey", 0, 0, 1000, 1000, false);

	game->run();

	return 0;
}