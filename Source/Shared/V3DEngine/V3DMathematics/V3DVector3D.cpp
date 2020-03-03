/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DVector3D.h"

#include <cmath>

namespace V3D::V3DEngine::V3DMathematics
{
	V3DVector3D::V3DVector3D(float scale) : x{ scale }, y{ scale }, z{ scale }
	{}

	V3DVector3D::V3DVector3D(float x, float y, float z) : x{ x }, y{ y }, z{ z }
	{}

	bool V3DVector3D::operator==(const V3DVector3D& value) const
	{
		return (x == value.x && y == value.y && z == value.z);
	}

	bool V3DVector3D::operator!=(const V3DVector3D& value) const
	{
		return (x != value.x || y != value.y || z != value.z);
	}

	V3DVector3D V3DVector3D::operator+(const V3DVector3D& value) const
	{
		return V3DVector3D(x + value.x, y + value.y, z + value.z);
	}

	V3DVector3D V3DVector3D::operator+(float size) const
	{
		return V3DVector3D(x + size, y + size, z + size);
	}

	V3DVector3D V3DVector3D::operator-(const V3DVector3D& value) const
	{
		return V3DVector3D(x - value.x, y - value.y, z - value.z);
	}

	V3DVector3D V3DVector3D::operator-(float size) const
	{
		return V3DVector3D(x - size, y - size, z - size);
	}

	V3DVector3D V3DVector3D::operator*(const V3DVector3D& value) const
	{
		return V3DVector3D(x * value.x, y * value.y, z * value.z);
	}

	V3DVector3D V3DVector3D::operator*(float size) const
	{
		return V3DVector3D(x * size, y * size, z * size);
	}

	V3DVector3D V3DVector3D::operator/(const V3DVector3D& value) const
	{
		return V3DVector3D(x / value.x, y / value.y, z / value.z);
	}

	V3DVector3D V3DVector3D::operator/(float size) const
	{
		return V3DVector3D(x / size, y / size, z / size);
	}

	V3DVector3D V3DVector3D::operator-() const
	{
		return V3DVector3D(-x, -y, -z);
	}

	V3DVector3D& V3DVector3D::operator++()
	{
		++x;
		++y;
		++z;

		return *this;
	}

	V3DVector3D& V3DVector3D::operator++(int)
	{
		x++;
		y++;
		z++;

		return *this;
	}

	V3DVector3D& V3DVector3D::operator--()
	{
		--x;
		--y;
		--z;

		return *this;
	}

	V3DVector3D& V3DVector3D::operator--(int)
	{
		x--;
		y--;
		z--;

		return *this;
	}

	V3DVector3D& V3DVector3D::operator+=(const V3DVector3D& value)
	{
		x += value.x;
		y += value.y;
		z += value.z;

		return *this;
	}

	V3DVector3D& V3DVector3D::operator+=(float size)
	{
		x += size;
		y += size;
		z += size;

		return *this;
	}

	V3DVector3D& V3DVector3D::operator-=(const V3DVector3D& value)
	{
		x -= value.x;
		y -= value.y;
		z -= value.z;

		return *this;
	}

	V3DVector3D& V3DVector3D::operator-=(float size)
	{
		x -= size;
		y -= size;
		z -= size;

		return *this;
	}

	V3DVector3D& V3DVector3D::operator*=(const V3DVector3D& value)
	{
		x *= value.x;
		y *= value.y;
		z *= value.z;

		return *this;
	}

	V3DVector3D& V3DVector3D::operator*=(float size)
	{
		x *= size;
		y *= size;
		z *= size;

		return *this;
	}

	V3DVector3D& V3DVector3D::operator/=(const V3DVector3D& value)
	{
		x /= value.x;
		y /= value.y;
		z /= value.z;

		return *this;
	}

	V3DVector3D& V3DVector3D::operator/=(float size)
	{
		x /= size;
		y /= size;
		z /= size;

		return *this;
	}

	bool V3DVector3D::operator<(const V3DVector3D& value) const
	{
		if (x < value.x && y < value.y && z < value.z) 
			return true;

		return false;
	}

	bool V3DVector3D::operator>(const V3DVector3D& value) const
	{
		if (x > value.x&& y > value.y&& z > value.z) 
			return true;

		return false;
	}

	void V3DVector3D::Zero()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	float V3DVector3D::Length() const
	{
		return static_cast<float>(sqrt(x * x + y * y + z * z));
	}

	float V3DVector3D::Distance(const V3DVector3D& value) const
	{
		return (*this - value).Length();
	}

	float V3DVector3D::DotProduct(const V3DVector3D& value) const
	{
		return x * value.x + y * value.y + z * value.z;
	}

	V3DVector3D V3DVector3D::CrossProduct(const V3DVector3D& value) const
	{
		return V3DVector3D(y * value.z - z * value.y, z * value.x - x * value.z, x * value.y - y * value.x);
	}

	float V3DVector3D::Normalise()
	{
		const float result = Length();

		if (result > 1e-08)
		{
			const float length = 1.0f / result;
			x *= length;
			y *= length;
			z *= length;
		}

		return result;
	}

	void V3DVector3D::Normalizing()
	{
		const float length = Length();

		x /= length;
		y /= length;
		z /= length;
	}

	V3DVector3D V3DVector3D::MidPoint(const V3DVector3D& value) const
	{
		return V3DVector3D((x + value.x) * 0.5f, (y + value.y) * 0.5f, (z + value.z) * 0.5f);
	}
}
