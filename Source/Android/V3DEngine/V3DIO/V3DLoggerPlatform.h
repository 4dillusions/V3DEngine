/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include <android/log.h>

namespace V3D::V3DEngine::V3DIO
{
	using V3DOStream = void*;

	inline void InitOStream(V3DOStream& oStream)
	{ }

	inline void WriteLineToFile(V3DOStream& oStream, const char* text)
	{ }

	inline void WriteLineToOutput(const char* log)
	{
		__android_log_print(ANDROID_LOG_VERBOSE, "V3DEngine", "%s", log);
	}
}