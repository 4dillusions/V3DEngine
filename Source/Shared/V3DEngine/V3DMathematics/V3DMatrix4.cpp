/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DMatrix4.h"
#include "V3DMatrix3.h"
#include "V3DVector2D.h"
#include "V3DVector3D.h"
#include "V3DVector4D.h"

#include <cmath>

namespace V3D::V3DEngine::V3DMathematics
{
	V3DMatrix4::V3DMatrix4(
		float m00, float m01, float m02, float m03,
		float m10, float m11, float m12, float m13,
		float m20, float m21, float m22, float m23,
		float m30, float m31, float m32, float m33)
	{
		m[0][0] = m00;
		m[0][1] = m01;
		m[0][2] = m02;
		m[0][3] = m03;
		m[1][0] = m10;
		m[1][1] = m11;
		m[1][2] = m12;
		m[1][3] = m13;
		m[2][0] = m20;
		m[2][1] = m21;
		m[2][2] = m22;
		m[2][3] = m23;
		m[3][0] = m30;
		m[3][1] = m31;
		m[3][2] = m32;
		m[3][3] = m33;
	}

	V3DMatrix4::V3DMatrix4(const V3DMatrix3& value)
	{
		Identity();
		*this = value;
	}

	V3DMatrix4& V3DMatrix4::operator=(const V3DMatrix4& value)
	{
		m[0][0] = value.m[0][0];
		m[0][1] = value.m[0][1];
		m[0][2] = value.m[0][2];
		m[0][3] = value.m[0][3];

		m[1][0] = value.m[1][0];
		m[1][1] = value.m[1][1];
		m[1][2] = value.m[1][2];
		m[1][3] = value.m[1][3];

		m[2][0] = value.m[2][0];
		m[2][1] = value.m[2][1];
		m[2][2] = value.m[2][2];
		m[2][3] = value.m[2][3];

		m[3][0] = value.m[3][0];
		m[3][1] = value.m[3][1];
		m[3][2] = value.m[3][2];
		m[3][3] = value.m[3][3];

		return *this;
	}

	V3DMatrix4& V3DMatrix4::operator=(const V3DMatrix3& value)
	{
		m[0][0] = value(0, 0); m[0][1] = value(0, 1); m[0][2] = value(0, 2);
		m[1][0] = value(1, 0); m[1][1] = value(1, 1); m[1][2] = value(1, 2);
		m[2][0] = value(2, 0); m[2][1] = value(2, 1); m[2][2] = value(2, 2);

		return *this;
	}

	float V3DMatrix4::operator() (int indexX, int indexY) const
	{
		return m[indexX][indexY];
	}

	float& V3DMatrix4::operator() (int indexX, int indexY)
	{
		return m[indexX][indexY];
	}

	V3DMatrix4 V3DMatrix4::operator*(const V3DMatrix4& value) const
	{
		V3DMatrix4 result;

		result.m[0][0] = m[0][0] * value.m[0][0] + m[0][1] * value.m[1][0] + m[0][2] * value.m[2][0] + m[0][3] * value.m[3][0];
		result.m[0][1] = m[0][0] * value.m[0][1] + m[0][1] * value.m[1][1] + m[0][2] * value.m[2][1] + m[0][3] * value.m[3][1];
		result.m[0][2] = m[0][0] * value.m[0][2] + m[0][1] * value.m[1][2] + m[0][2] * value.m[2][2] + m[0][3] * value.m[3][2];
		result.m[0][3] = m[0][0] * value.m[0][3] + m[0][1] * value.m[1][3] + m[0][2] * value.m[2][3] + m[0][3] * value.m[3][3];

		result.m[1][0] = m[1][0] * value.m[0][0] + m[1][1] * value.m[1][0] + m[1][2] * value.m[2][0] + m[1][3] * value.m[3][0];
		result.m[1][1] = m[1][0] * value.m[0][1] + m[1][1] * value.m[1][1] + m[1][2] * value.m[2][1] + m[1][3] * value.m[3][1];
		result.m[1][2] = m[1][0] * value.m[0][2] + m[1][1] * value.m[1][2] + m[1][2] * value.m[2][2] + m[1][3] * value.m[3][2];
		result.m[1][3] = m[1][0] * value.m[0][3] + m[1][1] * value.m[1][3] + m[1][2] * value.m[2][3] + m[1][3] * value.m[3][3];

		result.m[2][0] = m[2][0] * value.m[0][0] + m[2][1] * value.m[1][0] + m[2][2] * value.m[2][0] + m[2][3] * value.m[3][0];
		result.m[2][1] = m[2][0] * value.m[0][1] + m[2][1] * value.m[1][1] + m[2][2] * value.m[2][1] + m[2][3] * value.m[3][1];
		result.m[2][2] = m[2][0] * value.m[0][2] + m[2][1] * value.m[1][2] + m[2][2] * value.m[2][2] + m[2][3] * value.m[3][2];
		result.m[2][3] = m[2][0] * value.m[0][3] + m[2][1] * value.m[1][3] + m[2][2] * value.m[2][3] + m[2][3] * value.m[3][3];

		result.m[3][0] = m[3][0] * value.m[0][0] + m[3][1] * value.m[1][0] + m[3][2] * value.m[2][0] + m[3][3] * value.m[3][0];
		result.m[3][1] = m[3][0] * value.m[0][1] + m[3][1] * value.m[1][1] + m[3][2] * value.m[2][1] + m[3][3] * value.m[3][1];
		result.m[3][2] = m[3][0] * value.m[0][2] + m[3][1] * value.m[1][2] + m[3][2] * value.m[2][2] + m[3][3] * value.m[3][2];
		result.m[3][3] = m[3][0] * value.m[0][3] + m[3][1] * value.m[1][3] + m[3][2] * value.m[2][3] + m[3][3] * value.m[3][3];

		return result;
	}

