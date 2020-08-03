/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DTestObject
{
	struct V3DTestBinaryDataHead final
	{
		const int verticeCount{};
		const int uvCount{};

		V3DTestBinaryDataHead(int verticeCount, int uvCount) : verticeCount{verticeCount}, uvCount{uvCount}
		{ }
	};
}
