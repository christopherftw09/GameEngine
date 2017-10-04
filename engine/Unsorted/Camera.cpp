
#include "Camera.h"
#include <iostream>

using namespace std;

namespace Engine
{
	Camera::Camera()
	{
		glEnable(GL_DEPTH_TEST); // This removes any surfaces that may be hiding away from the camera.
		glEnable(GL_CULL_FACE);	// This stops the calculations of any inside faces.
	}

	Camera::~Camera() {}

	void Camera::Render()
	{
		// First we will clear the screen before attepting to rerender the scene again.
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

		if(this->updateCamera)
		{
			glViewport(0, 0, 800, 600);

			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();

			if(this->orthographic) glOrtho(-5.0f, 5.0f, -5.0f, 5.0f, 0.3f, 1000.0f);
			else gluPerspective(90.0f, ((float)800/600), 0.3f, 1000.0f);

			this->updateCamera = false;
		}

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}

	bool Camera::Update(float deltaTime, SDL_Event e)
	{
		return true;
	}
}