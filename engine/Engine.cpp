#include "Engine.h"

#include <SDL.h>

using namespace std;

namespace Engine
{
	SDL_Window* gWindow = nullptr;
	SDL_GLContext gGLContext = NULL;
	Uint32 gOldTime;

	bool Initialise()
	{
		printf("Game Engine Started.\n");

		if(SDL_Init(SDL_INIT_VIDEO) < 0) { printf("[Error] SDL didn't initialise. (Error: %s)", SDL_GetError()); return false; }

		// Attempt to set texture filtering to linear.
		if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) printf("*** [Warning] Linear texture filtering not available. ***\n");

		// Creating the game window.
		gWindow = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL); // SDL_FULLSCREEN SDL_RESIZABLE

		// Did the window get created?
		if(gWindow == NULL) { printf("[Error] We encountered a problem while creating game window was not created. (Error: %s)", SDL_GetError()); return false; }

		SDL_Delay(2000);

		return true;
	}

	void Deinitialise() {
		printf("Game Engine Stopping.\n");
		SDL_DestroyWindow(gWindow);
		SDL_Quit();
	}
	
	void Render() {}

	bool Update() {
		return false;
	}
}