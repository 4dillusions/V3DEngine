/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include <functional>

namespace V3D::V3DEngineTests
{
	struct V3DTimingTestData
	{
		std::function<void()> func;
		bool isKip{ false };
		int orderIndex{ 0 };
	};
}
