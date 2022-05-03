/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

// ReSharper disable once CppUnusedIncludeDirective
#include "V3DEngine/V3DCore/V3DAssetPathType.h"

namespace V3D::V3DEngine::V3DData
{
	template <typename TData> class V3DIFileRepository
    {
    public:
        V3DIFileRepository() = default;
        V3DIFileRepository(const V3DIFileRepository&) = default;
        V3DIFileRepository(V3DIFileRepository&&) = default;
        virtual ~V3DIFileRepository() = default;
        V3DIFileRepository& operator=(const V3DIFileRepository&) = delete;
        V3DIFileRepository& operator=(V3DIFileRepository&&) = delete;

		virtual TData Load(V3DCore::V3DAssetPathType path, const char* fileName) const = 0;
		virtual void Save(TData& data, const char* fileName) const = 0;
    };
}
