/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DVector4D.h"

namespace V3D::V3DEngine::V3DMathematics
{
	V3DVector4D::V3DVector4D(const float x, const float y, const float z, const float w) : x{ x }, y{ y }, z{ z }, w{ w }
	{}

	V3DVector4D::V3DVector4D(const float scale) : x{ scale }, y{ scale }, z{ scale }, w{ scale }
	{}

	bool V3DVector4D::operator==(const V3DVector4D& value) const
	{
		return (x == value.x && y == value.y && z == value.z && w == value.w);
	}

	bool V3DVector4D::operator!=(const V3DVector4D& value) const
	{
		return (x != value.x || y != value.y || z != value.z || w != value.w);
	}

	V3DVector4D V3DVector4D::operator+(const V3DVector4D& value) const
	{
		return V3DVector4D(x + value.x, y + value.y, z + value.z, w + value.w);
	}

	V3DVector4D V3DVector4D::operator+(const float size) const
	{
		return V3DVector4D(x + size, y + size, z + size, w + size);
	}

	V3DVector4D V3DVector4D::operator-(const V3DVector4D& value) const
	{
		return V3DVector4D(x - value.x, y - value.y, z - value.z, w - value.w);
	}

	V3DVector4D V3DVector4D::operator-(const float size) const
	{
		return V3DVector4D(x - size, y - size, z - size, w - size);
	}

	V3DVector4D V3DVector4D::operator*(const V3DVector4D& value) const
	{
		return V3DVector4D(x * value.x, y * value.y, z * value.z, w * value.w);
	}

	V3DVector4D V3DVector4D::operator*(const float size) const
	{
		return V3DVector4D(x * size, y * size, z * size, w * size);
	}

	V3DVector4D V3DVector4D::operator/(const V3DVector4D& value) const
	{
		return V3DVector4D(x / value.x, y / value.y, z / value.z, w / value.w);
	}

	V3DVector4D V3DVector4D::operator/(const float size) const
	{
		return V3DVector4D(x / size, y / size, z / size, w / size);
	}

	V3DVector4D V3DVector4D::operator-() const
	{
		return V3DVector4D(-x, -y, -z, -w);
	}

	V3DVector4D& V3DVector4D::operator++()
	{
		++x;
		++y;
		++z;
		++w;

		return *this;
	}

	V3DVector4D& V3DVector4D::operator++(int)
	{
		x++;
		y++;
		z++;
		w++;

		return *this;
	}

	V3DVector4D& V3DVector4D::operator--()
	{
		--x;
		--y;
		--z;
		--w;

		return *this;
	}

	V3DVector4D& V3DVector4D::operator--(int)
	{
		x--;
		y--;
		z--;
		w--;

		return *this;
	}

	V3DVector4D& V3DVector4D::operator+=(const V3DVector4D& value)
	{
		x += value.x;
		y += value.y;
		z += value.z;
		w += value.w;

		return *this;
	}

	V3DVector4D& V3DVector4D::operator+=(const float size)
	{
		x += size;
		y += size;
		z += size;
		w += size;

		return *this;
	}

	V3DVector4D& V3DVector4D::operator-=(const V3DVector4D& value)
	{
		x -= value.x;
		y -= value.y;
		z -= value.z;
		w -= value.w;

		return *this;
	}

	V3DVector4D& V3DVector4D::operator-=(const float size)
	{
		x -= size;
		y -= size;
		z -= size;
		w -= size;

		return *this;
	}

	V3DVector4D& V3DVector4D::operator*=(const V3DVector4D& value)
	{
		x *= value.x;
		y *= value.y;
		z *= value.z;
		w *= value.w;

		return *this;
	}

	V3DVector4D& V3DVector4D::operator*=(const float size)
	{
		x *= size;
		y *= size;
		z *= size;
		w *= size;

		return *this;
	}

	V3DVector4D& V3DVector4D::operator/=(const V3DVector4D& value)
	{
		x /= value.x;
		y /= value.y;
		z /= value.z;
		w /= value.w;

		return *this;
	}

	V3DVector4D& V3DVector4D::operator/=(const float size)
	{
		x /= size;
		y /= size;
		z /= size;
		w /= size;

		return *this;
	}

	bool V3DVector4D::operator<(const V3DVector4D& value) const
	{
		if (x < value.x && y < value.y && z < value.z && w < value.w) 
			return true;

		return false;
	}

	bool V3DVector4D::operator>(const V3DVector4D& value) const
	{
		if (x > value.x&& y > value.y&& z > value.z&& w > value.w) 
			return true;

		return false;
	}

	void V3DVector4D::Zero()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
		w = 0.0f;
	}

	float V3DVector4D::DotProduct(const V3DVector4D& value) const
	{
		return x * value.x + y * value.y + z * value.z + w * value.w;
	}
}
