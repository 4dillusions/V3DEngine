/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DTimeSpan.h"
#include "V3DString.h"

namespace V3D::V3DEngine::V3DCore
{
	class  V3DENGINE_API V3DDateTime final
	{
	public:
		V3DDateTime() = delete;
		V3DDateTime(const V3DDateTime&) = delete;
		V3DDateTime(V3DDateTime&&) = delete;
		~V3DDateTime() = delete;
		V3DDateTime& operator=(const V3DDateTime&) = delete;
		V3DDateTime& operator=(V3DDateTime&&) = delete;

		static V3DTimeSpan* GetNow();
		static V3DString GetTimeStamp(V3DTimeSpan* now = nullptr); //for logging
		static V3DString GetSqlTimeStamp(V3DTimeSpan* now = nullptr); //for MySQL (fractional-second time datatypes supported in MySQL 5.6.4 or later)
		static V3DString GetSQLTimeStampNumbers(V3DTimeSpan* now = nullptr); //for MySQL (under the version 5.6.4)
	};
}
