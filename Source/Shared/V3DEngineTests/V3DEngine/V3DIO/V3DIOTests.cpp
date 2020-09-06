/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DIOTests.h"

#include "V3DLoggerTest.h"
#include "V3DFileTest.h"
#include "V3DFolderTest.h"
#include "V3DTextRWTest.h"
#include "V3DBinaryRWTest.h"
#include "V3DJsonIOTest.h"
#include "V3DMemoryStreamTest.h"

namespace V3D::V3DEngineTests::V3DEngine::V3DIO
{	
	void V3DIOTests::RunAllTests()
	{
		V3DLoggerTest::RunAllTests();
		V3DFileTest::RunAllTests();
		V3DFolderTest::RunAllTests();
		V3DTextRWTest::RunAllTests();
		V3DBinaryRWTest::RunAllTests();
		V3DJsonIOTest::RunAllTests();
		V3DMemoryStreamTest::RunAllTests();
	}
}
