/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DCircle.h"

namespace V3D::V3DEngine::V3DMathematics
{
	V3DCircle::V3DCircle() : position{ 0, 0 }, radius{ 0 }
	{ }

	V3DCircle::V3DCircle(float x, float y, float radius) : position{ x, y }, radius{ radius }
	{ }

	bool V3DCircle::operator==(const V3DCircle& value) const
	{
		return (position == value.position && radius == value.radius);
	}

	bool V3DCircle::operator!=(const V3DCircle& value) const
	{
		return (position != value.position || radius != value.radius);
	}

	void V3DCircle::SetPosition(float x, float y)
	{
		position.x = x;
		position.y = y;
	}

	void V3DCircle::SetPosition(const V3DVector2D& pos)
	{
		this->position = pos;
	}

	V3DVector2D& V3DCircle::GetPosition()
	{
		return this->position;
	}

	void V3DCircle::SetRadius(float radius)
	{
		this->radius = radius;
	}

	float V3DCircle::GetRadius() const
	{
		return this->radius;
	}

	bool V3DCircle::Contains(int x, int y) const
	{
		return (((position.x - static_cast<float>(x)) * (position.x - static_cast<float>(x))) + ((position.y - static_cast<float>(y)) * (position.y - static_cast<float>(y)))) < (radius * radius);
	}

	bool V3DCircle::Contains(const V3DVector2D& point) const
	{
		return (((position.x - point.x) * (position.x - point.x)) + ((position.y - point.y) * (position.y - point.y))) < (radius * radius);
	}

	bool V3DCircle::Contains(const V3DCircle& value) const
	{
		return (((position.x - value.position.x) * (position.x - value.position.x)) + ((position.y - value.position.y) * (position.y - value.position.y))) <
			((radius - value.radius) * (radius - value.radius));
	}

	bool V3DCircle::Intersects(const V3DCircle& value) const
	{
		return (((position.x - value.position.x) * (position.x - value.position.x)) + ((position.y - value.position.y) * (position.y - value.position.y))) <
			((radius + value.radius) * (radius + value.radius));
	}
}
