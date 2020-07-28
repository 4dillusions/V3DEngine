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
		
		V3DTest::AssertOk(V3DFile::IsExist(V3DAssetPathType::Options, TestAsset), V3DFILE_INFO);

		V3DFile::Create(TestInternal);
		V3DTest::AssertOk(V3DFile::IsExist(V3DAssetPathType::Internal, TestInternal), V3DFILE_INFO);

		V3DFile::Delete(TestInternal);
		V3DTest::AssertOk(!V3DFile::IsExist(V3DAssetPathType::Internal, TestInternal), V3DFILE_INFO);
	}

	void V3DFileTest::RunAllTests()
	{
		FileTest();
	}
}
