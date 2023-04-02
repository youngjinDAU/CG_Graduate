#include <algorithm>
#include <DrawComponent.h>
#include <chrono>
#include <iostream>

#include "GL/freeglut.h"
#include <pmp/io/io.h>

namespace MN {


	void DrawComponent::Init()
	{
		pmp::read(mesh, "models\\bunny_stanford.obj");

		printf("face : %lld\n", mesh.n_faces());
		printf("vertex : %lld\n", mesh.n_vertices());
		printf("edge : %lld\n", mesh.n_vertices());
	}

	void DrawComponent::Draw()
	{
		glClearColor(1, 1, 1, 0);
		glEnable(GL_LIGHTING);
		glLineWidth(1.0);
		glColor3f(0, 0, 0);
	}
}