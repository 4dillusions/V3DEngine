/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DMatrix3.h"
#include "V3DVector3D.h"
#include "V3DMath.h"

#include <cmath>

namespace V3D::V3DEngine::V3DMathematics
{
	V3DMatrix3::V3DMatrix3(
		float m00, float m01, float m02,
		float m10, float m11, float m12,
		float m20, float m21, float m22)
	{
		m[0][0] = m00;
		m[0][1] = m01;
		m[0][2] = m02;

		m[1][0] = m10;
		m[1][1] = m11;
		m[1][2] = m12;

		m[2][0] = m20;
		m[2][1] = m21;
		m[2][2] = m22;
	}

	V3DMatrix3& V3DMatrix3::operator=(const V3DMatrix3& value)
	{
		if (this != &value)
		{
			m[0][0] = value.m[0][0];
			m[0][1] = value.m[0][1];
			m[0][2] = value.m[0][2];

			m[1][0] = value.m[1][0];
			m[1][1] = value.m[1][1];
			m[1][2] = value.m[1][2];

			m[2][0] = value.m[2][0];
			m[2][1] = value.m[2][1];
			m[2][2] = value.m[2][2];
		}

		return *this;
	}

	float V3DMatrix3::operator() (int indexX, int indexY) const
	{
		return m[indexX][indexY];
	}

	float& V3DMatrix3::operator() (int indexX, int indexY)
	{
		return m[indexX][indexY];
	}

	V3DMatrix3 V3DMatrix3::operator*(const V3DMatrix3& value) const
	{
		V3DMatrix3 result;

		result.m[0][0] = m[0][0] * value.m[0][0] + m[0][1] * value.m[1][0] + m[0][2] * value.m[2][0];
		result.m[0][1] = m[0][0] * value.m[0][1] + m[0][1] * value.m[1][1] + m[0][2] * value.m[2][1];
		result.m[0][2] = m[0][0] * value.m[0][2] + m[0][1] * value.m[1][2] + m[0][2] * value.m[2][2];

		result.m[1][0] = m[1][0] * value.m[0][0] + m[1][1] * value.m[1][0] + m[1][2] * value.m[2][0];
		result.m[1][1] = m[1][0] * value.m[0][1] + m[1][1] * value.m[1][1] + m[1][2] * value.m[2][1];
		result.m[1][2] = m[1][0] * value.m[0][2] + m[1][1] * value.m[1][2] + m[1][2] * value.m[2][2];

		result.m[2][0] = m[2][0] * value.m[0][0] + m[2][1] * value.m[1][0] + m[2][2] * value.m[2][0];
		result.m[2][1] = m[2][0] * value.m[0][1] + m[2][1] * value.m[1][1] + m[2][2] * value.m[2][1];
		result.m[2][2] = m[2][0] * value.m[0][2] + m[2][1] * value.m[1][2] + m[2][2] * value.m[2][2];

		return result;
	}

	V3DMatrix3 V3DMatrix3::operator+(const V3DMatrix3& value) const
	{
		V3DMatrix3 result;

		result.m[0][0] = m[0][0] + value.m[0][0];
		result.m[0][1] = m[0][1] + value.m[0][1];
		result.m[0][2] = m[0][2] + value.m[0][2];

		result.m[1][0] = m[1][0] + value.m[1][0];
		result.m[1][1] = m[1][1] + value.m[1][1];
		result.m[1][2] = m[1][2] + value.m[1][2];

		result.m[2][0] = m[2][0] + value.m[2][0];
		result.m[2][1] = m[2][1] + value.m[2][1];
		result.m[2][2] = m[2][2] + value.m[2][2];

		return result;
	}

	V3DMatrix3 V3DMatrix3::operator-(const V3DMatrix3& value) const
	{
		V3DMatrix3 result;

		result.m[0][0] = m[0][0] - value.m[0][0];
		result.m[0][1] = m[0][1] - value.m[0][1];
		result.m[0][2] = m[0][2] - value.m[0][2];

		result.m[1][0] = m[1][0] - value.m[1][0];
		result.m[1][1] = m[1][1] - value.m[1][1];
		result.m[1][2] = m[1][2] - value.m[1][2];

		result.m[2][0] = m[2][0] - value.m[2][0];
		result.m[2][1] = m[2][1] - value.m[2][1];
		result.m[2][2] = m[2][2] - value.m[2][2];

		return result;
	}

