/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include <list>

namespace V3D::V3DEngine::V3DCore
{
	class V3DString;
}

namespace V3D::V3DEngineTests::V3DTestObject
{
	struct V3DTestUIControl
	{
		char name[20]{};
		int hierarchyCode{};
		int x{}, y{};

		std::list<V3DTestUIControl*> controls;

		V3DTestUIControl() = default;
		V3DTestUIControl(const V3DTestUIControl&) = delete;
		V3DTestUIControl(V3DTestUIControl&&) = delete;
		~V3DTestUIControl();
		V3DTestUIControl& operator=(const V3DTestUIControl&) = delete;
		V3DTestUIControl& operator=(V3DTestUIControl&&) = delete;
		
		void WriteToString(V3D::V3DEngine::V3DCore::V3DString& out);
	};
}
