/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

// ReSharper disable All

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
		return (w == value.w && x == value.x && y == value.y && z == value.z);
	}

	bool V3DQuaternion::operator!=(const V3DQuaternion& value) const
	{
		return (w != value.w || x != value.x || y != value.y || z != value.z);
	}

	V3DQuaternion V3DQuaternion::operator+(const V3DQuaternion& value) const
	{
		return V3DQuaternion(w + value.w, x + value.x, y + value.y, z + value.z);
	}

	V3DQuaternion V3DQuaternion::operator-(const V3DQuaternion& value) const
	{
		return V3DQuaternion(w - value.w, x - value.x, y - value.y, z - value.z);
	}

	V3DQuaternion V3DQuaternion::operator*(const V3DQuaternion& value) const
	{
		return V3DQuaternion
		(
			w * value.w - x * value.x - y * value.y - z * value.z,
			w * value.x + x * value.w + y * value.z - z * value.y,
			w * value.y + y * value.w + z * value.x - x * value.z,
			w * value.z + z * value.w + x * value.y - y * value.x
		);
	}

	V3DQuaternion V3DQuaternion::operator*(float scalar) const
	{
		return V3DQuaternion(scalar * w, scalar * x, scalar * y, scalar * z);
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
		return V3DVector3D(x, y, z);
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

		if (diagonal > 0.0)
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
			static const unsigned long s_iNext[3] = { 1, 2, 0 };
			unsigned long i = 0;
			if (rotMatrix.m[1][1] > rotMatrix.m[0][0])
				i = 1;

			if (rotMatrix.m[2][2] > rotMatrix.m[i][i])
				i = 2;

			auto j = s_iNext[i];
			auto k = s_iNext[j];

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
		float _2x = x + x;
		float _2y = y + y;
		float _2z = z + z;
		float _2xw = _2x * w;
		float _2yw = _2y * w;
		float _2zw = _2z * w;
		float _2xx = _2x * x;
		float _2yx = _2y * x;
		float _2zx = _2z * x;
		float _2yy = _2y * y;
		float _2zy = _2z * y;
		float _2zz = _2z * z;

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

	// ReSharper disable once IdentifierTypo
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
		const float _Length = Length();

		w /= _Length;
		x /= _Length;
		y /= _Length;
		z /= _Length;
	}
}