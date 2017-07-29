#pragma once

#include <iostream>

#ifdef ENGINE_EXPORTS  
	#define ENGINE_API __declspec(dllexport)   
#else  
	#define ENGINE_API __declspec(dllimport)   
#endif

namespace Engine
{
	ENGINE_API bool Initialise();
	ENGINE_API void Deinitialise();

	ENGINE_API void Render();
	ENGINE_API bool Update();
}
