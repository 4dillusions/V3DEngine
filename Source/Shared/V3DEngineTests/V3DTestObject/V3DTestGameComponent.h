/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DCore/V3DGameComponent.h"

namespace V3D::V3DEngineTests::V3DTestObject
{
	class V3DTestGameComponent final : public V3D::V3DEngine::V3DCore::V3DGameComponent
	{
	public:
		static double componentUpdate;

		V3DTestGameComponent();
		explicit V3DTestGameComponent(const char* name);
		
		void Update(double deltaTime) override;
	};
}
