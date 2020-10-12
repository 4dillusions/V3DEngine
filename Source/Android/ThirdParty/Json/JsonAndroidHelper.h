/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

/*
	Hack for Android NDK API 19:
	undefined reference to 'wcstoll'
	undefined reference to 'wcstoull'
	undefined reference to 'wcstof'
*/

#pragma once

inline long long wcstoll(const wchar_t* str, wchar_t** str_end, int base)
{
	return 0;
}

inline unsigned long long wcstoull(const wchar_t* str, wchar_t** str_end, int base)
{
	return 0;
}

inline float wcstof(const wchar_t* str, wchar_t** str_end)
{
	return 0;
}
