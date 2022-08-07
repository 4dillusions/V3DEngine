/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTestRunner.h"
#include "V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DTypesTests.h"
#include "V3DEngine/V3DMathemathics/V3DMathematicsTests.h"
#include "V3DEngine/V3DCore/V3DCoreTests.h"
#include "V3DEngine/V3DIO/V3DIOTests.h"
#include "V3DEngine/V3DCollections/V3DCollectionsTests.h"
#include "V3DEngine/V3DNetwork/V3DNetworkTests.h"
#include "V3DEngine/V3DCryptography/V3DCryptographyTests.h"
#include "V3DEngine/V3DData/V3DDataTests.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngine/V3DThreading/V3DThreadingTests.h"
#include "V3DEngine/V3DAudio/V3DAudioTests.h"
#include "V3DEngine/V3DCore/V3DIocManager.h"
#include "V3DEngineTests/V3DTestMock/V3DFakeitTests.h"

#include "V3DEngine/V3DIO/V3DLogger.h"
#include "V3DEngine/V3DIO/V3DLogOutputType.h"

using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngineTests::V3DEngine
{	
	void V3DTestRunner::RunAllTests()
	{
		V3D::V3DEngine::V3DIO::V3DLogger::Get().SetOutputTypeFlag(V3D::V3DEngine::V3DIO::V3DLogOutputType::ToOutput, true);
		V3DIocManager::Init();
		V3DEnvironment::SetUnitTestMode();

		/*V3DTypesTests::RunAllTests();
		V3DMathematics::V3DMathematicsTests::RunAllTests();
		V3DCore::V3DCoreTests::RunAllTests();
		V3DIO::V3DIOTests::RunAllTests();
		V3DCollections::V3DCollectionsTests::RunAllTests();
		V3DNetwork::V3DNetworkTests::RunAllTests();
		V3DCryptography::V3DCryptographyTests::RunAllTests();
		V3DData::V3DDataTests::RunAllTests();
		V3DThreading::V3DThreadingTests::RunAllTests();*/
		V3DAudio::V3DAudioTests::RunAllTests();

		//V3DTestMock::V3DFakeitTests::RunAllTests();
		V3DTest::RunIntegrationTests();

		V3D::V3DEngine::V3DIO::V3DLogger::Get().SetOutputTypeFlag(V3D::V3DEngine::V3DIO::V3DLogOutputType::ToOutput, true);
		V3DIocManager::Clean();

		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
		V3DTest::WriteStatistics();
		//V3DTest::RunTimingTests();
	}
}
