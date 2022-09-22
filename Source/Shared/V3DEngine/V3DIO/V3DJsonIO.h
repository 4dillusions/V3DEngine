/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "ThirdParty/Json/json_fwd.hpp"
#include "V3DEngine/V3DEngineLibrary.h"
#include "V3DEngine/V3DCore/V3DAction.h"

namespace V3D::V3DEngine::V3DCore
{
	class V3DString;
}
	
namespace V3D::V3DEngine::V3DIO
{
	class V3DJsonVariant;

    class V3DENGINE_API V3DJsonIO final
    {
    public:
        V3DJsonIO() = delete;
        V3DJsonIO(const V3DJsonIO&) = delete;
        V3DJsonIO(V3DJsonIO&&) = delete;
        ~V3DJsonIO() = delete;
        V3DJsonIO& operator=(const V3DJsonIO&) = delete;
        V3DJsonIO& operator=(V3DJsonIO&&) = delete;

        static nlohmann::json GetJsonObject(const char* jsonText); //definition will be implement in platform specific .cpp
        static char* GetByteStream(const nlohmann::json& jsonObj); //definition will be implement in platform specific .cpp

        static void TraversalJsonHierarchy(const nlohmann::json& jsonObj, void* parent, const V3DCore::V3DAction3<const V3DCore::V3DString&, const V3DCore::V3DString&, const V3DJsonVariant&>& action);
    };
}
