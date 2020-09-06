/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DIO
{
	class V3DBinaryRWTest final
	{
	public:
		V3DBinaryRWTest() = delete;
		V3DBinaryRWTest(const V3DBinaryRWTest&) = delete;
		V3DBinaryRWTest(V3DBinaryRWTest&&) = delete;
		~V3DBinaryRWTest() = delete;
		V3DBinaryRWTest& operator=(const V3DBinaryRWTest&) = delete;
		V3DBinaryRWTest& operator=(V3DBinaryRWTest&&) = delete;

		static void BinarySimpleRWTest();
		static void BinaryComplexRWTest();
		static void BinaryComplexRWMemoryStreamTest();

		static void RunAllTests();
	};
}
