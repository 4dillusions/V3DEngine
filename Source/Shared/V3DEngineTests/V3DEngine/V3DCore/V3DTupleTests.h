/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	class V3DTupleTests final
	{
	public:
		V3DTupleTests() = delete;
		V3DTupleTests(const V3DTupleTests&) = delete;
		V3DTupleTests(V3DTupleTests&&) = delete;
		~V3DTupleTests() = delete;
		V3DTupleTests& operator=(const V3DTupleTests&) = delete;
		V3DTupleTests& operator=(V3DTupleTests&&) = delete;

		static void TupleTest();
		
		static void RunAllUnitTests();
		static void RegisterIntegrationTests();
		static void RegisterTimingTests();
	};
}
