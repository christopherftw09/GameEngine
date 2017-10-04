#pragma once

#include <SDL.h>
#include "Object.h"

namespace Engine
{
	class Camera: public Object
	{
		public:
			Camera();
			~Camera();

			void Render();
			bool Update(float deltaTime, SDL_Event e);

		private:
			bool updateCamera;
			bool orthographic;
	};
}