	V3DMatrix4 V3DMatrix4::operator+(const V3DMatrix4& value) const
	{
		V3DMatrix4 result;

		result.m[0][0] = m[0][0] + value.m[0][0];
		result.m[0][1] = m[0][1] + value.m[0][1];
		result.m[0][2] = m[0][2] + value.m[0][2];
		result.m[0][3] = m[0][3] + value.m[0][3];

		result.m[1][0] = m[1][0] + value.m[1][0];
		result.m[1][1] = m[1][1] + value.m[1][1];
		result.m[1][2] = m[1][2] + value.m[1][2];
		result.m[1][3] = m[1][3] + value.m[1][3];

		result.m[2][0] = m[2][0] + value.m[2][0];
		result.m[2][1] = m[2][1] + value.m[2][1];
		result.m[2][2] = m[2][2] + value.m[2][2];
		result.m[2][3] = m[2][3] + value.m[2][3];

		result.m[3][0] = m[3][0] + value.m[3][0];
		result.m[3][1] = m[3][1] + value.m[3][1];
		result.m[3][2] = m[3][2] + value.m[3][2];
		result.m[3][3] = m[3][3] + value.m[3][3];

		return result;
	}

	V3DMatrix4 V3DMatrix4::operator-(const V3DMatrix4& value) const
	{
		V3DMatrix4 result;

		result.m[0][0] = m[0][0] - value.m[0][0];
		result.m[0][1] = m[0][1] - value.m[0][1];
		result.m[0][2] = m[0][2] - value.m[0][2];
		result.m[0][3] = m[0][3] - value.m[0][3];

		result.m[1][0] = m[1][0] - value.m[1][0];
		result.m[1][1] = m[1][1] - value.m[1][1];
		result.m[1][2] = m[1][2] - value.m[1][2];
		result.m[1][3] = m[1][3] - value.m[1][3];

		result.m[2][0] = m[2][0] - value.m[2][0];
		result.m[2][1] = m[2][1] - value.m[2][1];
		result.m[2][2] = m[2][2] - value.m[2][2];
		result.m[2][3] = m[2][3] - value.m[2][3];

		result.m[3][0] = m[3][0] - value.m[3][0];
		result.m[3][1] = m[3][1] - value.m[3][1];
		result.m[3][2] = m[3][2] - value.m[3][2];
		result.m[3][3] = m[3][3] - value.m[3][3];

		return result;
	}

	bool V3DMatrix4::operator==(const V3DMatrix4& value) const
	{
		if (m[0][0] != value.m[0][0] || m[0][1] != value.m[0][1] || m[0][2] != value.m[0][2] || m[0][3] != value.m[0][3] ||
			m[1][0] != value.m[1][0] || m[1][1] != value.m[1][1] || m[1][2] != value.m[1][2] || m[1][3] != value.m[1][3] ||
			m[2][0] != value.m[2][0] || m[2][1] != value.m[2][1] || m[2][2] != value.m[2][2] || m[2][3] != value.m[2][3] ||
			m[3][0] != value.m[3][0] || m[3][1] != value.m[3][1] || m[3][2] != value.m[3][2] || m[3][3] != value.m[3][3])
			return false;

		return true;
	}