	bool V3DMatrix3::operator==(const V3DMatrix3& value) const
	{
		if (!V3DMath::IsEqual(m[0][0], value.m[0][0]) || !V3DMath::IsEqual(m[0][1], value.m[0][1]) || !V3DMath::IsEqual(m[0][2], value.m[0][2]) ||
			!V3DMath::IsEqual(m[1][0], value.m[1][0]) || !V3DMath::IsEqual(m[1][1], value.m[1][1]) || !V3DMath::IsEqual(m[1][2], value.m[1][2]) ||
			!V3DMath::IsEqual(m[2][0], value.m[2][0]) || !V3DMath::IsEqual(m[2][1], value.m[2][1]) || !V3DMath::IsEqual(m[2][2], value.m[2][2]))
			return false;

		return true;
	}

	bool V3DMatrix3::operator!=(const V3DMatrix3& value) const
	{
		if (!V3DMath::IsEqual(m[0][0], value.m[0][0]) || !V3DMath::IsEqual(m[0][1], value.m[0][1]) || !V3DMath::IsEqual(m[0][2], value.m[0][2]) ||
			!V3DMath::IsEqual(m[1][0], value.m[1][0]) || !V3DMath::IsEqual(m[1][1], value.m[1][1]) || !V3DMath::IsEqual(m[1][2], value.m[1][2]) ||
			!V3DMath::IsEqual(m[2][0], value.m[2][0]) || !V3DMath::IsEqual(m[2][1], value.m[2][1]) || !V3DMath::IsEqual(m[2][2], value.m[2][2]))
			return true;

		return false;
	}

	V3DVector3D V3DMatrix3::operator*(const V3DVector3D& vector) const
	{
		V3DVector3D result;

		result.x = m[0][0] * vector.x + m[0][1] * vector.y + m[0][2] * vector.z;
		result.y = m[1][0] * vector.x + m[1][1] * vector.y + m[1][2] * vector.z;
		result.z = m[2][0] * vector.x + m[2][1] * vector.y + m[2][2] * vector.z;

		return result;
	}

	V3DMatrix3 V3DMatrix3::operator*(float scalar) const
	{
		V3DMatrix3 result;

		result.m[0][0] = scalar * m[0][0];
		result.m[0][1] = scalar * m[0][1];
		result.m[0][2] = scalar * m[0][2];

		result.m[1][0] = scalar * m[1][0];
		result.m[1][1] = scalar * m[1][1];
		result.m[1][2] = scalar * m[1][2];

		result.m[2][0] = scalar * m[2][0];
		result.m[2][1] = scalar * m[2][1];
		result.m[2][2] = scalar * m[2][2];

		return result;
	}

	bool V3DMatrix3::Inverse(V3DMatrix3& inverse, float tolerance) const
	{
		inverse.m[0][0] = m[1][1] * m[2][2] - m[1][2] * m[2][1];
		inverse.m[0][1] = m[0][2] * m[2][1] - m[0][1] * m[2][2];
		inverse.m[0][2] = m[0][1] * m[1][2] - m[0][2] * m[1][1];
		inverse.m[1][0] = m[1][2] * m[2][0] - m[1][0] * m[2][2];
		inverse.m[1][1] = m[0][0] * m[2][2] - m[0][2] * m[2][0];
		inverse.m[1][2] = m[0][2] * m[1][0] - m[0][0] * m[1][2];
		inverse.m[2][0] = m[1][0] * m[2][1] - m[1][1] * m[2][0];
		inverse.m[2][1] = m[0][1] * m[2][0] - m[0][0] * m[2][1];
		inverse.m[2][2] = m[0][0] * m[1][1] - m[0][1] * m[1][0];

		const float Det =
			m[0][0] * inverse.m[0][0] +
			m[0][1] * inverse.m[1][0] +
			m[0][2] * inverse.m[2][0];

		if (fabs(Det) <= tolerance)
			return false;

		const float InvDet = 1.0f / Det;

		inverse.m[0][0] *= InvDet;
		inverse.m[0][1] *= InvDet;
		inverse.m[0][2] *= InvDet;

		inverse.m[1][0] *= InvDet;
		inverse.m[1][1] *= InvDet;
		inverse.m[1][2] *= InvDet;

		inverse.m[2][0] *= InvDet;
		inverse.m[2][1] *= InvDet;
		inverse.m[2][2] *= InvDet;

		return true;
	}

