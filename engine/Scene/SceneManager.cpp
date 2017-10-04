
#include "SceneManager.h"
#include <string>

namespace Engine
{
	SceneManager::SceneManager()
	{
		this->mActive = new Scene();
	}

	Scene* SceneManager::GetScene()
	{
		return this->mActive;
	}

	void SceneManager::SetScene(SCENES screen)
	{
		if(this->mActive != nullptr) delete this->mActive;
	}

	SceneManager* SceneManager::Instance()
	{
		if(!mInstance) mInstance = new SceneManager;

		return mInstance;
	}

	void SceneManager::Render()
	{
		this->mActive->Render();
	}

	bool SceneManager::Update(float deltaTime, SDL_Event e)
	{
		return this->mActive->Update(deltaTime, e);
	}
}