/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DQuaternion.h"
#include "V3DMath.h"

#include <cmath>

namespace V3D::V3DEngine::V3DMathematics
{
	V3DQuaternion::V3DQuaternion(float w, float x, float y, float z) : w{ w }, x{ x }, y{ y }, z{ z }
	{}

	V3DQuaternion::V3DQuaternion(const V3DMatrix3& rotMatrix)
	{
		FromRotationMatrix(rotMatrix);
	}

	bool V3DQuaternion::operator==(const V3DQuaternion& value) const
	{
		return (V3DMath::IsEqual(w ,value.w) && V3DMath::IsEqual(x, value.x) && V3DMath::IsEqual(y ,value.y) && V3DMath::IsEqual(z, value.z));
	}

	bool V3DQuaternion::operator!=(const V3DQuaternion& value) const
	{
		return (!V3DMath::IsEqual(w, value.w) || !V3DMath::IsEqual(x, value.x) || !V3DMath::IsEqual(y, value.y) || !V3DMath::IsEqual(z, value.z));
	}

	V3DQuaternion V3DQuaternion::operator+(const V3DQuaternion& value) const
	{
		return {w + value.w, x + value.x, y + value.y, z + value.z};
	}

	V3DQuaternion V3DQuaternion::operator-(const V3DQuaternion& value) const
	{
		return {w - value.w, x - value.x, y - value.y, z - value.z};
	}

	V3DQuaternion V3DQuaternion::operator*(const V3DQuaternion& value) const
	{
		return {
			w * value.w - x * value.x - y * value.y - z * value.z,
			w * value.x + x * value.w + y * value.z - z * value.y,
			w * value.y + y * value.w + z * value.x - x * value.z,
			w * value.z + z * value.w + x * value.y - y * value.x
		};
	}

	V3DQuaternion V3DQuaternion::operator*(float scalar) const
	{
		return {scalar * w, scalar * x, scalar * y, scalar * z};
	}

	float V3DQuaternion::Length() const
	{
		return sqrt(w * w + x * x + y * y + z * z);
	}

	float V3DQuaternion::DotProduct(const V3DQuaternion& value) const
	{
		return w * value.w + x * value.x + y * value.y + z * value.z;
	}

	float V3DQuaternion::RotationAngle() const
	{
		const float Cosa = w; 
		const float Sina = V3DVector3D(x, y, z).Length();
		const float AngRad = atan2(Cosa, Sina) * 2;

		return AngRad * 180 / V3DMath::Pi;
	}

	V3DVector3D V3DQuaternion::RotationAxis() const
	{
		return {x, y, z};
	}

	void V3DQuaternion::ToRotationAxis(V3DVector3D& rotAxis) const
	{
		rotAxis.x = x;
		rotAxis.y = y;
		rotAxis.z = z;
	}

	void V3DQuaternion::FromRotationMatrix(const V3DMatrix3& rotMatrix)
	{
		//Algorithm in Ken Shoemake's article in 1987 SIGGRAPH course notes
		const float diagonal = rotMatrix.m[0][0] + rotMatrix.m[1][1] + rotMatrix.m[2][2];
		float fRoot;

		if (diagonal > 0.0f)
		{
			fRoot = sqrt(diagonal + 1.0f);
			w = 0.5f * fRoot;
			fRoot = 0.5f / fRoot;
			
			x = (rotMatrix.m[2][1] - rotMatrix.m[1][2]) * fRoot;
			y = (rotMatrix.m[0][2] - rotMatrix.m[2][0]) * fRoot;
			z = (rotMatrix.m[1][0] - rotMatrix.m[0][1]) * fRoot;
		}
		else
		{
			static constexpr unsigned long s_iNext[3] = { 1, 2, 0 };
			unsigned long i = 0;
			if (rotMatrix.m[1][1] > rotMatrix.m[0][0])
				i = 1;

			if (rotMatrix.m[2][2] > rotMatrix.m[i][i])
				i = 2;

			const auto j = s_iNext[i];
			const auto k = s_iNext[j];

			fRoot = sqrt(rotMatrix.m[i][i] - rotMatrix.m[j][j] - rotMatrix.m[k][k] + 1.0f);
			float* apkQuat[3] = { &x, &y, &z };
			*apkQuat[i] = 0.5f * fRoot;
			fRoot = 0.5f / fRoot;
			w = (rotMatrix.m[k][j] - rotMatrix.m[j][k]) * fRoot;
			*apkQuat[j] = (rotMatrix.m[j][i] + rotMatrix.m[i][j]) * fRoot;
			*apkQuat[k] = (rotMatrix.m[k][i] + rotMatrix.m[i][k]) * fRoot;
		}
	}

	void V3DQuaternion::ToRotationMatrix(V3DMatrix3& rotMatrixOut) const
	{
		const float _2x = x + x;
		const float _2y = y + y;
		const float _2z = z + z;
		const float _2xw = _2x * w;
		const float _2yw = _2y * w;
		const float _2zw = _2z * w;
		const float _2xx = _2x * x;
		const float _2yx = _2y * x;
		const float _2zx = _2z * x;
		const float _2yy = _2y * y;
		const float _2zy = _2z * y;
		const float _2zz = _2z * z;

		rotMatrixOut.m[0][0] = 1.0f - (_2yy + _2zz);
		rotMatrixOut.m[0][1] = _2yx - _2zw;
		rotMatrixOut.m[0][2] = _2zx + _2yw;
		rotMatrixOut.m[1][0] = _2yx + _2zw;
		rotMatrixOut.m[1][1] = 1.0f - (_2xx + _2zz);
		rotMatrixOut.m[1][2] = _2zy - _2xw;
		rotMatrixOut.m[2][0] = _2zx - _2yw;
		rotMatrixOut.m[2][1] = _2zy + _2xw;
		rotMatrixOut.m[2][2] = 1.0f - (_2xx + _2yy);
	}

	float V3DQuaternion::Normalise()
	{
		const float Result = Length();

		const float Length = 1.0f / Result;
		w *= Length;
		x *= Length;
		y *= Length;
		z *= Length;

		return Result;
	}

	void V3DQuaternion::Normalizing()
	{
		const float LengthTmp = Length();

		w /= LengthTmp;
		x /= LengthTmp;
		y /= LengthTmp;
		z /= LengthTmp;
	}
}
