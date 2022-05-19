/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DCollections/V3DDynamicArray.h"

namespace V3D::V3DEngine::V3DIO
{
    class V3DENGINE_API V3DISQLContext  // NOLINT(clang-diagnostic-weak-vtables)
    {
    public:
        V3DISQLContext() = default;
        V3DISQLContext(const V3DISQLContext&) = delete;
        V3DISQLContext(V3DISQLContext&&) = delete;
        virtual ~V3DISQLContext() = default;
        V3DISQLContext& operator=(const V3DISQLContext&) = delete;
        V3DISQLContext& operator=(V3DISQLContext&&) = delete;
        
        virtual V3DCollections::V3DDynamicArray<V3DCore::V3DString>& GetOutList() = 0;
        virtual long long GetLastInsertedId() const = 0;
        virtual int GetLastModifiedRowCount() const = 0;
        
        virtual bool ExecuteSQL(const char* sql, bool isPutOutList = false) = 0;
    };
}
