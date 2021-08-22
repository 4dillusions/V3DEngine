/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngine::V3DCryptography
{
	enum class V3DHashType
	{
		//MD5 (Message Digest algorithm) produces 128 bit (16 byte) hash value. Typically rendered as a hexadecimal number, 32 digits long.
		MD5,

		//SHA1 (Secure Hash Algorithm) produces a 160-bit (20-byte) hash value. Typically rendered as a hexadecimal number, 40 digits long.
		SHA1,

		//SHA224 (Secure Hash Algorithm) produces 224-bit (28-byte) Typically rendered as a hexadecimal number, 56 digits long.
		SHA224,

		//SHA256 (Secure Hash Algorithm) produces 256 bit (32 byte) hash value. Typically rendered as a hexadecimal number, 64 digits long.
		SHA256,
	};
}
