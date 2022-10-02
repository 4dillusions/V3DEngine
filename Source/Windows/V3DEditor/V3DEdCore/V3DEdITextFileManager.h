/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngine::V3DCore
{
	class V3DString;
}

namespace V3D::V3DEditor::V3DEdCore
{
	class V3DEdITextFileManager
    {
    public:
		V3DEdITextFileManager() = default;
		V3DEdITextFileManager(const V3DEdITextFileManager&) = delete;
		V3DEdITextFileManager(V3DEdITextFileManager&&) = delete;
        virtual ~V3DEdITextFileManager() = default;
		V3DEdITextFileManager& operator=(const V3DEdITextFileManager&) = delete;
		V3DEdITextFileManager& operator=(V3DEdITextFileManager&&) = delete;

		virtual V3DEngine::V3DCore::V3DString* ReadEditorStyle() const = 0;
        virtual void WriteEditorStyle(const V3DEngine::V3DCore::V3DString& text) const = 0;

		virtual V3DEngine::V3DCore::V3DString* ReadOptions(const char* fileName) const = 0; //Assets\Data\Options
        virtual void WriteOptions(const char* fileName, const V3DEngine::V3DCore::V3DString& text) const = 0;
    };
}
