/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTestLayerPool.h"

namespace V3D::V3DEngineTests::V3DTestObject
{
	V3DTestLayerPool::V3DTestLayerPool(int size) : V3DGameCompositeComponentPool{ size }
	{ }
	
	V3DTestLayerPool::V3DTestLayerPool(const char* name, int size) : V3DGameCompositeComponentPool{ name, size }
	{ }
}
