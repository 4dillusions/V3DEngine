/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include <list>

#include "ThirdParty/Json/json_fwd.hpp"

namespace V3D::V3DEngine::V3DCore
{
	class V3DString;
}

namespace V3D::V3DEngineTests::V3DTestObject
{
	struct V3DTestJSonUIControl
	{
		char name[20]{};
		int hierarchyCode{};
		int x{}, y{};

		std::list<V3DTestJSonUIControl*> controls;

		~V3DTestJSonUIControl();
		void Load(const nlohmann::json& jsonObj, int hierarchyNum = 0);
		void WriteToString(V3D::V3DEngine::V3DCore::V3DString& out);
	};
}
