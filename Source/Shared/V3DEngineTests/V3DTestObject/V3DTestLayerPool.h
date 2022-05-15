/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DCore/V3DGameCompositeComponentPool.h"
#include "V3DTestSprite.h"

namespace V3D::V3DEngineTests::V3DTestObject
{
	class V3DTestLayerPool final : public V3D::V3DEngine::V3DCore::V3DGameCompositeComponentPool<V3DTestSprite>  // NOLINT(clang-diagnostic-weak-vtables)
	{
	public:
		explicit V3DTestLayerPool(int size);
		explicit V3DTestLayerPool(const char* name, int size);
	};
}
