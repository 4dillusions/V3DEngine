/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DCryptography
{
	class V3DCryptographyMethodTests final
	{
	public:
		V3DCryptographyMethodTests() = delete;
		V3DCryptographyMethodTests(const V3DCryptographyMethodTests&) = delete;
		V3DCryptographyMethodTests(V3DCryptographyMethodTests&&) = delete;
		~V3DCryptographyMethodTests() = delete;
		V3DCryptographyMethodTests& operator=(const V3DCryptographyMethodTests&) = delete;
		V3DCryptographyMethodTests& operator=(V3DCryptographyMethodTests&&) = delete;

		static void HashMethodTest();
		
		static void RunAllTests();
	};
}
