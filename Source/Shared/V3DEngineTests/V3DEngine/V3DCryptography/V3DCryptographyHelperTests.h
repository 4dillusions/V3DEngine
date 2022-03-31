/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DCryptography
{
	class V3DCryptographyHelperTests final
	{
	public:
		V3DCryptographyHelperTests() = delete;
		V3DCryptographyHelperTests(const V3DCryptographyHelperTests&) = delete;
		V3DCryptographyHelperTests(V3DCryptographyHelperTests&&) = delete;
		~V3DCryptographyHelperTests() = delete;
		V3DCryptographyHelperTests& operator=(const V3DCryptographyHelperTests&) = delete;
		V3DCryptographyHelperTests& operator=(V3DCryptographyHelperTests&&) = delete;

		static void ConvertHexArrayToStringTest();
		
		static void RunAllTests();
	};
}
