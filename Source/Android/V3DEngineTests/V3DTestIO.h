/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include <string>
#include <android/log.h>

namespace V3D::V3DEngineTests
{
	template <typename T>std::string to_string(T value)
	{
		char result[10];
		sprintf(result, "%d", value);

		return result;
	}

	inline void WriteOutput(const std::string& text)
	{
		__android_log_print(ANDROID_LOG_VERBOSE, "LFUnitTest", "%s", text.c_str());
	}
}
