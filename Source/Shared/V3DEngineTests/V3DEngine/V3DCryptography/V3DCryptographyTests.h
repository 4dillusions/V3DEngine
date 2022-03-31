/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DCryptography
{
	class V3DCryptographyTests final
	{
	public:
		V3DCryptographyTests() = delete;
		V3DCryptographyTests(const V3DCryptographyTests&) = delete;
		V3DCryptographyTests(V3DCryptographyTests&&) = delete;
		~V3DCryptographyTests() = delete;
		V3DCryptographyTests& operator=(const V3DCryptographyTests&) = delete;
		V3DCryptographyTests& operator=(V3DCryptographyTests&&) = delete;

		static void RunAllTests();
	};
}
