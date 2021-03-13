/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DVector3D.h"
#include "V3DMatrix3.h"

namespace V3D::V3DEngine::V3DMathematics
{
	//2D Vector and math calculations
	class V3DENGINE_API V3DQuaternion final
	{
	public:
		float w{ 0.0f }, x{ 0.0f }, y{ 0.0f }, z{ 0.0f };

		V3DQuaternion() = default;
		V3DQuaternion(float w, float x, float y, float z);
		explicit V3DQuaternion(const V3DMatrix3 & rotMatrix);
		V3DQuaternion(const V3DQuaternion&) = default;
		V3DQuaternion(V3DQuaternion&&) = default;
		~V3DQuaternion() = default;

		V3DQuaternion& operator=(const V3DQuaternion&) = default;
		V3DQuaternion& operator=(V3DQuaternion&&) = default;

		bool operator==(const V3DQuaternion& value) const;
		bool operator!=(const V3DQuaternion& value) const;

		V3DQuaternion operator+(const V3DQuaternion& value) const;
		V3DQuaternion operator-(const V3DQuaternion& value) const;
		
		V3DQuaternion operator*(const V3DQuaternion& value) const;
		V3DQuaternion operator*(float scalar) const;

		[[nodiscard]] float Length() const;
		[[nodiscard]] float DotProduct(const V3DQuaternion& value) const;
		[[nodiscard]] float RotationAngle() const;
		[[nodiscard]] V3DVector3D RotationAxis() const;

		void ToRotationAxis(V3DVector3D& rotAxis) const;
		void FromRotationMatrix(const V3DMatrix3& rotMatrix);
		void ToRotationMatrix(V3DMatrix3& rotMatrixOut) const;
		float Normalise();
		void Normalizing();
	};
}
