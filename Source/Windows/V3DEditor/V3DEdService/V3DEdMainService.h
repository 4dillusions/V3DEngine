/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DIO/V3DLogMessageType.h"

namespace V3D::V3DEditor
{
    namespace V3DEdCore
    {
        class V3DEdIViewManager;
    }

    namespace V3DEdLocator
    {
        class V3DEdModelLocator;
    }

    namespace V3DEdModel
    {
        struct V3DEdMainModel;
    }
}

namespace V3D::V3DEngine
{
    namespace V3DCore
    {
        class V3DString;
    }

    namespace V3DIO
    {
        class V3DLogger;
    }
}

namespace V3D::V3DEditor::V3DEdService
{
    class V3DEdMainService final
    {
        V3DEdCore::V3DEdIViewManager* viewManager;
        V3DEdLocator::V3DEdModelLocator* modelLocator;
        V3DEngine::V3DIO::V3DLogger* outputLogger;

        V3DEdModel::V3DEdMainModel* GetMainModel() const;

    public:
        V3DEdMainService(V3DEdCore::V3DEdIViewManager* viewManager, V3DEdLocator::V3DEdModelLocator* modelLocator, V3DEngine::V3DIO::V3DLogger* outputLogger);

        void Settings() const;
        void AboutEditor() const;
        void AboutQt() const;

        void EngineLogWrite(const V3DEngine::V3DCore::V3DString& log) const;
        void EngineLogClear() const;
        void OutputLogWrite(V3DEngine::V3DIO::V3DLogMessageType messageType, const V3DEngine::V3DCore::V3DString& log) const;
        void OutputLogClear() const;
    };
}
