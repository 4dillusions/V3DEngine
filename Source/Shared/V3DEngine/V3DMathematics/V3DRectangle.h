/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DVector2D.h"

namespace V3D::V3DEngine::V3DMathematics
{
	class V3DENGINE_API V3DRectangle final
	{
	public:
		V3DVector2D position = V3DVector2D();
		float width{ 0 }, height{ 0 };

		V3DRectangle() = default;
		V3DRectangle(const V3DRectangle&) = default;
		V3DRectangle(V3DRectangle&&) = default;
		V3DRectangle(float x, float y, float width, float height);
		V3DRectangle(const V3DVector2D& pos, const V3DVector2D& size);
		~V3DRectangle() = default;

		V3DRectangle& operator=(const V3DRectangle&) = default;
		V3DRectangle& operator=(V3DRectangle&&) = default;
		bool operator==(const V3DRectangle& value) const;
		bool operator!=(const V3DRectangle& value) const;

		float GetLeft() const;
		float GetRight() const;
		float GetTop() const;
		float GetBottom() const;
		void SetPosition(float x, float y);
		void SetPosition(const V3DVector2D& pos);
		V3DVector2D& GetPosition();
		V3DVector2D GetSize() const;
		void SetSize(const V3DVector2D& size);
		V3DVector2D GetCenter() const;

		bool Contains(float x, float y) const;
		bool Contains(const V3DVector2D& pofloat) const;
		bool Contains(const V3DRectangle& value) const;
		bool Intersects(const V3DRectangle& value) const;
	};
}
