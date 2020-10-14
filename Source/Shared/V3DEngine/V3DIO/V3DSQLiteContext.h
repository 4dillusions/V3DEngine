/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DCollections/V3DDynamicArray.h"

struct sqlite3;

namespace V3D::V3DEngine::V3DIO
{
	class V3DENGINE_API V3DSQLiteContext final
	{
		sqlite3* db{};
		V3DCollections::V3DDynamicArray<V3DCore::V3DString> outList;

        static int OutputListCallback(void* customData, int columnCount, char** field, char** columnName);
        
	public:
		V3DSQLiteContext(const char* dbName);
        V3DSQLiteContext(const V3DSQLiteContext&) = delete;
        V3DSQLiteContext(V3DSQLiteContext&&) = delete;
        ~V3DSQLiteContext();
        V3DSQLiteContext& operator=(const V3DSQLiteContext&) = delete;
        V3DSQLiteContext& operator=(V3DSQLiteContext&&) = delete;

		[[nodiscard]] V3DCollections::V3DDynamicArray<V3DCore::V3DString>& GetOutList();
		[[nodiscard]] long long GetLastInsertedId() const;
		[[nodiscard]] int GetLastModifiedRowCount() const;

		bool ExecuteSQL(const char* sql, bool isPutOutList = false);
	};
}
