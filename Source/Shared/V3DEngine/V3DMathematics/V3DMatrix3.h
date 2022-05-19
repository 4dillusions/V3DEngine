/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DEngineLibrary.h"

namespace V3D::V3DEngine::V3DMathematics
{
	class V3DVector3D;

	//3*3 Matrix and math calculations
	class V3DENGINE_API V3DMatrix3 final
	{
	public:
		float m[3][3] = {};
		
		V3DMatrix3() = default;
		V3DMatrix3(
			float m00, float m01, float m02,
			float m10, float m11, float m12,
			float m20, float m21, float m22);
		V3DMatrix3(const V3DMatrix3&) = default;
		V3DMatrix3(V3DMatrix3&&) = default;
		~V3DMatrix3() = default;

		V3DMatrix3& operator=(const V3DMatrix3& value);
		V3DMatrix3& operator=(V3DMatrix3&&) = default;

		float operator() (int indexX, int indexY) const; //float a = matrix(0, 0);
		float& operator() (int indexX, int indexY); //matrix(0, 0) = 22.12;

		V3DMatrix3 operator*(const V3DMatrix3& value) const;
		V3DMatrix3 operator+(const V3DMatrix3& value) const;
		V3DMatrix3 operator-(const V3DMatrix3& value) const;

		bool operator==(const V3DMatrix3& value) const;
		bool operator!=(const V3DMatrix3& value) const;

		V3DVector3D operator*(const V3DVector3D& vector) const;
		V3DMatrix3 operator*(float scalar) const;
		bool Inverse(V3DMatrix3& inverse, float tolerance = 0.000001f) const; //1e-06
		V3DMatrix3 Inverse(float tolerance = 0.000001f) const; //1e-06
		V3DMatrix3 Transpose() const;
		float Determinant() const;
		void Orthonormalize();

		void Zero();
		void Identity();
	};
}
