/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DIO/V3DIOStream.h"
#include "V3DEngine/V3DGameEngine.h"

namespace V3D::V3DEngine::V3DIO
{
    class V3DENGINE_API V3DOstream final : public V3DIOstream
    {
    public:
        void WriteLineToFile(const char* log) override;
        void WriteLineToOutput(const char* log) override;
    };
}
