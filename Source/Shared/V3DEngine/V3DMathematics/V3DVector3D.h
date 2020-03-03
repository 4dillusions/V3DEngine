/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DEngineLibrary.h"

namespace V3D::V3DEngine::V3DMathematics
{
	//3D Vector and math calculations
	class V3DENGINE_API V3DVector3D final
	{
	public:
		float x = 0.0f, y = 0.0f, z = 0.0f;

		V3DVector3D() = default;
		explicit V3DVector3D(float scale);
		V3DVector3D(float x, float y, float z);
		V3DVector3D(const V3DVector3D&) = default;
		V3DVector3D(V3DVector3D&&) = default;
		~V3DVector3D() = default;

		V3DVector3D& operator=(const V3DVector3D&) = default;
		V3DVector3D& operator=(V3DVector3D&&) = default;

		bool operator==(const V3DVector3D& value) const;
		bool operator!=(const V3DVector3D& value) const;

		V3DVector3D operator+(const V3DVector3D& value) const;
		V3DVector3D operator+(float size) const;

		V3DVector3D operator-(const V3DVector3D& value) const;
		V3DVector3D operator-(float size) const;

		V3DVector3D operator*(const V3DVector3D& value) const;
		V3DVector3D operator*(float size) const;

		V3DVector3D operator/(const V3DVector3D& value) const;
		V3DVector3D operator/(float size) const;

		V3DVector3D operator-() const;

		V3DVector3D& operator++();
		V3DVector3D& operator++(int);
		V3DVector3D& operator--();
		V3DVector3D& operator--(int);

		V3DVector3D& operator+=(const V3DVector3D& value);
		V3DVector3D& operator+=(float size);

		V3DVector3D& operator-=(const V3DVector3D& value);
		V3DVector3D& operator-=(float size);

		V3DVector3D& operator*=(const V3DVector3D& value);
		V3DVector3D& operator*=(float size);

		V3DVector3D& operator/=(const V3DVector3D& value);
		V3DVector3D& operator/=(float size);

		bool operator<(const V3DVector3D& value) const;
		bool operator>(const V3DVector3D& value) const;

		void Zero();
		[[nodiscard]] float Length() const;
		[[nodiscard]] float Distance(const V3DVector3D& value) const;
		[[nodiscard]] float DotProduct(const V3DVector3D& value) const;
		[[nodiscard]] V3DVector3D CrossProduct(const V3DVector3D& value) const;
		float Normalise();
		void Normalizing();
		[[nodiscard]] V3DVector3D MidPoint(const V3DVector3D& value) const;
	};
}
