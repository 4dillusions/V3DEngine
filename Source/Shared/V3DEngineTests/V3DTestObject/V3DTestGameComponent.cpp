/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTestGameComponent.h"

namespace V3D::V3DEngineTests::V3DTestObject
{
	double V3DTestGameComponent::componentUpdate = 0;

	V3DTestGameComponent::V3DTestGameComponent() : V3DTestGameComponent(nullptr)
	{ }

	V3DTestGameComponent::V3DTestGameComponent(const char* name) : V3DGameComponent(name)
	{ }
	
	void V3DTestGameComponent::Update(double deltaTime)
	{
		componentUpdate += deltaTime;
	}
}
