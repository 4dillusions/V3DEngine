/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTestRunner.h"
#include "V3DTest.h"
#include "V3DTestType.h"
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

using namespace V3D::V3DEngineTests::V3DEngine;
using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DIO;

namespace V3D::V3DEngineTests
{
	V3DTestType V3DTestRunner::testType = V3DTestType::UnitTests;

	void V3DTestRunner::Init()
	{
		if (testType == V3DTestType::IntegrationTests)
			V3DLogger::Get().SetOutputTypeFlag(V3DLogOutputType::ToOutput, true);

		V3DIocManager::Init();
		V3DEnvironment::SetUnitTestMode();
	}

	void V3DTestRunner::CleanUp()
	{
		if (testType == V3DTestType::IntegrationTests)
			V3DLogger::Get().SetOutputTypeFlag(V3DLogOutputType::ToOutput, true);

		V3DIocManager::Clean();

		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);

		if (testType == V3DTestType::UnitTests)
			V3DTest::WriteStatistics();
	}
	
	void V3DTestRunner::RunUniTests()
	{
		if (testType == V3DTestType::UnitTests)
		{
			V3DTypesTests::RunAllUnitTests();
			V3DMathematics::V3DMathematicsTests::RunAllUnitTests();
			V3DCore::V3DCoreTests::RunAllUnitTests();
			V3DIO::V3DIOTests::RunAllUnitTests();
			V3DCollections::V3DCollectionsTests::RunAllUnitTests();
			V3DNetwork::V3DNetworkTests::RunAllUnitTests();
			V3DCryptography::V3DCryptographyTests::RunAllUnitTests();
			V3DData::V3DDataTests::RunAllUnitTests();
			V3DThreading::V3DThreadingTests::RunAllUnitTests();
			V3DTestMock::V3DFakeitTests::RunAllUnitTests();
			V3DAudio::V3DAudioTests::RunAllUnitTests();
		}
	}

	void V3DTestRunner::RegisterAndRunIntegrationTests()
	{
		if (testType == V3DTestType::IntegrationTests)
		{
			V3DTypesTests::RegisterIntegrationTests();
			V3DMathematics::V3DMathematicsTests::RegisterIntegrationTests();
			V3DCore::V3DCoreTests::RegisterIntegrationTests();
			V3DIO::V3DIOTests::RegisterIntegrationTests();
			V3DCollections::V3DCollectionsTests::RegisterIntegrationTests();
			V3DNetwork::V3DNetworkTests::RegisterIntegrationTests();
			V3DCryptography::V3DCryptographyTests::RegisterIntegrationTests();
			V3DData::V3DDataTests::RegisterIntegrationTests();
			V3DThreading::V3DThreadingTests::RegisterIntegrationTests();
			V3DTestMock::V3DFakeitTests::RegisterIntegrationTests();
			V3DAudio::V3DAudioTests::RegisterIntegrationTests();
			
			V3DTest::RunIntegrationTests();
		}
	}

	void V3DTestRunner::RegisterAndRunRunTimingTests()
	{
		if (testType == V3DTestType::TimingTests)
		{
			V3DTypesTests::RegisterTimingTests();
			V3DMathematics::V3DMathematicsTests::RegisterTimingTests();
			V3DCore::V3DCoreTests::RegisterTimingTests();
			V3DIO::V3DIOTests::RegisterTimingTests();
			V3DCollections::V3DCollectionsTests::RegisterTimingTests();
			V3DNetwork::V3DNetworkTests::RegisterTimingTests();
			V3DCryptography::V3DCryptographyTests::RegisterTimingTests();
			V3DData::V3DDataTests::RegisterTimingTests();
			V3DThreading::V3DThreadingTests::RegisterTimingTests();
			V3DTestMock::V3DFakeitTests::RegisterTimingTests();
			V3DAudio::V3DAudioTests::RegisterTimingTests();

			V3DTest::RunTimingTests();
		}
	}
	
	void V3DTestRunner::RunAllTests()
	{
		Init();

		RunUniTests();
		RegisterAndRunIntegrationTests();
		
		CleanUp();

		RegisterAndRunRunTimingTests();
	}
}
