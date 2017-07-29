//
// Game
//

#include "Engine.h"

using namespace std;
using namespace Engine;

int main(int argc, char* args[])
{
	if(Initialise())
	{
		bool running = true;

		do // the game loop.
		{
			Render();
			running = Update();
		}
		while(running);
	}

	Deinitialise(); // closing the game window and then freeing up any used resources (i'm recycling :D).
	return 0;
}
