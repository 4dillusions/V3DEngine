/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DTestObject
{
    class V3DITestInterface
    {
    public:
        V3DITestInterface() = default;
        V3DITestInterface(const V3DITestInterface&) = delete;
        V3DITestInterface(V3DITestInterface&&) = delete;
        virtual ~V3DITestInterface() = default;
        V3DITestInterface& operator=(const V3DITestInterface&) = delete;
        V3DITestInterface& operator=(V3DITestInterface&&) = delete;

        virtual bool GetIsSucceed() = 0;
        virtual int GetCount() = 0;
        virtual int GetResult() = 0;
    };
}
