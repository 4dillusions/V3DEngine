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

    class V3DEdClient final
    {
        V3DEdCore::V3DEdIViewManager* viewManager;

    public:
        explicit V3DEdClient(V3DEdCore::V3DEdIViewManager* viewManager);
        
        int Execute() const;
    };
}
