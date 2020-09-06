/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/


#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DIO
{
	class V3DMemoryStreamTest final
	{
	public:
		V3DMemoryStreamTest() = delete;
		V3DMemoryStreamTest(const V3DMemoryStreamTest&) = delete;
		V3DMemoryStreamTest(V3DMemoryStreamTest&&) = delete;
		~V3DMemoryStreamTest() = delete;
		V3DMemoryStreamTest& operator=(const V3DMemoryStreamTest&) = delete;
		V3DMemoryStreamTest& operator=(V3DMemoryStreamTest&&) = delete;

		static void WriteReadArrayTest();
		static void WriteReadObjectTest();
		
		static void RunAllTests();
	};
}
