/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTestPlayerSqlRepository.h"
#include "V3DTestPlayerData.h"
#include "V3DEngine/V3DCore/V3DIoc.h"
#include "V3DEngine/V3DIO/V3DSQLiteContext.h"
#include "V3DEngine/V3DIO/V3DLogger.h"

using namespace V3D::V3DEngine::V3DIO;
using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngineTests::V3DTestObject
{
	V3DTestPlayerSqlRepository::V3DTestPlayerSqlRepository() : db{ V3DIoc<V3DSQLiteContext*>::GetSingleton() }
	{
		bool isOk = false;
		if (db != nullptr && db->ExecuteSQL("SELECT rowid FROM Player;") == false)
		{
			isOk = db->ExecuteSQL("CREATE TABLE Player(Name NVARCHAR(20), UpdatedTime DATETIME);");
			V3DLogger::Get().WriteOutput("Create Player table!");
		}

		V3DLogger::Get().WriteOutput(isOk ? "Player table OK!" : "Player table failed!");
	}
	
	V3DTestPlayerData V3DTestPlayerSqlRepository::Select(const V3DTestPlayerData& data) const
	{
		V3DTestPlayerData result;

		if (db == nullptr)
			return result;

		V3DString sql("SELECT rowid, Name FROM Player WHERE ");
		sql += V3DString("rowid = ") + data.GetId() + " AND ";
		sql += V3DString("Name = '") + data.GetName() + "';";

		db->ExecuteSQL(sql.ToChar(), true);
		auto& outList = db->GetOutList();

		if (outList.GetLength() == 0)
			return result;

		result.SetId(outList[0]->ToInt());  // NOLINT
		result.SetName(*outList[1]);

		return result;
	}
	
	bool V3DTestPlayerSqlRepository::Insert(V3DTestPlayerData& data) const
	{
		if (db == nullptr)
			return false;

		V3DString sql("INSERT INTO Player VALUES ('");
		sql += data.GetName() + "', '";
		sql += V3DString("2012-10-23 09:23:10.999") + "');";

		const bool result = db->ExecuteSQL(sql.ToChar());
		data.SetId(static_cast<int>(db->GetLastInsertedId()));

		return result;
	}
	
	bool V3DTestPlayerSqlRepository::Update(const V3DTestPlayerData& data) const
	{
		V3DString sql("UPDATE Player SET Name = '");
		sql += data.GetName() + "', ";
		sql += V3DString("UpdatedTime = '") + "2020-10-23 09:23:20.456" + "' ";
		sql += V3DString("WHERE rowid = ") + data.GetId() + ";";
		db->ExecuteSQL(sql.ToChar());

		return db->GetLastModifiedRowCount() == 1;
	}
	
	bool V3DTestPlayerSqlRepository::Delete(const V3DTestPlayerData& data) const
	{
		if (db == nullptr)
			return false;

		db->ExecuteSQL((V3DString("DELETE FROM Player WHERE rowid = ") + data.GetId() + ";").ToChar());

		return db->GetLastModifiedRowCount() > 0;
	}
	
	bool V3DTestPlayerSqlRepository::DeleteAll() const
	{
		if (db == nullptr)
			return false;

		if (db != nullptr)
			db->ExecuteSQL("DELETE FROM Player;");

		return db->GetLastModifiedRowCount() > 0;
	}
}
