/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DSQLiteTest.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngineTests/V3DTestObject/V3DTestPlayerSqlModel.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DIO/V3DFile.h"
#include "V3DEngine/V3DIO/V3DLogger.h"
#include "V3DEngine/V3DIO/V3DLogOutputType.h"
#include "V3DEngine/V3DIO/V3DSQLiteContext.h"
#include "V3DEngineTests/V3DTestObject/V3DTestPlayerSqlProvider.h"

using namespace V3D::V3DEngineTests::V3DTestObject;
using namespace V3D::V3DEngine::V3DIO;
using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngineTests::V3DEngine::V3DIO
{
	void V3DSQLiteTest::CRUDTest()
	{
		V3DLogger::Get().SetOutputTypeFlag(V3DLogOutputType::ToFile, true);
		const char* dbName = "test.db";
		const char* dbExceptionName = "NotImplemented.db";
		V3DFile::Delete(dbName);
		V3DFile::Delete(dbExceptionName);

		V3DSQLiteContext db(dbName);

		if (V3DFile::IsExist(V3DAssetPathType::Internal, dbExceptionName))
		{
			V3DFile::Delete(dbExceptionName);
			return;
		}
		
		V3DTest::AssertOk(V3DFile::IsExist(V3DAssetPathType::Internal, dbName), V3DFILE_INFO);

		V3DTestPlayerSqlModel player1(V3DString("Player1"));
		V3DTestPlayerSqlModel player2(V3DString("Player2"));

		const V3DTestPlayerSqlProvider provider(&db);
		provider.Insert(player1);
		provider.Insert(player2);
		V3DTest::AssertOk(provider.Select(player1) == player1, V3DFILE_INFO);

		player1.SetName(V3DString("updated"));
		provider.Update(player1);
		V3DTest::AssertOk(provider.Select(player1) == player1, V3DFILE_INFO);

		V3DTest::AssertOk(provider.Delete(player1.GetId()), V3DFILE_INFO);
		V3DTest::AssertOk(provider.Select(player1) != player1, V3DFILE_INFO);
		V3DTest::AssertOk(provider.Select(player2) == player2, V3DFILE_INFO);
		V3DTest::AssertOk(provider.DeleteAll(), V3DFILE_INFO);
		V3DTest::AssertOk(provider.Select(player2) != player2, V3DFILE_INFO);

		db.~V3DSQLiteContext();
		V3DFile::Delete(dbName);
		V3DLogger::Get().SetOutputTypeFlag(V3DLogOutputType::ToFile, false);
	}
	
	void V3DSQLiteTest::RunAllTests()
	{
		CRUDTest();
	}
}
