/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEditor::V3DEdService
{
	class V3DEdSettingsService;
}

namespace V3D::V3DEditor::V3DEdController
{
    class V3DEdSettingsController final
    {
        V3DEdService::V3DEdSettingsService* settingsService;

    public:
        V3DEdSettingsController(V3DEdService::V3DEdSettingsService* settingsService);

        void OnSettingsLoad() const;
        void OnSettingsSave() const;
    };
}
