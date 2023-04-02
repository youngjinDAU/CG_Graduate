#pragma once
#include <map>
#include "pmp/SurfaceMesh.h"
namespace MN
{
	class DrawComponent
	{
	public:
		void Init();
		void Draw();
		int arrowNum0 = 0;
		int arrowNum1 = 0;
		pmp::SurfaceMesh mesh;

	};
}