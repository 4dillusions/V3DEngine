/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEditor/V3DEdCore/V3DEdITextFileManager.h"

namespace V3D::V3DEditor::V3DEdData
{
    class V3DEdTextFileManager final : public V3DEdCore::V3DEdITextFileManager
    {
    public:
	    V3DEngine::V3DCore::V3DString* ReadEditorStyle() const override;
        void WriteEditorStyle(const V3DEngine::V3DCore::V3DString& text) const override;

        //V3DEngine::V3DCore::V3DString* ReadShader(const char* fileName); //Assets\Content\Shader
        //void WriteShader(const char* fileName, const V3DEngine::V3DCore::V3DString& text);

        //V3DEngine::V3DCore::V3DString* ReadLevel(); //Assets\Data\Level
        //void WriteLevel(const char* fileName, const V3DEngine::V3DCore::V3DString& text);

        V3DEngine::V3DCore::V3DString* ReadOptions(const char* fileName) const override; //Assets\Data\Options
        void WriteOptions(const char* fileName, const V3DEngine::V3DCore::V3DString& text) const override;

        //V3DEngine::V3DCore::V3DString* ReadPhysicsSetings(const char* fileName); //Assets\Data\Physics
        //void WritePhysicsSettings(const char* fileName, const V3DEngine::V3DCore::V3DString& text);

        //V3DEngine::V3DCore::V3DString* ReadUI(const char* fileName); //Assets\Data\UI
        //void WriteUI(const char* fileName, const V3DEngine::V3DCore::V3DString& text);
    };
}
