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
	void V3DIOTests::RunAllUnitTests()
	{
		V3DLoggerTests::RunAllUnitTests();
		V3DFileTests::RunAllUnitTests();
		V3DFolderTests::RunAllUnitTests();
		V3DTextRWTests::RunAllUnitTests();
		V3DBinaryRWTests::RunAllUnitTests();
		V3DJsonIOTests::RunAllUnitTests();
		V3DMemoryStreamTests::RunAllUnitTests();
		V3DSQLiteTests::RunAllUnitTests();
	}

	void V3DIOTests::RegisterIntegrationTests()
	{
		V3DLoggerTests::RegisterIntegrationTests();
		V3DFileTests::RegisterIntegrationTests();
		V3DFolderTests::RegisterIntegrationTests();
		V3DTextRWTests::RegisterIntegrationTests();
		V3DBinaryRWTests::RegisterIntegrationTests();
		V3DJsonIOTests::RegisterIntegrationTests();
		V3DMemoryStreamTests::RegisterIntegrationTests();
		V3DSQLiteTests::RegisterIntegrationTests();
	}

	void V3DIOTests::RegisterTimingTests()
	{
		V3DLoggerTests::RegisterTimingTests();
		V3DFileTests::RegisterTimingTests();
		V3DFolderTests::RegisterTimingTests();
		V3DTextRWTests::RegisterTimingTests();
		V3DBinaryRWTests::RegisterTimingTests();
		V3DJsonIOTests::RegisterTimingTests();
		V3DMemoryStreamTests::RegisterTimingTests();
		V3DSQLiteTests::RegisterTimingTests();
	}
}
