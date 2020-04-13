/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DEngineLibraryPlatform.h"

namespace V3D::V3DEngine::V3DMathematics
{
	//4D Vector and math calculations
	class V3DENGINE_API V3DVector4D final
	{
	public:
		float x{ 0 }, y{ 0 }, z{ 0 }, w{ 0 };

		V3DVector4D() = default;
		explicit V3DVector4D(float scale);
		V3DVector4D(float x, float y, float z, float w);
		V3DVector4D(const V3DVector4D&) = default;
		V3DVector4D(V3DVector4D&&) = default;
		~V3DVector4D() = default;

		V3DVector4D& operator=(const V3DVector4D&) = default;
		V3DVector4D& operator=(V3DVector4D&&) = default;

		bool operator==(const V3DVector4D& value) const;
		bool operator!=(const V3DVector4D& value) const;

		V3DVector4D operator+(const V3DVector4D& value) const;
		V3DVector4D operator+(float size) const;

		V3DVector4D operator-(const V3DVector4D& value) const;
		V3DVector4D operator-(float size) const;

		V3DVector4D operator*(const V3DVector4D& value) const;
		V3DVector4D operator*(float size) const;

		V3DVector4D operator/(const V3DVector4D& value) const;
		V3DVector4D operator/(float size) const;

		V3DVector4D operator-() const;

		const V3DVector4D& operator++();
		const V3DVector4D& operator++(int);
		const V3DVector4D& operator--();
		const V3DVector4D& operator--(int);

		V3DVector4D& operator+=(const V3DVector4D& value);
		V3DVector4D& operator+=(float size);

		V3DVector4D& operator-=(const V3DVector4D& value);
		V3DVector4D& operator-=(float size);

		V3DVector4D& operator*=(const V3DVector4D& value);
		V3DVector4D& operator*=(float size);

		V3DVector4D& operator/=(const V3DVector4D& value);
		V3DVector4D& operator/=(float size);

		bool operator<(const V3DVector4D& value) const;
		bool operator>(const V3DVector4D& value) const;

		void Zero();
		[[nodiscard]] float DotProduct(const V3DVector4D& value) const;
	};
}
