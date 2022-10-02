/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEditor
{
    namespace V3DEdCore
    {
        class V3DEdIViewManager;
        class V3DEdITextFileManager;
    }

    namespace V3DEdLocator
    {
        class V3DEdModelLocator;
    }

    namespace V3DEdModel
    {
        struct V3DEdSettingsModel;
    }
}

namespace V3D::V3DEditor::V3DEdService
{
    class V3DEdSettingsService final
    {
        V3DEdCore::V3DEdIViewManager* viewManager;
        V3DEdCore::V3DEdITextFileManager* textFileManager;
        V3DEdLocator::V3DEdModelLocator* modelLocator;

        V3DEdModel::V3DEdSettingsModel* GetSettingsModel() const;
        
    public:
        V3DEdSettingsService(V3DEdCore::V3DEdIViewManager* viewManager, V3DEdCore::V3DEdITextFileManager* textFileManager, V3DEdLocator::V3DEdModelLocator* modelLocator);

        void Load() const;
        void Save() const;
    };
}
