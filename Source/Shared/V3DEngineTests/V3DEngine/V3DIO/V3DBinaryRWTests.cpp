/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DBinaryRWTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DIO/V3DFile.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngineTests/V3DTestObject/V3DTestSimpleData.h"
#include "V3DEngineTests/V3DTestObject/V3DTestSimpleFileRepository.h"
#include "V3DEngineTests/V3DTestObject/V3DTestComplexData.h"
#include "V3DEngineTests/V3DTestObject/V3DTestComplexFileRepository.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DIO;
using namespace V3D::V3DEngineTests::V3DTestObject;
using namespace V3D::V3DEngine::V3DData;

namespace V3D::V3DEngineTests::V3DEngine::V3DIO
{
	void V3DBinaryRWTests::BinarySimpleRWTest()
	{
		const char* TestDataFileName = "testData.dat";

		V3DIFileRepository<V3DTestSimpleData>* simpleFileRepository = V3DMemory::New<V3DTestSimpleFileRepository<V3DTestSimpleData>>(V3DFILE_INFO);

		V3DTestSimpleData testDataW;
		testDataW.id = 23;
		testDataW.text[0] = '1';
		testDataW.text[1] = '2';
		testDataW.text[2] = '3';
		simpleFileRepository->Save(testDataW, TestDataFileName);
		V3DTest::AssertOk(V3DFile::GetSize(V3DAssetPathType::Internal, TestDataFileName) == sizeof(V3DTestSimpleData), V3DFILE_INFO);

		const auto testDataR = simpleFileRepository->Load(V3DAssetPathType::Internal, TestDataFileName);
		V3DTest::AssertOk(testDataR.id == 23, V3DFILE_INFO);
		V3DTest::AssertOk(testDataR.text[0] == '1', V3DFILE_INFO);
		V3DTest::AssertOk(testDataR.text[1] == '2', V3DFILE_INFO);
		V3DTest::AssertOk(testDataR.text[2] == '3', V3DFILE_INFO);
		V3DFile::Delete(TestDataFileName);

		const auto testDataRContent = simpleFileRepository->Load(V3DAssetPathType::Options, TestDataFileName);
		V3DTest::AssertOk(testDataRContent.id == 23, V3DFILE_INFO);
		V3DTest::AssertOk(testDataRContent.text[0] == '1', V3DFILE_INFO);
		V3DTest::AssertOk(testDataRContent.text[1] == '2', V3DFILE_INFO);
		V3DTest::AssertOk(testDataRContent.text[2] == '3', V3DFILE_INFO);

		V3DMemory::Delete(simpleFileRepository);
	}

	void V3DBinaryRWTests::BinaryComplexRWTest()
	{
		const char* TestModelDataFileName = "testModelData.dat";

		V3DIFileRepository<V3DTestComplexData*>* complexFileRepository = V3DMemory::New<V3DTestComplexFileRepository>(V3DFILE_INFO);

		auto testDataW = V3DMemory::New<V3DTestComplexData>(V3DFILE_INFO, V3DTestComplexDataHead{ 2, 3 });
		testDataW->vertices[0] = 10;
		testDataW->vertices[1] = 20;
		testDataW->uvs[0] = 1;
		testDataW->uvs[1] = 2;
		testDataW->uvs[2] = 3;
		complexFileRepository->Save(testDataW, TestModelDataFileName);
		V3DTest::AssertOk(V3DFile::GetSize(V3DAssetPathType::Internal, TestModelDataFileName) == testDataW->GetSize(), V3DFILE_INFO);
		V3DMemory::Delete(testDataW);

		auto testDataR = complexFileRepository->Load(V3DAssetPathType::Internal, TestModelDataFileName);
		V3DTest::AssertOk(testDataR->head->verticeCount == 2, V3DFILE_INFO);
		V3DTest::AssertOk(testDataR->head->uvCount == 3, V3DFILE_INFO);
		V3DTest::AssertOk(testDataR->vertices[0] == 10.0f, V3DFILE_INFO);
		V3DTest::AssertOk(testDataR->vertices[1] == 20.0f, V3DFILE_INFO);
		V3DTest::AssertOk(testDataR->uvs[0] == 1, V3DFILE_INFO);
		V3DTest::AssertOk(testDataR->uvs[1] == 2, V3DFILE_INFO);
		V3DTest::AssertOk(testDataR->uvs[2] == 3, V3DFILE_INFO);
		V3DFile::Delete(TestModelDataFileName);
		V3DMemory::Delete(testDataR);

		auto testDataRContent = complexFileRepository->Load(V3DAssetPathType::Model, TestModelDataFileName);
		V3DTest::AssertOk(testDataRContent->head->verticeCount == 2, V3DFILE_INFO);
		V3DTest::AssertOk(testDataRContent->head->uvCount == 3, V3DFILE_INFO);
		V3DTest::AssertOk(testDataRContent->vertices[0] == 10.0f, V3DFILE_INFO);
		V3DTest::AssertOk(testDataRContent->vertices[1] == 20.0f, V3DFILE_INFO);
		V3DTest::AssertOk(testDataRContent->uvs[0] == 1, V3DFILE_INFO);
		V3DTest::AssertOk(testDataRContent->uvs[1] == 2, V3DFILE_INFO);
		V3DTest::AssertOk(testDataRContent->uvs[2] == 3, V3DFILE_INFO);
		V3DMemory::Delete(testDataRContent);

		V3DMemory::Delete(complexFileRepository);
	}

	void V3DBinaryRWTests::RunAllTests()
	{
		BinarySimpleRWTest();
		BinaryComplexRWTest();
	}
}
