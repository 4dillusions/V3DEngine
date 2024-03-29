/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEngine/V3DIO/V3DLogger.h"
#include "V3DEngine/V3DCore/V3DEnvironment.h"

#include <android/log.h>

namespace V3D::V3DEngine::V3DIO
{
    void V3DLogger::WriteLineToFile(const char* log)
    { }

    void V3DLogger::WriteLineToOutput(const char* log)
    {
        __android_log_print(ANDROID_LOG_VERBOSE, V3DCore::V3DEnvironment::GetEngineName(), "%s", log);
    }
}
