/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEngine/V3DIO/V3DSQLiteContext.h"
#include "V3DEngine/V3DCore/V3DString.h"
#include "V3DEngine/V3DIO/V3DBinaryRW.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DCollections;

namespace V3D::V3DEngine::V3DIO
{
	V3DSQLiteContext::V3DSQLiteContext(const char* dbName)
	{
		db = nullptr; //avoid not using warning
		V3DBinaryRW::Write("NotImplemented.db", nullptr, 0);
	}
	
	V3DSQLiteContext::~V3DSQLiteContext()  // NOLINT
	{
		
	}

	int V3DSQLiteContext::OutputListCallback(void* customData, int columnCount, char** field, char** columnName)
	{
		return -1;
	}

	V3DDynamicArray<V3DString>& V3DSQLiteContext::GetOutList()
	{
		return outList;
	}

	// ReSharper disable once CppMemberFunctionMayBeStatic
	long long V3DSQLiteContext::GetLastInsertedId() const
	{
		return -1;
	}

	// ReSharper disable once CppMemberFunctionMayBeStatic
	int V3DSQLiteContext::GetLastModifiedRowCount() const
	{
		return -1;
	}

	// ReSharper disable once CppMemberFunctionMayBeStatic
	bool V3DSQLiteContext::ExecuteSQL(const char* sql, bool isPutOutList)
	{
		return false;
	}
}
