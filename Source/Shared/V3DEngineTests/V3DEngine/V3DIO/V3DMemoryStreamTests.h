/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/


#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DIO
{
	class V3DMemoryStreamTests final
	{
	public:
		V3DMemoryStreamTests() = delete;
		V3DMemoryStreamTests(const V3DMemoryStreamTests&) = delete;
		V3DMemoryStreamTests(V3DMemoryStreamTests&&) = delete;
		~V3DMemoryStreamTests() = delete;
		V3DMemoryStreamTests& operator=(const V3DMemoryStreamTests&) = delete;
		V3DMemoryStreamTests& operator=(V3DMemoryStreamTests&&) = delete;

		static void WriteReadArrayTest();
		static void WriteReadObjectTest();
		static void WriteReadObjectToFileTest();
		
		static void RunAllTests();
	};
}
