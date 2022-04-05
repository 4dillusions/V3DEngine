/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DISQLContext.h"

struct sqlite3;

namespace V3D::V3DEngine::V3DIO
{
	//definitions will be implement in platform specific .cpp
	class V3DENGINE_API V3DSQLiteContext final : public V3DISQLContext
	{
		sqlite3* db{};  // NOLINT(clang-diagnostic-unused-private-field)
		V3DCollections::V3DDynamicArray<V3DCore::V3DString> outList;

        static int OutputListCallback(void* customData, int columnCount, char** field, char** columnName);
        
	public:
		explicit V3DSQLiteContext(const char* dbName);
        V3DSQLiteContext(const V3DSQLiteContext&) = delete;
        V3DSQLiteContext(V3DSQLiteContext&&) = delete;
        ~V3DSQLiteContext() override;
        V3DSQLiteContext& operator=(const V3DSQLiteContext&) = delete;
        V3DSQLiteContext& operator=(V3DSQLiteContext&&) = delete;

		V3DCollections::V3DDynamicArray<V3DCore::V3DString>& GetOutList() override;
		long long GetLastInsertedId() const override;
		int GetLastModifiedRowCount() const override;

		bool ExecuteSQL(const char* sql, bool isPutOutList = false) override;
	};
}
