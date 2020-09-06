/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DBinaryRWTest.h"

#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DIO/V3DFile.h"
#include "V3DEngineTests/V3DTestObject/V3DTestBinaryData.h"
#include "V3DEngineTests/V3DTestObject/V3DTestSimpleBinaryData.h"
#include "V3DEngine/V3DIO/V3DBinaryRW.h"
#include "V3DEngine/V3DIO/V3DMemoryStream.h"
#include "V3DEngine/V3DCore/V3DMemory.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DIO;
using namespace V3D::V3DEngineTests::V3DTestObject;

namespace V3D::V3DEngineTests::V3DEngine::V3DIO
{
	void V3DBinaryRWTest::BinarySimpleRWTest()
	{
		const char* TestDataFileName = "testData.dat";

		V3DTestSimpleBinaryData testDataW;
		testDataW.id = 23;
		testDataW.text[0] = '1';
		testDataW.text[1] = '2';
		testDataW.text[2] = '3';
		testDataW.Save(TestDataFileName);

		V3DTestSimpleBinaryData testDataR;
		testDataR.Load(V3DAssetPathType::Internal, TestDataFileName);
		V3DTest::AssertOk(testDataR.id == 23, V3DFILE_INFO);
		V3DTest::AssertOk(testDataR.text[0] == '1', V3DFILE_INFO);
		V3DTest::AssertOk(testDataR.text[1] == '2', V3DFILE_INFO);
		V3DTest::AssertOk(testDataR.text[2] == '3', V3DFILE_INFO);
		V3DFile::Delete(TestDataFileName);
	}

	void V3DBinaryRWTest::BinaryComplexRWTest()
	{
		const char* TestModelDataFileName = "testModelData.dat";

		const V3DTestBinaryData testDataW(V3DTestBinaryDataHead{ 2, 3 });
		testDataW.vertices[0] = 10;
		testDataW.vertices[1] = 20;
		testDataW.uvs[0] = 1;
		testDataW.uvs[1] = 2;
		testDataW.uvs[2] = 3;
		testDataW.Save(TestModelDataFileName);

		V3DTestBinaryData testDataR;
		testDataR.Load(V3DAssetPathType::Internal, TestModelDataFileName);
		V3DTest::AssertOk(testDataR.head->verticeCount == 2, V3DFILE_INFO);
		V3DTest::AssertOk(testDataR.head->uvCount == 3, V3DFILE_INFO);
		V3DTest::AssertOk(testDataR.vertices[0] == 10, V3DFILE_INFO);
		V3DTest::AssertOk(testDataR.vertices[1] == 20, V3DFILE_INFO);
		V3DTest::AssertOk(testDataR.uvs[0] == 1, V3DFILE_INFO);
		V3DTest::AssertOk(testDataR.uvs[1] == 2, V3DFILE_INFO);
		V3DTest::AssertOk(testDataR.uvs[2] == 3, V3DFILE_INFO);
		V3DFile::Delete(TestModelDataFileName);
	}

	void V3DBinaryRWTest::BinaryComplexRWMemoryStreamTest()
	{
		const char* TestModelDataFileName = "testModelData.dat";

		const V3DTestBinaryData testDataW(V3DTestBinaryDataHead{ 2, 3 });
		testDataW.vertices[0] = 10;
		testDataW.vertices[1] = 20;
		testDataW.uvs[0] = 1;
		testDataW.uvs[1] = 2;
		testDataW.uvs[2] = 3;
		V3DMemoryStream streamW(testDataW.GetSize());
		testDataW.Save(streamW);
		V3DBinaryRW::Write(TestModelDataFileName, streamW.GetBuffer(), streamW.GetCurrentSize());

		auto bufferR = V3DBinaryRW::Read(V3DAssetPathType::Internal, TestModelDataFileName);
		V3DMemoryStream streamR(bufferR);
		V3DTestBinaryData testDataR;
		testDataR.Load(streamR);
		V3DTest::AssertOk(testDataR.head->verticeCount == 2, V3DFILE_INFO);
		V3DTest::AssertOk(testDataR.head->uvCount == 3, V3DFILE_INFO);
		V3DTest::AssertOk(testDataR.vertices[0] == 10, V3DFILE_INFO);
		V3DTest::AssertOk(testDataR.vertices[1] == 20, V3DFILE_INFO);
		V3DTest::AssertOk(testDataR.uvs[0] == 1, V3DFILE_INFO);
		V3DTest::AssertOk(testDataR.uvs[1] == 2, V3DFILE_INFO);
		V3DTest::AssertOk(testDataR.uvs[2] == 3, V3DFILE_INFO);
		V3DMemory::DeleteArray(bufferR);
	}

	void V3DBinaryRWTest::RunAllTests()
	{
		BinarySimpleRWTest();
		BinaryComplexRWTest();
		BinaryComplexRWMemoryStreamTest();
	}
}