	bool V3DMatrix4::operator!=(const V3DMatrix4& value) const
	{
		if (m[0][0] != value.m[0][0] || m[0][1] != value.m[0][1] || m[0][2] != value.m[0][2] || m[0][3] != value.m[0][3] ||
			m[1][0] != value.m[1][0] || m[1][1] != value.m[1][1] || m[1][2] != value.m[1][2] || m[1][3] != value.m[1][3] ||
			m[2][0] != value.m[2][0] || m[2][1] != value.m[2][1] || m[2][2] != value.m[2][2] || m[2][3] != value.m[2][3] ||
			m[3][0] != value.m[3][0] || m[3][1] != value.m[3][1] || m[3][2] != value.m[3][2] || m[3][3] != value.m[3][3])
			return true;

		return false;
	}

	V3DVector3D V3DMatrix4::operator*(const V3DVector3D& vector) const
	{
		V3DVector3D result;

		const float inv = 1.0f / (m[3][0] * vector.x + m[3][1] * vector.y + m[3][2] * vector.z + m[3][3]);

		result.x = (m[0][0] * vector.x + m[0][1] * vector.y + m[0][2] * vector.z + m[0][3]) * inv;
		result.y = (m[1][0] * vector.x + m[1][1] * vector.y + m[1][2] * vector.z + m[1][3]) * inv;
		result.z = (m[2][0] * vector.x + m[2][1] * vector.y + m[2][2] * vector.z + m[2][3]) * inv;

		return result;
	}

	V3DVector4D V3DMatrix4::operator*(const V3DVector4D& vector) const
	{
		return V3DVector4D(
			m[0][0] * vector.x + m[0][1] * vector.y + m[0][2] * vector.z + m[0][3] * vector.w,
			m[1][0] * vector.x + m[1][1] * vector.y + m[1][2] * vector.z + m[1][3] * vector.w,
			m[2][0] * vector.x + m[2][1] * vector.y + m[2][2] * vector.z + m[2][3] * vector.w,
			m[3][0] * vector.x + m[3][1] * vector.y + m[3][2] * vector.z + m[3][3] * vector.w
		);
	}

	V3DMatrix4 V3DMatrix4::operator*(float scalar) const
	{
		return V3DMatrix4(
			scalar * m[0][0], scalar * m[0][1], scalar * m[0][2], scalar * m[0][3],
			scalar * m[1][0], scalar * m[1][1], scalar * m[1][2], scalar * m[1][3],
			scalar * m[2][0], scalar * m[2][1], scalar * m[2][2], scalar * m[2][3],
			scalar * m[3][0], scalar * m[3][1], scalar * m[3][2], scalar * m[3][3]);
	}

	void V3DMatrix4::SetTranslation(const V3DVector2D& vector)
	{
		m[0][3] = vector.x;
		m[1][3] = vector.y;
		m[2][3] = 0;
	}

	void V3DMatrix4::SetTranslation(const V3DVector3D& vector)
	{
		m[0][3] = vector.x;
		m[1][3] = vector.y;
		m[2][3] = vector.z;
	}

	void V3DMatrix4::SetRotationYaw(float yaw)
	{
		m[0][0] = cosf(yaw); m[0][2] = -sinf(yaw);
		m[2][0] = sinf(yaw); m[2][2] = cosf(yaw);
	}

	void V3DMatrix4::SetRotationPitch(float pitch)
	{
		m[1][1] = cosf(pitch); m[1][2] = sinf(pitch);
		m[2][1] = -sinf(pitch); m[2][2] = cosf(pitch);
	}

	void V3DMatrix4::SetRotationRoll(float roll)
	{
		m[0][0] = cosf(roll); m[0][1] = sinf(roll);
		m[1][0] = -sinf(roll); m[1][1] = cosf(roll);
	}

	V3DVector2D V3DMatrix4::GetTranslation2D()
	{
		return V3DVector2D(m[0][3], m[1][3]);
	}

	V3DVector3D V3DMatrix4::GetTranslation3D()
	{
		return V3DVector3D(m[0][3], m[1][3], m[2][3]);
	}

