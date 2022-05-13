/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEngine/V3DIO/V3DSQLiteContext.h"
#include "V3DEngine/V3DCore/V3DString.h"
#include "V3DEngine/V3DIO/V3DLogger.h"

#include "ThirdParty/SQLite/sqlite3.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DCollections;

namespace V3D::V3DEngine::V3DIO
{
	V3DSQLiteContext::V3DSQLiteContext(const char* dbName)
	{
		if (sqlite3_open(dbName, &db))
		{
			V3DLogger::Get().WriteOutput(V3DLogMessageType::Error, V3DString("Can't open database ") + sqlite3_errmsg(db));
			sqlite3_close(db);
			db = nullptr;
		}
		else
		{
			V3DLogger::Get().WriteOutput(V3DString("open/create database  ") + dbName + " OK!");
		}
	}
	
	V3DSQLiteContext::~V3DSQLiteContext()
	{
		if (db != nullptr)
			sqlite3_close(db);
	}

	int V3DSQLiteContext::OutputListCallback(void* customData, int columnCount, char** field, char** columnName)
	{
		const auto list = static_cast<V3DDynamicArray<V3DString>*>(customData);

		for (int index = 0; index < columnCount; index++)
			list->Add(V3DString(field[index]));

		return 0;
	}

	V3DDynamicArray<V3DString>& V3DSQLiteContext::GetOutList()
	{
		return outList;
	}

	long long V3DSQLiteContext::GetLastInsertedId() const
	{
		if (db == nullptr)
		{
			V3DLogger::Get().WriteOutput(V3DLogMessageType::Error, "Can't get last id!");
			return 0;
		}

		return sqlite3_last_insert_rowid(db);
	}

	int V3DSQLiteContext::GetLastModifiedRowCount() const
	{
		return sqlite3_changes(db);
	}
	
	bool V3DSQLiteContext::ExecuteSQL(const char* sql, bool isPutOutList)
	{
		outList.RemoveAll();

		if (db == nullptr)
		{
			V3DLogger::Get().WriteOutput(V3DLogMessageType::Error, "Can't execute SQL command!");
			return false;
		}

		V3DLogger::Get().WriteOutput( V3DString("SQL command: ") + sql);

		char* errorMsg{};
		if (sqlite3_exec(db, sql, isPutOutList ? OutputListCallback : nullptr, &outList, &errorMsg) != SQLITE_OK)
		{
			V3DLogger::Get().WriteOutput(V3DLogMessageType::Error, errorMsg);
			sqlite3_free(errorMsg);

			return false;
		}
		
		return true;
	}
}
