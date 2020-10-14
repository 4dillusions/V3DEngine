/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTestPlayerSqlModel.h"
#include "V3DTestPlayerSqlProvider.h"
#include "V3DEngine/V3DIO/V3DSQLiteContext.h"
#include "V3DEngine/V3DIO/V3DLogger.h"

using namespace V3D::V3DEngine::V3DIO;
using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngineTests::V3DTestObject
{
	V3DTestPlayerSqlProvider::V3DTestPlayerSqlProvider(V3DSQLiteContext* db) : db{ db }
	{
		bool isOk = false;
		if (db != nullptr && db->ExecuteSQL("SELECT rowid FROM Player;") == false)
		{
			isOk = db->ExecuteSQL("CREATE TABLE Player(Name NVARCHAR(20), UpdatedTime DATETIME);");
			V3DLogger::Get().WriteOutput("Create Player table!");
		}

		V3DLogger::Get().WriteOutput(isOk ? "Player table OK!" : "Player table failed!");
	}
	
	V3DTestPlayerSqlModel V3DTestPlayerSqlProvider::Select(V3DTestPlayerSqlModel& model) const
	{
		V3DTestPlayerSqlModel result;

		if (db == nullptr)
			return result;

		V3DString sql("SELECT rowid, Name FROM Player WHERE ");
		sql += V3DString("rowid = ") + model.GetId() + " AND ";
		sql += V3DString("Name = '") + model.GetName() + "';";

		db->ExecuteSQL(sql.ToChar(), true);
		auto& outList = db->GetOutList();

		if (outList.GetLength() == 0)
			return result;

		result.SetId(outList[0]->ToInt());  // NOLINT
		result.SetName(*outList[1]);

		return result;
	}
	
	bool V3DTestPlayerSqlProvider::Insert(V3DTestPlayerSqlModel& model) const
	{
		if (db == nullptr)
			return false;

		V3DString sql("INSERT INTO Player VALUES ('");
		sql += model.GetName() + "', '";
		sql += V3DString("2012-10-23 09:23:10.999") + "');";

		const bool result = db->ExecuteSQL(sql.ToChar());
		model.SetId(static_cast<int>(db->GetLastInsertedId()));

		return result;
	}
	
	bool V3DTestPlayerSqlProvider::Update(V3DTestPlayerSqlModel& model) const
	{
		V3DString sql("UPDATE Player SET Name = '");
		sql += model.GetName() + "', ";
		sql += V3DString("UpdatedTime = '") + "2020-10-23 09:23:20.456" + "' ";
		sql += V3DString("WHERE rowid = ") + model.GetId() + ";";
		db->ExecuteSQL(sql.ToChar());

		return db->GetLastModifiedRowCount() == 1;
	}
	
	bool V3DTestPlayerSqlProvider::Delete(int id) const
	{
		if (db == nullptr)
			return false;

		db->ExecuteSQL((V3DString("DELETE FROM Player WHERE rowid = ") + id + ";").ToChar());

		return db->GetLastModifiedRowCount() > 0;
	}
	
	bool V3DTestPlayerSqlProvider::DeleteAll() const
	{
		if (db == nullptr)
			return false;

		if (db != nullptr)
			db->ExecuteSQL("DELETE FROM Player;");

		return db->GetLastModifiedRowCount() > 0;
	}
}
