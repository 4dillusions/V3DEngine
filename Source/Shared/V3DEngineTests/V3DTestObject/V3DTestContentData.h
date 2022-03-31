/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DTestObject
{
	struct V3DTestContentData
	{
		static constexpr int Size = 3 * 1024 * 1024; //3 Mb
		char bytes[Size]{};
	};
}
