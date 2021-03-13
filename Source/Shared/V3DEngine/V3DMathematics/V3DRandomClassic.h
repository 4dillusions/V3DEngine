/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DEngineLibrary.h"

namespace V3D::V3DEngine::V3DMathematics
{
	class V3DVector2D;

	class V3DENGINE_API V3DRandomClassic final
	{
		V3DRandomClassic();

	public:
		V3DRandomClassic(const V3DRandomClassic&) = delete;
		V3DRandomClassic(V3DRandomClassic&&) = delete;
		~V3DRandomClassic() = default;
		V3DRandomClassic& operator=(const V3DRandomClassic&) = delete;
		V3DRandomClassic& operator=(V3DRandomClassic&&) = delete;

	private:
		static float CreateRandom(float min, float max);

	public:
		static int CreateRandom(int min, int max);
		static V3DVector2D CreateRandom(const V3DVector2D& min, const V3DVector2D& max);
	};
}
