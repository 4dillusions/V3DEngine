/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DMath.h"

#include <cmath>

namespace V3D::V3DEngine::V3DMathematics
{
	float V3DMath::ConvertDegreeToRadian(float degree)
	{
		return (degree * 0.01745329f);
	}

	float V3DMath::ConvertRadianToDegree(float radian)
	{
		return (radian * 57.29578f);
	}

	float V3DMath::Lerp(float value1, float value2, float amount)
	{
		return (value1 + ((value2 - value1) * amount));
	}

	float V3DMath::Clamp(float value, float min, float max)
	{
		value = (value > max) ? max : value;
		value = (value < min) ? min : value;

		return value;
	}

	int V3DMath::Clamp(int value, int min, int max)
	{
		value = (value > max) ? max : value;
		value = (value < min) ? min : value;

		return value;
	}

	float V3DMath::Distance(float value1, float value2)
	{
		return Abs((value1 - value2));
	}

	float V3DMath::Log(int x, float value)
	{
		return static_cast<float>(log(value)) / static_cast<float>(log(x));
	}

	float V3DMath::Pow(int x, float value)
	{
		return static_cast<float>(pow(x, value));
	}

	bool V3DMath::IsPowerOfTwo(int value)
	{
		return (value & (value - 1)) == 0 && value > 0;
	}
}
