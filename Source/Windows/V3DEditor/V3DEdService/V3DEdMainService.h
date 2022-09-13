/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEditor::V3DEdCore
{
    class V3DEdIViewManager;
}
	
namespace V3D::V3DEditor::V3DEdService
{
    class V3DEdMainService final
    {
        V3DEdCore::V3DEdIViewManager* viewManager;

    public:
        V3DEdMainService(V3DEdCore::V3DEdIViewManager* viewManager);

        void AboutEditor() const;
        void AboutQt() const;
    };
}
