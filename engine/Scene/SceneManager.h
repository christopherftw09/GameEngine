#pragma once

#include "Scene.h"

using namespace std;

namespace Engine
{
	enum SCENES { DEFAULT };

	class SceneManager
	{
		private:
			Scene* mActive = nullptr;
			static SceneManager* mInstance;

			SceneManager();

		public:
			static SceneManager* Instance();

			void SetScene(SCENES screen);
			Scene* GetScene();

			void Render();
			bool Update(float deltaTime, SDL_Event e);
	};
}