	V3DMatrix3 V3DMatrix3::Inverse(float tolerance) const
	{
		V3DMatrix3 result;
		result.Zero();
		Inverse(result, tolerance);

		return result;
	}

	V3DMatrix3 V3DMatrix3::Transpose() const
	{
		V3DMatrix3 result;

		result.m[0][0] = m[0][0];
		result.m[0][1] = m[1][0];
		result.m[0][2] = m[2][0];

		result.m[1][0] = m[0][1];
		result.m[1][1] = m[1][1];
		result.m[1][2] = m[2][1];

		result.m[2][0] = m[0][2];
		result.m[2][1] = m[1][2];
		result.m[2][2] = m[2][2];

		return result;
	}

	float V3DMatrix3::Determinant() const
	{
		const float Factor = m[1][1] * m[2][2] - m[1][2] * m[2][1];
		const float Factor1 = m[1][2] * m[2][0] - m[1][0] * m[2][2];
		const float Factor2 = m[1][0] * m[2][1] - m[1][1] * m[2][0];

		const float Result =
			m[0][0] * Factor +
			m[0][1] * Factor1 +
			m[0][2] * Factor2;

		return Result;
	}

	void V3DMatrix3::Orthonormalize()
	{
		float invLength = 1.0f / sqrt(m[0][0] * m[0][0] + m[1][0] * m[1][0] + m[2][0] * m[2][0]);

		m[0][0] *= invLength;
		m[1][0] *= invLength;
		m[2][0] *= invLength;

		float dot = m[0][0] * m[0][1] + m[1][0] * m[1][1] + m[2][0] * m[2][1];

		m[0][1] -= dot * m[0][0];
		m[1][1] -= dot * m[1][0];
		m[2][1] -= dot * m[2][0];

		invLength = 1.0f / sqrt(m[0][1] * m[0][1] + m[1][1] * m[1][1] + m[2][1] * m[2][1]);

		m[0][1] *= invLength;
		m[1][1] *= invLength;
		m[2][1] *= invLength;

		const float Dot1 = m[0][1] * m[0][2] + m[1][1] * m[1][2] + m[2][1] * m[2][2];
		dot = m[0][0] * m[0][2] + m[1][0] * m[1][2] + m[2][0] * m[2][2];

		m[0][2] -= dot * m[0][0] + Dot1 * m[0][1];
		m[1][2] -= dot * m[1][0] + Dot1 * m[1][1];
		m[2][2] -= dot * m[2][0] + Dot1 * m[2][1];

		invLength = 1.0f / sqrt(m[0][2] * m[0][2] + m[1][2] * m[1][2] + m[2][2] * m[2][2]);

		m[0][2] *= invLength;
		m[1][2] *= invLength;
		m[2][2] *= invLength;
	}

	void V3DMatrix3::Zero()
	{
		m[0][0] = 0; m[0][1] = 0; m[0][2] = 0;
		m[1][0] = 0; m[1][1] = 0; m[1][2] = 0;
		m[2][0] = 0; m[2][1] = 0; m[2][2] = 0;
	}

	void V3DMatrix3::Identity()
	{
		m[0][0] = 1; m[0][1] = 0; m[0][2] = 0;
		m[1][0] = 0; m[1][1] = 1; m[1][2] = 0;
		m[2][0] = 0; m[2][1] = 0; m[2][2] = 1;
	}
}