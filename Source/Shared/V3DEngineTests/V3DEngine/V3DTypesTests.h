/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine
{
	class V3DTypesTests final
	{
	public:
		V3DTypesTests() = delete;
		V3DTypesTests(const V3DTypesTests&) = delete;
		V3DTypesTests(V3DTypesTests&&) = delete;
		~V3DTypesTests() = delete;
		V3DTypesTests& operator=(const V3DTypesTests&) = delete;
		V3DTypesTests& operator=(V3DTypesTests&&) = delete;

		static void RunAllTests();
	};
}
