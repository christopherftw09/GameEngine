#include "Engine.h"

#include <SDL.h>
#include <glew.h>
#include <SDL_opengl.h>
#include <gl\glu.h>

#include "Scene\SceneManager.h"

using namespace std;

namespace Engine
{
	SDL_Window* gWindow = nullptr;
	SDL_GLContext gGLContext = NULL;
	Uint32 gOldTime;

	SceneManager* SceneManager::mInstance = nullptr;

	bool Initialise()
	{
		if(SDL_Init(SDL_INIT_VIDEO) < 0) { printf("[Error] SDL didn't initialise. (Error: %s)", SDL_GetError()); return false; }

		// Attempt to set texture filtering to linear.
		if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) printf("*** [Warning] Linear texture filtering not available. ***\n");

		// Requesting OpenGL's 3.1 context. (3.2)
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

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

		if(glewError != GLEW_OK) { printf("We encountered a problem while initialising GLEW! (Error: %s)\n", glewGetErrorString(glewError)); return false; }

		//printf("*** You are using OpenGL version: %s. ***\n\n", glGetString(GL_VERSION));

		gOldTime = SDL_GetTicks();

		printf("Game Engine Started.\n");
		return true;
	}

	void Deinitialise()
	{
		SDL_DestroyWindow(gWindow);
		gWindow = nullptr;

		SDL_Quit();
		printf("Game Engine Stopped.\n");
	}
	
	void Render()
	{
		// run the screen manager's render function.
		SceneManager::Instance()->Render();

		// Updating the OpenGL renderer.
		SDL_GL_SwapWindow(gWindow);
	}

	bool Update()
	{
		// Getting and setting the new time.
		Uint32 newTime = SDL_GetTicks();

		// Event Handler.
		SDL_Event e;

		// Get the events.
		SDL_PollEvent(&e);

		// Handle any upcoming events.
		switch(e.type)
		{
			// What happens if the user clicks the windows close (red cross) button.
			case SDL_QUIT:
				return false;

			default:
				SceneManager::Instance()->Update((float)(newTime - gOldTime) / 1000.0f, e);
			break;
		}

		// Set the current time to be the old time.
		gOldTime = newTime;
		return true;
	}
}