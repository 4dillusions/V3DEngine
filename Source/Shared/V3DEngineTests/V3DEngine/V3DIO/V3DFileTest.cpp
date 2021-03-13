/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DFileTest.h"

#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DIO/V3DFile.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DIO;

namespace V3D::V3DEngineTests::V3DEngine::V3DIO
{
	void V3DFileTest::FileTest()
	{
		const char* TestAsset = "test.txt";
		const char* TestInternal = "test.dat";
		const char* TestFake = "fake.dat";
		
		V3DTest::AssertOk(V3DFile::IsExist(V3DAssetPathType::Options, TestAsset), V3DFILE_INFO);

		V3DTest::AssertOk(V3DFile::GetSize(V3DAssetPathType::Options, TestFake) == -1, V3DFILE_INFO);
		V3DTest::AssertOk(V3DFile::GetSize(V3DAssetPathType::Internal, TestFake) == -1, V3DFILE_INFO);
		V3DTest::AssertOk(V3DFile::GetSize(V3DAssetPathType::Options, TestAsset) == 295, V3DFILE_INFO);

		V3DFile::Create(TestInternal);
		V3DTest::AssertOk(V3DFile::IsExist(V3DAssetPathType::Internal, TestInternal), V3DFILE_INFO);
		V3DTest::AssertOk(V3DFile::GetSize(V3DAssetPathType::Internal, TestInternal) == 0, V3DFILE_INFO);

		V3DFile::Delete(TestInternal);
		V3DTest::AssertOk(!V3DFile::IsExist(V3DAssetPathType::Internal, TestInternal), V3DFILE_INFO);
	}

	void V3DFileTest::RunAllTests()
	{
		FileTest();
	}
}
