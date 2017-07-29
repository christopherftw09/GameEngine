#include "Engine.h"

#include <SDL.h>
#include <glew.h>
#include <SDL_opengl.h>
#include <gl\glu.h>

using namespace std;

namespace Engine
{
	SDL_Window* gWindow = nullptr;
	SDL_GLContext gGLContext = NULL;
	Uint32 gOldTime;

	bool Initialise()
	{
		if(SDL_Init(SDL_INIT_VIDEO) < 0) { printf("[Error] SDL didn't initialise. (Error: %s)", SDL_GetError()); return false; }

		// Attempt to set texture filtering to linear.
		if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) printf("*** [Warning] Linear texture filtering not available. ***\n");

		// Creating the game window.
		gWindow = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL); // SDL_FULLSCREEN SDL_RESIZABLE

		// Did the window get created?
		if(gWindow == NULL) { printf("[Error] We encountered a problem while creating game window was not created. (Error: %s)", SDL_GetError()); return false; }

		gGLContext = SDL_GL_CreateContext(gWindow);

		// Did we setup the OpenGL context.
		if(gGLContext == NULL) { printf("We encountered a problem while creating the OpenGL context. (Error: %s).", SDL_GetError()); return false; }

		// Initializing GLEW
		glewExperimental = GL_TRUE;
		GLenum glewError = glewInit();

		if(glewError != GLEW_OK) { printf("We encountered a problem while initializing GLEW! (Error: %s)\n", glewGetErrorString(glewError)); return false; }

		//printf("*** You are using OpenGL version: %s. ***\n\n", glGetString(GL_VERSION));

		printf("Game Engine Started.\n");
		return true;
	}

	void Deinitialise() {
		SDL_DestroyWindow(gWindow);
		SDL_Quit();
		printf("Game Engine Stopped.\n");
	}
	
	void Render() {
		printf("Render.\n");
	}

	bool Update() {
		printf("Update.\n");
		return false;
	}
}