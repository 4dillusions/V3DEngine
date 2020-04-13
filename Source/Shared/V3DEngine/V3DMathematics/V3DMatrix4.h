/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DEngineLibraryPlatform.h"

namespace V3D::V3DEngine::V3DMathematics
{
	class V3DMatrix3;
	class V3DVector2D;
	class V3DVector3D;
	class V3DVector4D;

	//4*4 Matrix and math calculations
	class V3DENGINE_API V3DMatrix4 final
	{
	public:
		float m[4][4] = {};

		V3DMatrix4() = default;
		V3DMatrix4(
			float m00, float m01, float m02, float m03,
			float m10, float m11, float m12, float m13,
			float m20, float m21, float m22, float m23,
			float m30, float m31, float m32, float m33);
		explicit V3DMatrix4(const V3DMatrix3& value);
		V3DMatrix4(const V3DMatrix4&) = default;
		V3DMatrix4(V3DMatrix4&&) = default;
		~V3DMatrix4() = default;

		V3DMatrix4& operator=(const V3DMatrix4& value);
		V3DMatrix4& operator=(V3DMatrix4&&) = default;
		V3DMatrix4& operator=(const V3DMatrix3& value);

		float operator() (int indexX, int indexY) const; //float a = matrix(0, 0);
		float& operator() (int indexX, int indexY); //matrix(0, 0) = 22.12;

		V3DMatrix4 operator*(const V3DMatrix4& value) const;
		V3DMatrix4 operator+(const V3DMatrix4& value) const;
		V3DMatrix4 operator-(const V3DMatrix4& value) const;

		bool operator==(const V3DMatrix4& value) const;
		bool operator!=(const V3DMatrix4& value) const;

		V3DVector3D operator*(const V3DVector3D& vector) const;
		V3DVector4D operator*(const V3DVector4D& vector) const;
		V3DMatrix4 operator*(float scalar) const;

		void SetTranslation(const V3DVector2D& vector);
		void SetTranslation(const V3DVector3D& vector);
		void SetRotationYaw(float yaw); //Y axis
		void SetRotationPitch(float pitch); //X axis
		void SetRotationRoll(float roll); //Z axis
		V3DVector2D GetTranslation2D();
		V3DVector3D GetTranslation3D();
		static V3DMatrix4 GetTranslation(const V3DVector2D& vector);
		static V3DMatrix4 GetTranslation(const V3DVector3D& vector);
		void MakeTranslation(const V3DVector2D& vector);
		void MakeTranslation(const V3DVector3D& vector);
		void SetScale(const V3DVector3D& vector);
		static V3DMatrix4 GetScale(const V3DVector3D& vector);
		bool IsHasScale();
		[[nodiscard]] bool IsAffine() const;
		[[nodiscard]] V3DMatrix4 InverseAffine() const;
		[[nodiscard]] V3DMatrix4 ConcatenateAffine(const V3DMatrix4& value) const;
		[[nodiscard]] V3DVector3D TransformAffine(const V3DVector3D& vector) const;
		[[nodiscard]] V3DVector4D TransformAffine(const V3DVector4D& vector) const;

		[[nodiscard]] V3DMatrix4 Concatenate(const V3DMatrix4& value) const;
		[[nodiscard]] V3DMatrix4 Inverse() const;
		[[nodiscard]] V3DMatrix4 Transpose() const;
		[[nodiscard]] float Determinant() const;
		void Zero();
		void Identity();
	};
}
