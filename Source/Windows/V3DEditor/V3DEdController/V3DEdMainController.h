/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEditor::V3DEdService
{
	class V3DEdMainService;
}

namespace V3D::V3DEditor::V3DEdController
{
    class V3DEdMainController final
    {
        V3DEdService::V3DEdMainService* mainService;

    public:
        V3DEdMainController(V3DEdService::V3DEdMainService* mainService);

        void OnToolBarAboutEditor() const;
        void OnToolBarAboutQt() const;
    };
}
