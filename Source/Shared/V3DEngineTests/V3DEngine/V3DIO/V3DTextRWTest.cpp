#include "V3DTextRWTest.h"

#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DIO/V3DTextRW.h"
#include "V3DEngine/V3DIO/V3DFile.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DIO;

namespace V3D::V3DEngineTests::V3DEngine::V3DIO
{
	void V3DTextRWTest::TextRWTest()
	{
		const char* TestAsset = "test2.txt";
		const char* TestInternal = "test.txt";
		const V3DString TestString("<img src=\"Doc/Doxygen/Res/V3DLogoLarge.png\">");
		
		V3DTest::AssertOk(V3DTextRW::Read(V3DAssetPathType::Options, TestAsset).Contains(TestString), V3DFILE_INFO);

		V3DTextRW::Write(V3DAssetPathType::Internal, TestInternal, TestString);
		V3DTest::AssertOk(V3DTextRW::Read(V3DAssetPathType::Internal, TestInternal).Contains(TestString), V3DFILE_INFO);
		V3DFile::Delete(TestInternal);
	}

	void V3DTextRWTest::RunAllTests()
	{
		TextRWTest();

	}
}
