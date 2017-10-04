#pragma once

#include <SDL.h>
#include <iostream>

#include "../Camera.h"

namespace Engine
{
	class Scene
	{
		public:
			Scene();
			virtual ~Scene();

			virtual void Render();
			virtual bool Update(float deltaTime, SDL_Event e);

		protected:
			Camera* mCamera;
			float mCurrentTime;
	};
}