#include <algorithm>
#include <DrawComponent.h>
#include <chrono>
#include <iostream>

#include "GL/freeglut.h"

namespace MN {


	void DrawComponent::Init()
	{

	}

	void DrawComponent::Draw()
	{
		glClearColor(1, 1, 1, 0);
		glEnable(GL_LIGHTING);
		glLineWidth(1.0);
		glColor3f(0, 0, 0);
	}
}