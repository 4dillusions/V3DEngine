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
        class V3DEdIWindowManager;
    }

    class V3DEdClient final
    {
        V3DEdCore::V3DEdIWindowManager* windowManager;

    public:
        explicit V3DEdClient(V3DEdCore::V3DEdIWindowManager* windowManager);
        V3DEdClient(const V3DEdClient&) = delete;
        V3DEdClient(V3DEdClient&&) = delete;
        ~V3DEdClient() = default;
        V3DEdClient& operator=(const V3DEdClient&) = delete;
        V3DEdClient& operator=(V3DEdClient&&) = delete;

        int Execute() const;
    };
}
