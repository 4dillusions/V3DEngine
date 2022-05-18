/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEngineTests/V3DTest.h"

#include <android/log.h>

namespace V3D::V3DEngineTests
{
	void V3DTest::WriteOutput(const std::string& text)
	{
		__android_log_print(ANDROID_LOG_VERBOSE, "V3DEngineTests", "%s", text.c_str());
	}

	void V3DTest::WriteOutput(const char* text)
	{
		__android_log_print(ANDROID_LOG_VERBOSE, "V3DEngineTests", "%s", text);
	}
}
