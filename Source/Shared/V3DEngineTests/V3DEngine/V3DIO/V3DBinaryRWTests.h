/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DIO
{
	class V3DBinaryRWTests final
	{
	public:
		V3DBinaryRWTests() = delete;
		V3DBinaryRWTests(const V3DBinaryRWTests&) = delete;
		V3DBinaryRWTests(V3DBinaryRWTests&&) = delete;
		~V3DBinaryRWTests() = delete;
		V3DBinaryRWTests& operator=(const V3DBinaryRWTests&) = delete;
		V3DBinaryRWTests& operator=(V3DBinaryRWTests&&) = delete;

		static void BinarySimpleRWTest();
		static void BinaryComplexRWTest();

		static void RunAllUnitTests();
		static void RegisterIntegrationTests();
		static void RegisterTimingTests();
	};
}
