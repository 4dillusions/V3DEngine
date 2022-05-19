/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

// ReSharper disable CppUnusedIncludeDirective
#pragma once

#include "V3DEngine/V3DEngineLibrary.h"

namespace V3D::V3DEngine::V3DNetwork
{
    //definitions will be implement in platform specific .cpp
    class V3DENGINE_API V3DSocketHelper final
    {
    public:
        V3DSocketHelper() = delete;
        V3DSocketHelper(const V3DSocketHelper&) = delete;
        V3DSocketHelper(V3DSocketHelper&&) = delete;
        ~V3DSocketHelper() = delete;
        V3DSocketHelper& operator=(const V3DSocketHelper&) = delete;
        V3DSocketHelper& operator=(V3DSocketHelper&&) = delete;

        static void Close(int socket);
        static void SetNonBlocking(int socket);
    };
}
