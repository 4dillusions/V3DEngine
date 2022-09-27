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
        V3DEdModel::V3DEdSettingsModel* settingsModel;
        
    public:
        V3DEdSettingsService(V3DEdCore::V3DEdIViewManager* viewManager, V3DEdModel::V3DEdSettingsModel* settingsModel);

        void Save() const;
    };
}
