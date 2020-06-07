/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DEngineLibrary.h"

namespace V3D::V3DEngine::V3DMathematics
{
	//Fast math functions and constants
	class V3DENGINE_API V3DMath final
	{
	public:
		V3DMath() = delete;
		V3DMath(const V3DMath&) = delete;
		V3DMath(V3DMath&&) = delete;
		~V3DMath() = delete;
		V3DMath& operator=(const V3DMath&) = delete;
		V3DMath& operator=(V3DMath&&) = delete;

		static constexpr float Pi = 3.141593f;
		static constexpr float PiOver2 = Pi / 2.0f;
		static constexpr float PiOver4 = Pi / 4.0f;
		static constexpr float TwoPi = Pi * 2.0f;
		static constexpr float E = 2.718282f;
		static constexpr float Log10E = 0.4342945f;
		static constexpr float Log2E = 1.442695f;

		template<typename T> static T Min(T value1, T value2) { return (value1 < value2) ? value1 : value2; }
		template<typename T> static T Max(T value1, T value2) { return (value1 > value2) ? value1 : value2; }
		template<typename T> static T Max3(T value1, T value2, T value3) { return (value1 > value2) ? ((value1 > value3) ? value1 : value3) : ((value2 > value3) ? value2 : value3); }
		template<typename T> static T Min3(T value1, T value2, T value3) { return (value1 < value2) ? ((value1 < value3) ? value1 : value3) : ((value2 < value3) ? value2 : value3); }
		template<typename T> static T Abs(T value) { return (value < 0) ? -value : value; }

		static float ConvertDegreeToRadian(float degree);
		static float ConvertRadianToDegree(float radian);
		static float Lerp(float value1, float value2, float amount);
		static float Clamp(float value, float min, float max);
		static int Clamp(int value, int min, int max);
		static float Distance(float value1, float value2);
		static float Log(int x, float value);
		static float Pow(int x, float value);
		static bool IsPowerOfTwo(int value);
	};
}