	V3DMatrix4 V3DMatrix4::GetTranslation(const V3DVector3D& vector)
	{
		V3DMatrix4 result;

		result.m[0][0] = 1.0; result.m[0][1] = 0.0; result.m[0][2] = 0.0; result.m[0][3] = vector.x;
		result.m[1][0] = 0.0; result.m[1][1] = 1.0; result.m[1][2] = 0.0; result.m[1][3] = vector.y;
		result.m[2][0] = 0.0; result.m[2][1] = 0.0; result.m[2][2] = 1.0; result.m[2][3] = vector.z;
		result.m[3][0] = 0.0; result.m[3][1] = 0.0; result.m[3][2] = 0.0; result.m[3][3] = 1.0;

		return result;
	}

	V3DMatrix4 V3DMatrix4::GetTranslation(const V3DVector2D& vector)
	{
		V3DMatrix4 result;

		result.m[0][0] = 1.0; result.m[0][1] = 0.0; result.m[0][2] = 0.0; result.m[0][3] = vector.x;
		result.m[1][0] = 0.0; result.m[1][1] = 1.0; result.m[1][2] = 0.0; result.m[1][3] = vector.y;
		result.m[2][0] = 0.0; result.m[2][1] = 0.0; result.m[2][2] = 1.0; result.m[2][3] = 0;
		result.m[3][0] = 0.0; result.m[3][1] = 0.0; result.m[3][2] = 0.0; result.m[3][3] = 1.0;

		return result;
	}

	void V3DMatrix4::MakeTranslation(const V3DVector2D& vector)
	{
		m[0][0] = 1.0; m[0][1] = 0.0; m[0][2] = 0.0; m[0][3] = vector.x;
		m[1][0] = 0.0; m[1][1] = 1.0; m[1][2] = 0.0; m[1][3] = vector.y;
		m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = 1.0; m[2][3] = 0;
		m[3][0] = 0.0; m[3][1] = 0.0; m[3][2] = 0.0; m[3][3] = 1.0;
	}

	void V3DMatrix4::MakeTranslation(const V3DVector3D& vector)
	{
		m[0][0] = 1.0; m[0][1] = 0.0; m[0][2] = 0.0; m[0][3] = vector.x;
		m[1][0] = 0.0; m[1][1] = 1.0; m[1][2] = 0.0; m[1][3] = vector.y;
		m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = 1.0; m[2][3] = vector.z;
		m[3][0] = 0.0; m[3][1] = 0.0; m[3][2] = 0.0; m[3][3] = 1.0;
	}

	void V3DMatrix4::SetScale(const V3DVector3D& vector)
	{
		m[0][0] = vector.x;
		m[1][1] = vector.y;
		m[2][2] = vector.z;
	}

	V3DMatrix4 V3DMatrix4::GetScale(const V3DVector3D& vector)
	{
		V3DMatrix4 result;

		result.m[0][0] = vector.x; result.m[0][1] = 0.0; result.m[0][2] = 0.0; result.m[0][3] = 0.0;
		result.m[1][0] = 0.0; result.m[1][1] = vector.y; result.m[1][2] = 0.0; result.m[1][3] = 0.0;
		result.m[2][0] = 0.0; result.m[2][1] = 0.0; result.m[2][2] = vector.z; result.m[2][3] = 0.0;
		result.m[3][0] = 0.0; result.m[3][1] = 0.0; result.m[3][2] = 0.0; result.m[3][3] = 1.0;

		return result;
	}

	bool V3DMatrix4::IsHasScale()
	{
		const auto RealEqual = [](float a, float b, float tolerance) { return (fabs(b - a) <= tolerance) ? true : false; };

		float t = m[0][0] * m[0][0] + m[1][0] * m[1][0] + m[2][0] * m[2][0];
		if (!RealEqual(t, 1.0f, 1e-04f))
			return true;

		t = m[0][1] * m[0][1] + m[1][1] * m[1][1] + m[2][1] * m[2][1];
		if (!RealEqual(t, 1.0f, 1e-04f))
			return true;

		t = m[0][2] * m[0][2] + m[1][2] * m[1][2] + m[2][2] * m[2][2];
		if (!RealEqual(t, 1.0f, 1e-04f))
			return true;

		return false;
	}

	bool V3DMatrix4::IsAffine() const
	{
		return m[3][0] == 0 && m[3][1] == 0 && m[3][2] == 0 && m[3][3] == 1;
	}

