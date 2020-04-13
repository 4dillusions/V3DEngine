#pragma once

#include "V3DEngine/V3DEngineLibraryPlatform.h"

namespace V3D::V3DEngine::V3DCore
{
	struct V3DENGINE_API V3DTimeSpan
	{
		int year;
		int month;
		int day;
		int hour;
		int min;
		int sec;
		int millisec;
	};
}
