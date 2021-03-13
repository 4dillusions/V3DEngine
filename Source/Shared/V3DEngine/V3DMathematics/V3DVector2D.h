/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DEngineLibrary.h"

namespace V3D::V3DEngine::V3DMathematics
{
	//2D Vector and math calculations
	class V3DENGINE_API V3DVector2D final
	{
	public:
		float x{ 0.0f }, y{ 0.0f };

		V3DVector2D() = default;
		explicit V3DVector2D(float scale);
		V3DVector2D(float x, float y);
		V3DVector2D(const V3DVector2D&) = default;
		V3DVector2D(V3DVector2D&&) = default;
		~V3DVector2D() = default;

		V3DVector2D& operator=(const V3DVector2D&) = default;
		V3DVector2D& operator=(V3DVector2D&&) = default;

		bool operator==(const V3DVector2D& value) const;
		bool operator!=(const V3DVector2D& value) const;

		V3DVector2D operator+(const V3DVector2D& value) const;
		V3DVector2D operator+(float size) const;

		V3DVector2D operator-(const V3DVector2D& value) const;
		V3DVector2D operator-(float size) const;

		V3DVector2D operator*(const V3DVector2D& value) const;
		V3DVector2D operator*(float size) const;

		V3DVector2D operator/(const V3DVector2D& value) const;
		V3DVector2D operator/(float size) const;

		V3DVector2D operator-() const;

		const V3DVector2D& operator++();
		const V3DVector2D& operator++(int);
		const V3DVector2D& operator--();
		const V3DVector2D& operator--(int);

		V3DVector2D& operator+=(const V3DVector2D& value);
		V3DVector2D& operator+=(float size);

		V3DVector2D& operator-=(const V3DVector2D& value);
		V3DVector2D& operator-=(float size);

		V3DVector2D& operator*=(const V3DVector2D& value);
		V3DVector2D& operator*=(float size);

		V3DVector2D& operator/=(const V3DVector2D& value);
		V3DVector2D& operator/=(float size);

		bool operator<(const V3DVector2D& value) const;
		bool operator>(const V3DVector2D& value) const;

		void Zero();
		void Up();
		void Down();
		void Left();
		void Right();
		void Rotate(float angle);
		void RotateCeil(float angle);
		void Rotate90DegreeForward();
		void Rotate90DegreeBackward();

		[[nodiscard]] float Length() const;
		[[nodiscard]] float Distance(const V3DVector2D& value) const;
		[[nodiscard]] float DotProduct(const V3DVector2D& value) const;
		[[nodiscard]] float CrossProduct(const V3DVector2D& value) const;
		float Normalise();
		void Normalizing();
		[[nodiscard]] V3DVector2D MidPoint(const V3DVector2D& value) const;
	};
}
