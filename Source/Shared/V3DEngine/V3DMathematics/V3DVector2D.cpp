/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DVector2D.h"
#include "V3DMath.h"

#include <cmath>

namespace V3D::V3DEngine::V3DMathematics
{
	V3DVector2D::V3DVector2D(float x, float y) : x{ x }, y{ y }
	{}

	V3DVector2D::V3DVector2D(float scale) : x{ scale }, y{ scale }
	{}

	bool V3DVector2D::operator==(const V3DVector2D& value) const
	{
		return (V3DMath::IsEqual(x, value.x) && V3DMath::IsEqual(y, value.y));
	}

	bool V3DVector2D::operator!=(const V3DVector2D& value) const
	{
		return (!V3DMath::IsEqual(x, value.x) || !V3DMath::IsEqual(y, value.y));
	}

	V3DVector2D V3DVector2D::operator+(const V3DVector2D& value) const
	{
		return {x + value.x, y + value.y};
	}

	V3DVector2D V3DVector2D::operator+(float size) const
	{
		return {x + size, y + size};
	}

	V3DVector2D V3DVector2D::operator-(const V3DVector2D& value) const
	{
		return {x - value.x, y - value.y};
	}

	V3DVector2D V3DVector2D::operator-(float size) const
	{
		return {x - size, y - size};
	}

	V3DVector2D V3DVector2D::operator*(const V3DVector2D& value) const
	{
		return {x * value.x, y * value.y};
	}

	V3DVector2D V3DVector2D::operator*(float size) const
	{
		return {x * size, y * size};
	}

	V3DVector2D V3DVector2D::operator/(const V3DVector2D& value) const
	{
		return {x / value.x, y / value.y};
	}

	V3DVector2D V3DVector2D::operator/(float size) const
	{
		return {x / size, y / size};
	}

	V3DVector2D V3DVector2D::operator-() const
	{
		return {-x, -y};
	}

	const V3DVector2D& V3DVector2D::operator++()
	{
		++x;
		++y;

		return *this;
	}

	const V3DVector2D& V3DVector2D::operator++(int)
	{
		x++;
		y++;

		return *this;
	}

	const V3DVector2D& V3DVector2D::operator--()
	{
		--x;
		--y;

		return *this;
	}

	const V3DVector2D& V3DVector2D::operator--(int)
	{
		x--;
		y--;

		return *this;
	}

	V3DVector2D& V3DVector2D::operator+=(const V3DVector2D& value)
	{
		x += value.x;
		y += value.y;

		return *this;
	}

	V3DVector2D& V3DVector2D::operator+=(float size)
	{
		x += size;
		y += size;

		return *this;
	}

	V3DVector2D& V3DVector2D::operator-=(const V3DVector2D& value)
	{
		x -= value.x;
		y -= value.y;

		return *this;
	}

	V3DVector2D& V3DVector2D::operator-=(float size)
	{
		x -= size;
		y -= size;

		return *this;
	}

	V3DVector2D& V3DVector2D::operator*=(const V3DVector2D& value)
	{
		x *= value.x;
		y *= value.y;

		return *this;
	}

	V3DVector2D& V3DVector2D::operator*=(float size)
	{
		x *= size;
		y *= size;

		return *this;
	}

	V3DVector2D& V3DVector2D::operator/=(const V3DVector2D& value)
	{
		x /= value.x;
		y /= value.y;

		return *this;
	}

	V3DVector2D& V3DVector2D::operator/=(float size)
	{
		x /= size;
		y /= size;

		return *this;
	}

	bool V3DVector2D::operator<(const V3DVector2D& value) const
	{
		if (x < value.x && y < value.y) 
			return true;

		return false;
	}

	bool V3DVector2D::operator>(const V3DVector2D& value) const
	{
		if (x > value.x && y > value.y) 
			return true;

		return false;
	}

	void V3DVector2D::Zero()
	{
		x = 0.0f;
		y = 0.0f;
	}

	void V3DVector2D::Up()
	{
		x = 0.0f;
		y = -1.0f;
	}

	void V3DVector2D::Down()
	{
		x = 0.0f;
		y = 1.0f;
	}

	void V3DVector2D::Left()
	{
		x = -1.0f;
		y = 0.0f;
	}

	void V3DVector2D::Right()
	{
		x = 1.0f;
		y = 0.0f;
	}

	void V3DVector2D::Rotate(float angle)
	{
		angle = -V3DMath::ConvertDegreeToRadian(angle);

		const float X1 = (x * cosf(angle)) - (y * sinf(angle));
		const float Y1 = (y * cosf(angle)) + (x * sinf(angle));

		x = X1;
		y = Y1;
	}

	void V3DVector2D::RotateCeil(float angle)
	{
		angle = -V3DMath::ConvertDegreeToRadian(angle);

		const float X1 = (x * cosf(angle)) - (y * sinf(angle));
		const float Y1 = (y * cosf(angle)) + (x * sinf(angle));

		x = ceilf(X1);
		y = ceilf(Y1);
	}

	void V3DVector2D::Rotate90DegreeForward()
	{
		const float X1 = y;
		const float Y1 = -x;

		x = X1;
		y = Y1;
	}

	void V3DVector2D::Rotate90DegreeBackward()
	{
		const float X1 = -y;
		const float Y1 = x;

		x = X1;
		y = Y1;
	}

	float V3DVector2D::Length() const
	{
		return sqrt(x * x + y * y);
	}

	float V3DVector2D::Distance(const V3DVector2D& value) const
	{
		return (*this - value).Length();
	}

	float V3DVector2D::DotProduct(const V3DVector2D& value) const
	{
		return x * value.x + y * value.y;
	}

	float V3DVector2D::CrossProduct(const V3DVector2D& value) const
	{
		return x * value.y - y * value.x;
	}

	float V3DVector2D::Normalise()
	{
		const float Result = Length();

		if (Result > 1e-08f)
		{
			const float Length = 1.0f / Result;
			x *= Length;
			y *= Length;
		}

		return Result;
	}

	void V3DVector2D::Normalizing()
	{
		const float LengthTmp = Length();

		x /= LengthTmp;
		y /= LengthTmp;
	}

	V3DVector2D V3DVector2D::MidPoint(const V3DVector2D& value) const
	{
		return {(x + value.x) * 0.5f, (y + value.y) * 0.5f};
	}
}
