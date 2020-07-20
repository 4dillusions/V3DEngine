/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DOstream.h"

#include <android/log.h>

namespace V3D::V3DEngine::V3DIO
{
    void V3DOstream::WriteLineToFile(const char* log)
    { }

    void V3DOstream::WriteLineToOutput(const char* log)
    {
        __android_log_print(ANDROID_LOG_VERBOSE, "V3DEngine", "%s", log);
    }
}
