/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DIOTests.h"

#include "V3DLoggerTests.h"
#include "V3DFileTests.h"
#include "V3DFolderTests.h"
#include "V3DTextRWTests.h"
#include "V3DBinaryRWTests.h"
#include "V3DJsonIOTests.h"
#include "V3DMemoryStreamTests.h"
#include "V3DSQLiteTests.h"

namespace V3D::V3DEngineTests::V3DEngine::V3DIO
{	
	void V3DIOTests::RunAllTests()
	{
		V3DLoggerTests::RunAllTests();
		V3DFileTests::RunAllTests();
		V3DFolderTests::RunAllTests();
		V3DTextRWTests::RunAllTests();
		V3DBinaryRWTests::RunAllTests();
		V3DJsonIOTests::RunAllTests();
		V3DMemoryStreamTests::RunAllTests();
		V3DSQLiteTests::RunAllTests();
	}
}
