/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DRandomClassic.h"
#include "V3DVector2D.h"

#include <ctime>
#include <cstdlib>

namespace V3D::V3DEngine::V3DMathematics
{
	V3DRandomClassic::V3DRandomClassic()
	{
		srand(static_cast<unsigned int>(time(nullptr)));  // NOLINT
	}

	float V3DRandomClassic::CreateRandom(float min, float max)
	{
		[[maybe_unused]] static V3DRandomClassic random;

		return static_cast<float>((rand() % (static_cast<int>(++max) - static_cast<int>(min))) + static_cast<int>(min));  // NOLINT(concurrency-mt-unsafe)
	}
	
	int V3DRandomClassic::CreateRandom(int min, int max)
	{
		return static_cast<int>(CreateRandom(static_cast<float>(min), static_cast<float>(max)));
	}

	V3DVector2D V3DRandomClassic::CreateRandom(const V3DVector2D& min, const V3DVector2D& max)
	{
		return { CreateRandom(min.x, max.x), CreateRandom(min.y, max.y) };
	}
}
