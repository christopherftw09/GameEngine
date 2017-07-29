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
		do // the game loop.
		{
			Render();
		}
		while(Update());
	}

	Deinitialise(); // closing the game window and then freeing up any used resources (i'm recycling :D).
	return 0;
}
