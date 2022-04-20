/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DEngineLibrary.h"

#include "ThirdParty/Json/json_fwd.hpp"

namespace V3D::V3DEngine::V3DIO
{
    //definitions will be implement in platform specific .cpp
    class V3DENGINE_API V3DJsonIO final
    {
    public:
        V3DJsonIO() = delete;
        V3DJsonIO(const V3DJsonIO&) = delete;
        V3DJsonIO(V3DJsonIO&&) = delete;
        ~V3DJsonIO() = delete;
        V3DJsonIO& operator=(const V3DJsonIO&) = delete;
        V3DJsonIO& operator=(V3DJsonIO&&) = delete;

        static nlohmann::json GetJsonObject(const char* jsonText);
        static char* GetByteStream(const nlohmann::json& jsonObj);
    };
}
