/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTestLayer.h"

namespace V3D::V3DEngineTests::V3DTestObject
{
	V3DTestLayer::V3DTestLayer() : V3DGameCompositeComponent()
	{ }
	
	V3DTestLayer::V3DTestLayer(const char* name) : V3DGameCompositeComponent { name }
	{ }
}
