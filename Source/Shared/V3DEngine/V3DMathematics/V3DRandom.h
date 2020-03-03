/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DEngineLibrary.h"
#include <random>

namespace V3D::V3DEngine::V3DMathematics
{
	class V3DVector2D;

	class V3DENGINE_API V3DRandom final
	{
		static std::random_device entropySource;
		static std::mt19937 randGenerator;
		
		V3DRandom() = default;

	public:
		V3DRandom(const V3DRandom&) = delete;
		V3DRandom(V3DRandom&&) = delete;
		V3DRandom& operator=(const V3DRandom&) = delete;
		V3DRandom& operator=(V3DRandom&&) = delete;

	private:
		~V3DRandom() = default;

	public:
		static int CreateRandom(int min, int max);
		static V3DVector2D CreateRandom(const V3DVector2D& min, const V3DVector2D& max);
	};
}
