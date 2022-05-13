/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DDateTime.h"

#include <ctime>
#include <chrono>

namespace V3D::V3DEngine::V3DCore
{
	V3DTimeSpan* V3DDateTime::GetNow()
	{
		time_t currentTime;
		time(&currentTime);
		struct tm* localTime = localtime(&currentTime);  // NOLINT(concurrency-mt-unsafe)
		localTime->tm_year += 1900;
		localTime->tm_mon += 1;

		static V3DTimeSpan result{};
		result.year = localTime->tm_year;
		result.month = localTime->tm_mon;
		result.day = localTime->tm_mday;
		result.hour = localTime->tm_hour;
		result.min = localTime->tm_min;
		result.sec = localTime->tm_sec;
		result.millisec = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() % 1000);
		
		return &result;
	}
	
	V3DString V3DDateTime::GetTimeStamp(const V3DTimeSpan* now)
	{
		if (now == nullptr)
			now = GetNow();
		
		return V3DString('[') + now->day + "." + now->month + "." + now->year + " " + now->hour + ":" + now->min + ":" + now->sec + "] ";
	}
	
	V3DString V3DDateTime::GetSqlTimeStamp(const V3DTimeSpan* now)
	{
		if (now == nullptr)
			now = GetNow();

		return V3DString(now->year) + "-" + now->month + "-" + now->day + " " + now->hour + ":" + now->min + ":" + now->sec + "." + now->millisec;
	}
	
	V3DString V3DDateTime::GetSQLTimeStampNumbers(const V3DTimeSpan* now)
	{
		if (now == nullptr)
			now = GetNow();

		return V3DString(now->year) + now->month + now->day + now->hour + now->min + now->sec + now->millisec;
	}
}
