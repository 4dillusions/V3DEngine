/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DSQLiteTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngineTests/V3DTestObject/V3DTestPlayerData.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DCore/V3DIoc.h"
#include "V3DEngine/V3DIO/V3DFile.h"
#include "V3DEngine/V3DIO/V3DLogger.h"
#include "V3DEngine/V3DIO/V3DLogOutputType.h"
#include "V3DEngine/V3DIO/V3DSQLiteContext.h"
#include "V3DEngineTests/V3DTestObject/V3DTestPlayerSqlRepository.h"

using namespace V3D::V3DEngineTests::V3DTestObject;
using namespace V3D::V3DEngine::V3DIO;
using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DData;

namespace V3D::V3DEngineTests::V3DEngine::V3DIO
{
	void V3DSQLiteTests::CRUDTest()
	{
		V3DLogger::Get().SetOutputTypeFlag(V3DLogOutputType::ToFile, true);
		const char* dbName = "test.db";
		const char* dbExceptionName = "NotImplemented.db";
		V3DFile::Delete(dbName);
		V3DFile::Delete(dbExceptionName);

		V3DIoc<V3DSQLiteContext*>::Register<V3DSQLiteContext>([&]() { return V3DMemory::New<V3DSQLiteContext>(V3DFILE_INFO, dbName); });
		V3DIoc<V3DSQLiteContext*>::Create();

		if (V3DFile::IsExist(V3DAssetPathType::Internal, dbExceptionName))
		{
			V3DIoc<V3DSQLiteContext*>::DeleteInstance();
			V3DFile::Delete(dbExceptionName);
			
			return;
		}
		
		V3DTest::AssertOk(V3DFile::IsExist(V3DAssetPathType::Internal, dbName), V3DFILE_INFO);

		V3DTestPlayerData player1(V3DString("Player1"));
		V3DTestPlayerData player2(V3DString("Player2"));

		V3DISQLRepository<V3DTestPlayerData>* playerSQLRepository = V3DMemory::New<V3DTestPlayerSqlRepository>(V3DFILE_INFO);
		playerSQLRepository->Insert(player1);
		playerSQLRepository->Insert(player2);
		V3DTest::AssertOk(playerSQLRepository->Select(player1) == player1, V3DFILE_INFO);

		player1.SetName(V3DString("updated"));
		playerSQLRepository->Update(player1);
		V3DTest::AssertOk(playerSQLRepository->Select(player1) == player1, V3DFILE_INFO);

		V3DTest::AssertOk(playerSQLRepository->Delete(player1), V3DFILE_INFO);
		V3DTest::AssertOk(playerSQLRepository->Select(player1) != player1, V3DFILE_INFO);
		V3DTest::AssertOk(playerSQLRepository->Select(player2) == player2, V3DFILE_INFO);
		V3DTest::AssertOk(playerSQLRepository->DeleteAll(), V3DFILE_INFO);
		V3DTest::AssertOk(playerSQLRepository->Select(player2) != player2, V3DFILE_INFO);

		V3DMemory::Delete(playerSQLRepository);
		V3DIoc<V3DSQLiteContext*>::DeleteInstance();
		V3DFile::Delete(dbName);
		V3DLogger::Get().SetOutputTypeFlag(V3DLogOutputType::ToFile, false);
	}
	
	void V3DSQLiteTests::RunAllTests()
	{
		CRUDTest();
	}
}
