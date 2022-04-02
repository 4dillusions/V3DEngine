/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DVector2D.h"

namespace V3D::V3DEngine::V3DMathematics
{
	class V3DENGINE_API V3DCircle final
	{
	public:
		V3DVector2D position;
		float radius;

		V3DCircle();
		V3DCircle(const V3DCircle&) = default;
		V3DCircle(V3DCircle&&) = default;
		V3DCircle(float x, float y, float radius);
		~V3DCircle() = default;

		V3DCircle& operator=(const V3DCircle&) = default;
		V3DCircle& operator=(V3DCircle&&) = default;
		bool operator==(const V3DCircle& value) const;
		bool operator!=(const V3DCircle& value) const;

		void SetPosition(float x, float y);
		void SetPosition(const V3DVector2D& pos);
		V3DVector2D& GetPosition();
		void SetRadius(float otherRadius);
		float GetRadius() const;

		bool Contains(int x, int y) const;
		bool Contains(const V3DVector2D& point) const;
		bool Contains(const V3DCircle& value) const;
		bool Intersects(const V3DCircle& value) const;
	};
}
