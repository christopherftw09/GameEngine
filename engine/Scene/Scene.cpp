
#include "Scene.h"
#include <string>

namespace Engine
{
	Scene::Scene()
	{
		this->mCamera = new Camera();
		//this->mCamera->SetPosition(Vector3(0.0, 0.0f, -10.0f)); // setting a default camera position.
	}

	Scene::~Scene()
	{
		delete this->mCamera; // cleaning up the main scene camera.
	}

	void Scene::Render()
	{
		this->mCamera->Render();
	}

	bool Scene::Update(float deltaTime, SDL_Event e)
	{
		this->mCamera->Update(deltaTime, e);
		return false;
	}
}