	V3DMatrix4 V3DMatrix4::InverseAffine() const
	{
		const float m10 = m[1][0], m11 = m[1][1], m12 = m[1][2];
		const float m20 = m[2][0], m21 = m[2][1], m22 = m[2][2];

		float t00 = m22 * m11 - m21 * m12;
		float t10 = m20 * m12 - m22 * m10;
		float t20 = m21 * m10 - m20 * m11;

		float m00 = m[0][0], m01 = m[0][1], m02 = m[0][2];

		const float invDet = 1 / (m00 * t00 + m01 * t10 + m02 * t20);

		t00 *= invDet; t10 *= invDet; t20 *= invDet;

		m00 *= invDet; m01 *= invDet; m02 *= invDet;

		const float r00 = t00;
		const float r01 = m02 * m21 - m01 * m22;
		const float r02 = m01 * m12 - m02 * m11;

		const float r10 = t10;
		const float r11 = m00 * m22 - m02 * m20;
		const float r12 = m02 * m10 - m00 * m12;

		const float r20 = t20;
		const float r21 = m01 * m20 - m00 * m21;
		const float r22 = m00 * m11 - m01 * m10;

		const float m03 = m[0][3], m13 = m[1][3], m23 = m[2][3];

		const float r03 = -(r00 * m03 + r01 * m13 + r02 * m23);
		const float r13 = -(r10 * m03 + r11 * m13 + r12 * m23);
		const float r23 = -(r20 * m03 + r21 * m13 + r22 * m23);

		return V3DMatrix4(
			r00, r01, r02, r03,
			r10, r11, r12, r13,
			r20, r21, r22, r23,
			0, 0, 0, 1);
	}

	V3DMatrix4 V3DMatrix4::ConcatenateAffine(const V3DMatrix4& value) const
	{
		return V3DMatrix4(
			m[0][0] * value.m[0][0] + m[0][1] * value.m[1][0] + m[0][2] * value.m[2][0],
			m[0][0] * value.m[0][1] + m[0][1] * value.m[1][1] + m[0][2] * value.m[2][1],
			m[0][0] * value.m[0][2] + m[0][1] * value.m[1][2] + m[0][2] * value.m[2][2],
			m[0][0] * value.m[0][3] + m[0][1] * value.m[1][3] + m[0][2] * value.m[2][3] + m[0][3],

			m[1][0] * value.m[0][0] + m[1][1] * value.m[1][0] + m[1][2] * value.m[2][0],
			m[1][0] * value.m[0][1] + m[1][1] * value.m[1][1] + m[1][2] * value.m[2][1],
			m[1][0] * value.m[0][2] + m[1][1] * value.m[1][2] + m[1][2] * value.m[2][2],
			m[1][0] * value.m[0][3] + m[1][1] * value.m[1][3] + m[1][2] * value.m[2][3] + m[1][3],

			m[2][0] * value.m[0][0] + m[2][1] * value.m[1][0] + m[2][2] * value.m[2][0],
			m[2][0] * value.m[0][1] + m[2][1] * value.m[1][1] + m[2][2] * value.m[2][1],
			m[2][0] * value.m[0][2] + m[2][1] * value.m[1][2] + m[2][2] * value.m[2][2],
			m[2][0] * value.m[0][3] + m[2][1] * value.m[1][3] + m[2][2] * value.m[2][3] + m[2][3],

			0, 0, 0, 1);
	}

	V3DVector3D V3DMatrix4::TransformAffine(const V3DVector3D& vector) const
	{
		return V3DVector3D(
			m[0][0] * vector.x + m[0][1] * vector.y + m[0][2] * vector.z + m[0][3],
			m[1][0] * vector.x + m[1][1] * vector.y + m[1][2] * vector.z + m[1][3],
			m[2][0] * vector.x + m[2][1] * vector.y + m[2][2] * vector.z + m[2][3]);
	}

	V3DVector4D V3DMatrix4::TransformAffine(const V3DVector4D& vector) const
	{
		return V3DVector4D(
			m[0][0] * vector.x + m[0][1] * vector.y + m[0][2] * vector.z + m[0][3] * vector.w,
			m[1][0] * vector.x + m[1][1] * vector.y + m[1][2] * vector.z + m[1][3] * vector.w,
			m[2][0] * vector.x + m[2][1] * vector.y + m[2][2] * vector.z + m[2][3] * vector.w,
			vector.w);
	}

