/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DMemoryStreamTests.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DIO/V3DMemoryStream.h"
#include "V3DEngineTests/V3DTestObject/V3DTestComplexData.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngine/V3DIO/V3DBinaryRW.h"
#include "V3DEngine/V3DMathematics/V3DMath.h"
#include "V3DEngineTests/V3DTestObject/V3DTestComplexMemoryStreamRepository.h"

using namespace V3D::V3DEngine::V3DIO;
using namespace V3D::V3DEngineTests::V3DTestObject;
using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DData;
using namespace V3D::V3DEngine::V3DMathematics;

namespace V3D::V3DEngineTests::V3DEngine::V3DIO
{
	void V3DMemoryStreamTests::WriteReadArrayTest()
	{
		char array[100];
		V3DMemoryStream streamIn(100, array);
		int x = 12;
		double y = 23.45;
		streamIn.Write(x);
		streamIn.Write(y);
		streamIn.Write(x);
		V3DTest::AssertOk(streamIn.GetCurrentSize() == (sizeof(x) * 2) + sizeof(y), V3DFILE_INFO);

		V3DMemoryStream streamOut(array);
		int x1, x3;
		double x2;
		streamOut.Read(x1);
		streamOut.Read(x2);
		streamOut.Read(x3);
		V3DTest::AssertOk(x1 == x, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMath::IsEqual(x2, y), V3DFILE_INFO);
		V3DTest::AssertOk(x3 == x, V3DFILE_INFO);
	}

	void V3DMemoryStreamTests::WriteReadObjectTest()
	{
		V3DIStreamRepository<V3DTestComplexData, V3DMemoryStream>* memoryStreamRepository = V3DMemory::New<V3DTestComplexMemoryStreamRepository>(V3DFILE_INFO);

		const V3DTestComplexData testDataW(V3DTestComplexDataHead{ 2, 3 });
		testDataW.vertices[0] = 10;
		testDataW.vertices[1] = 20;
		testDataW.uvs[0] = 1;
		testDataW.uvs[1] = 2;
		testDataW.uvs[2] = 3;
		V3DMemoryStream streamW(testDataW.GetSize());
		memoryStreamRepository->WriteDataToStream(testDataW, streamW);

		V3DTestComplexData testDataR;
		V3DMemoryStream streamR(streamW.GetBuffer());
		memoryStreamRepository->ReadDataFromStream(streamR, testDataR);
		V3DTest::AssertOk(testDataR.head->verticeCount == 2, V3DFILE_INFO);
		V3DTest::AssertOk(testDataR.head->uvCount == 3, V3DFILE_INFO);
		V3DTest::AssertOk(testDataR.vertices[0] == 10.0f, V3DFILE_INFO);
		V3DTest::AssertOk(testDataR.vertices[1] == 20.0f, V3DFILE_INFO);
		V3DTest::AssertOk(testDataR.uvs[0] == 1, V3DFILE_INFO);
		V3DTest::AssertOk(testDataR.uvs[1] == 2, V3DFILE_INFO);
		V3DTest::AssertOk(testDataR.uvs[2] == 3, V3DFILE_INFO);

		V3DMemory::Delete(memoryStreamRepository);
	}

	void V3DMemoryStreamTests::WriteReadObjectToFileTest()
	{
		V3DIStreamRepository<V3DTestComplexData, V3DMemoryStream>* memoryStreamRepository = V3DMemory::New<V3DTestComplexMemoryStreamRepository>(V3DFILE_INFO);
		const char* TestModelDataFileName = "testModelData.dat";

		const V3DTestComplexData testDataW(V3DTestComplexDataHead{ 2, 3 });
		testDataW.vertices[0] = 10;
		testDataW.vertices[1] = 20;
		testDataW.uvs[0] = 1;
		testDataW.uvs[1] = 2;
		testDataW.uvs[2] = 3;
		V3DMemoryStream streamW(testDataW.GetSize());
		memoryStreamRepository->WriteDataToStream(testDataW, streamW);
		V3DBinaryRW::Write(TestModelDataFileName, streamW.GetBuffer(), streamW.GetCurrentSize());

		auto bufferR = V3DBinaryRW::Read(V3DAssetPathType::Internal, TestModelDataFileName);
		V3DMemoryStream streamR(bufferR);
		V3DTestComplexData testDataR;
		memoryStreamRepository->ReadDataFromStream(streamR, testDataR);
		V3DTest::AssertOk(testDataR.head->verticeCount == 2, V3DFILE_INFO);
		V3DTest::AssertOk(testDataR.head->uvCount == 3, V3DFILE_INFO);
		V3DTest::AssertOk(testDataR.vertices[0] == 10.0f, V3DFILE_INFO);
		V3DTest::AssertOk(testDataR.vertices[1] == 20.0f, V3DFILE_INFO);
		V3DTest::AssertOk(testDataR.uvs[0] == 1, V3DFILE_INFO);
		V3DTest::AssertOk(testDataR.uvs[1] == 2, V3DFILE_INFO);
		V3DTest::AssertOk(testDataR.uvs[2] == 3, V3DFILE_INFO);
		V3DMemory::DeleteArray(bufferR);

		V3DMemory::Delete(memoryStreamRepository);
	}

	void V3DMemoryStreamTests::RunAllUnitTests()
	{
		WriteReadArrayTest();
		WriteReadObjectTest();
		WriteReadObjectToFileTest();
	}

	void V3DMemoryStreamTests::RegisterIntegrationTests()
	{
	}

	void V3DMemoryStreamTests::RegisterTimingTests()
	{
	}
}
