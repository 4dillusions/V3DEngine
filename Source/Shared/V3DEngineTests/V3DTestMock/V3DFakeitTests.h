/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DTestMock
{
	class V3DFakeitTests final
	{
	public:
		V3DFakeitTests() = delete;
		V3DFakeitTests(const V3DFakeitTests&) = delete;
		V3DFakeitTests(V3DFakeitTests&&) = delete;
		~V3DFakeitTests() = delete;
		V3DFakeitTests& operator=(const V3DFakeitTests&) = delete;
		V3DFakeitTests& operator=(V3DFakeitTests&&) = delete;

		static void RunAllUnitTests();
		static void RegisterIntegrationTests();
		static void RegisterTimingTests();
	};
}
