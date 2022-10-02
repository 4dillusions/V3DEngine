/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngine::V3DCore
{
    enum class V3DAssetPathType : unsigned;
}

namespace V3D::V3DEditor::V3DEdCore
{
	enum class V3DEdAssetPathType : unsigned int;
	
	class V3DEdEnvironment
	{
	public:
        V3DEdEnvironment() = delete;
        V3DEdEnvironment(const V3DEdEnvironment&) = delete;
        V3DEdEnvironment(V3DEdEnvironment&&) = delete;
        ~V3DEdEnvironment() = delete;
        V3DEdEnvironment& operator=(const V3DEdEnvironment&) = delete;
        V3DEdEnvironment& operator=(V3DEdEnvironment&&) = delete;

        static const char* GetEditorStyleFileName();
        static const char* GetAssetPath(V3DEdAssetPathType assetPath);
        static const char* GetFileFullName(V3DEngine::V3DCore::V3DAssetPathType path, const char* fileName);
	};
}
