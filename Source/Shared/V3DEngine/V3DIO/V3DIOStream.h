/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngine::V3DIO
{
    class V3DIOstream
    {
    public:
        V3DIOstream() = default;
        V3DIOstream(const V3DIOstream&) = default;
        V3DIOstream(V3DIOstream&&) = default;
        virtual ~V3DIOstream() = default;
        V3DIOstream& operator=(const V3DIOstream&) = delete;
        V3DIOstream& operator=(V3DIOstream&&) = delete;

        virtual void WriteLineToFile(const char* log) = 0;
        virtual void WriteLineToOutput(const char* log) = 0;
    };
}