	V3DMatrix4 V3DMatrix4::Concatenate(const V3DMatrix4& value) const
	{
		V3DMatrix4 result;

		result.m[0][0] = m[0][0] * value.m[0][0] + m[0][1] * value.m[1][0] + m[0][2] * value.m[2][0] + m[0][3] * value.m[3][0];
		result.m[0][1] = m[0][0] * value.m[0][1] + m[0][1] * value.m[1][1] + m[0][2] * value.m[2][1] + m[0][3] * value.m[3][1];
		result.m[0][2] = m[0][0] * value.m[0][2] + m[0][1] * value.m[1][2] + m[0][2] * value.m[2][2] + m[0][3] * value.m[3][2];
		result.m[0][3] = m[0][0] * value.m[0][3] + m[0][1] * value.m[1][3] + m[0][2] * value.m[2][3] + m[0][3] * value.m[3][3];

		result.m[1][0] = m[1][0] * value.m[0][0] + m[1][1] * value.m[1][0] + m[1][2] * value.m[2][0] + m[1][3] * value.m[3][0];
		result.m[1][1] = m[1][0] * value.m[0][1] + m[1][1] * value.m[1][1] + m[1][2] * value.m[2][1] + m[1][3] * value.m[3][1];
		result.m[1][2] = m[1][0] * value.m[0][2] + m[1][1] * value.m[1][2] + m[1][2] * value.m[2][2] + m[1][3] * value.m[3][2];
		result.m[1][3] = m[1][0] * value.m[0][3] + m[1][1] * value.m[1][3] + m[1][2] * value.m[2][3] + m[1][3] * value.m[3][3];

		result.m[2][0] = m[2][0] * value.m[0][0] + m[2][1] * value.m[1][0] + m[2][2] * value.m[2][0] + m[2][3] * value.m[3][0];
		result.m[2][1] = m[2][0] * value.m[0][1] + m[2][1] * value.m[1][1] + m[2][2] * value.m[2][1] + m[2][3] * value.m[3][1];
		result.m[2][2] = m[2][0] * value.m[0][2] + m[2][1] * value.m[1][2] + m[2][2] * value.m[2][2] + m[2][3] * value.m[3][2];
		result.m[2][3] = m[2][0] * value.m[0][3] + m[2][1] * value.m[1][3] + m[2][2] * value.m[2][3] + m[2][3] * value.m[3][3];

		result.m[3][0] = m[3][0] * value.m[0][0] + m[3][1] * value.m[1][0] + m[3][2] * value.m[2][0] + m[3][3] * value.m[3][0];
		result.m[3][1] = m[3][0] * value.m[0][1] + m[3][1] * value.m[1][1] + m[3][2] * value.m[2][1] + m[3][3] * value.m[3][1];
		result.m[3][2] = m[3][0] * value.m[0][2] + m[3][1] * value.m[1][2] + m[3][2] * value.m[2][2] + m[3][3] * value.m[3][2];
		result.m[3][3] = m[3][0] * value.m[0][3] + m[3][1] * value.m[1][3] + m[3][2] * value.m[2][3] + m[3][3] * value.m[3][3];

		return result;
	}

