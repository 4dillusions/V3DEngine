/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include <string>

namespace V3D::V3DEngineTests
{
    template <typename TDerived> class V3DITestIO
    {
    public:
        V3DITestIO() = default;
        V3DITestIO(const V3DITestIO&) = default;
        V3DITestIO(V3DITestIO&&) = default;
        virtual ~V3DITestIO() = default;
        V3DITestIO& operator=(const V3DITestIO&) = delete;
        V3DITestIO& operator=(V3DITestIO&&) = delete;

        static TDerived& Get()
        {
            static TDerived instance;

            return instance;
        }

        virtual std::string ConvertToString(int value) = 0;
        virtual void WriteOutput(const std::string& text) = 0;
    };
}
