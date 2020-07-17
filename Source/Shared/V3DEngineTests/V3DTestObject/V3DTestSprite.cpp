/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTestSprite.h"

namespace V3D::V3DEngineTests::V3DTestObject
{
	double V3DTestSprite::componentUpdate = 0;
	
	V3DTestSprite::V3DTestSprite() : V3DGameComponent()
	{ }
	
	V3DTestSprite::V3DTestSprite(const char* name) : V3DGameComponent{ name }
	{ }
	
	void V3DTestSprite::Update(double deltaTime)
	{
		componentUpdate += deltaTime;
	}
}