	V3DMatrix4 V3DMatrix4::Inverse() const
	{
		const float m00 = m[0][0], m01 = m[0][1], m02 = m[0][2], m03 = m[0][3];
		const float m10 = m[1][0], m11 = m[1][1], m12 = m[1][2], m13 = m[1][3];
		const float m20 = m[2][0], m21 = m[2][1], m22 = m[2][2], m23 = m[2][3];
		const float m30 = m[3][0], m31 = m[3][1], m32 = m[3][2], m33 = m[3][3];

		float v0 = m20 * m31 - m21 * m30;
		float v1 = m20 * m32 - m22 * m30;
		float v2 = m20 * m33 - m23 * m30;
		float v3 = m21 * m32 - m22 * m31;
		float v4 = m21 * m33 - m23 * m31;
		float v5 = m22 * m33 - m23 * m32;

		const float t00 = +(v5 * m11 - v4 * m12 + v3 * m13);
		const float t10 = -(v5 * m10 - v2 * m12 + v1 * m13);
		const float t20 = +(v4 * m10 - v2 * m11 + v0 * m13);
		const float t30 = -(v3 * m10 - v1 * m11 + v0 * m12);

		const float invDet = 1 / (t00 * m00 + t10 * m01 + t20 * m02 + t30 * m03);

		const float d00 = t00 * invDet;
		const float d10 = t10 * invDet;
		const float d20 = t20 * invDet;
		const float d30 = t30 * invDet;

		const float d01 = -(v5 * m01 - v4 * m02 + v3 * m03) * invDet;
		const float d11 = +(v5 * m00 - v2 * m02 + v1 * m03) * invDet;
		const float d21 = -(v4 * m00 - v2 * m01 + v0 * m03) * invDet;
		const float d31 = +(v3 * m00 - v1 * m01 + v0 * m02) * invDet;

		v0 = m10 * m31 - m11 * m30;
		v1 = m10 * m32 - m12 * m30;
		v2 = m10 * m33 - m13 * m30;
		v3 = m11 * m32 - m12 * m31;
		v4 = m11 * m33 - m13 * m31;
		v5 = m12 * m33 - m13 * m32;

		const float d02 = +(v5 * m01 - v4 * m02 + v3 * m03) * invDet;
		const float d12 = -(v5 * m00 - v2 * m02 + v1 * m03) * invDet;
		const float d22 = +(v4 * m00 - v2 * m01 + v0 * m03) * invDet;
		const float d32 = -(v3 * m00 - v1 * m01 + v0 * m02) * invDet;

		v0 = m21 * m10 - m20 * m11;
		v1 = m22 * m10 - m20 * m12;
		v2 = m23 * m10 - m20 * m13;
		v3 = m22 * m11 - m21 * m12;
		v4 = m23 * m11 - m21 * m13;
		v5 = m23 * m12 - m22 * m13;

		const float d03 = -(v5 * m01 - v4 * m02 + v3 * m03) * invDet;
		const float d13 = +(v5 * m00 - v2 * m02 + v1 * m03) * invDet;
		const float d23 = -(v4 * m00 - v2 * m01 + v0 * m03) * invDet;
		const float d33 = +(v3 * m00 - v1 * m01 + v0 * m02) * invDet;

		return V3DMatrix4(
			d00, d01, d02, d03,
			d10, d11, d12, d13,
			d20, d21, d22, d23,
			d30, d31, d32, d33);
	}

	V3DMatrix4 V3DMatrix4::Transpose() const
	{
		return V3DMatrix4(m[0][0], m[1][0], m[2][0], m[3][0],
			m[0][1], m[1][1], m[2][1], m[3][1],
			m[0][2], m[1][2], m[2][2], m[3][2],
			m[0][3], m[1][3], m[2][3], m[3][3]);
	}

	float V3DMatrix4::Determinant() const
	{
		const auto Minor = [](const V3DMatrix4& value, const int r0, const int r1, const int r2, const int c0, const int c1, const int c2)
		{
			return value(r0, c0) * (value(r1, c1) * value(r2, c2) - value(r2, c1) * value(r1, c2)) -
				value(r0, c1) * (value(r1, c0) * value(r2, c2) - value(r2, c0) * value(r1, c2)) +
				value(r0, c2) * (value(r1, c0) * value(r2, c1) - value(r2, c0) * value(r1, c1));
		};

		return m[0][0] * Minor(*this, 1, 2, 3, 1, 2, 3) -
			m[0][1] * Minor(*this, 1, 2, 3, 0, 2, 3) +
			m[0][2] * Minor(*this, 1, 2, 3, 0, 1, 3) -
			m[0][3] * Minor(*this, 1, 2, 3, 0, 1, 2);
	}

	void V3DMatrix4::Zero()
	{
		m[0][0] = 0; m[0][1] = 0; m[0][2] = 0; m[0][3] = 0;
		m[1][0] = 0; m[1][1] = 0; m[1][2] = 0; m[1][3] = 0;
		m[2][0] = 0; m[2][1] = 0; m[2][2] = 0; m[2][3] = 0;
		m[3][0] = 0; m[3][1] = 0; m[3][2] = 0; m[3][3] = 0;
	}

	void V3DMatrix4::Identity()
	{
		m[0][0] = 1; m[0][1] = 0; m[0][2] = 0; m[0][3] = 0;
		m[1][0] = 0; m[1][1] = 1; m[1][2] = 0; m[1][3] = 0;
		m[2][0] = 0; m[2][1] = 0; m[2][2] = 1; m[2][3] = 0;
		m[3][0] = 0; m[3][1] = 0; m[3][2] = 0; m[3][3] = 1;
	}
}
