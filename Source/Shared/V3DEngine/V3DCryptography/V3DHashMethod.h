/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DEngineLibrary.h"
#include "V3DHashType.h"

namespace V3D::V3DEngine::V3DCore
{
	class V3DString;
}

namespace V3D::V3DEngine::V3DCryptography
{
	/*
		A hash is not ‘encryption’ – it cannot be decrypted back to the original text.
		It is a ‘one-way’ cryptographic function, and is a fixed size for any size of source text.
	*/
	class V3DENGINE_API V3DHashMethod final
	{
		V3DHashType hashType;
		int arraySize;

		unsigned char* CreateHexArray(int arraySize) const;
		
		void InitPicohash(void* picoContext) const;
		void InitPicohashHMAC(void* picoContext, const V3DCore::V3DString& key) const;

		V3DCore::V3DString CreateHashOrHMAC(const V3DCore::V3DString& plainText, const V3DCore::V3DString& key) const;
		
	public:
		V3DHashMethod() = delete;
		explicit V3DHashMethod(V3DHashType hashType);
		V3DHashMethod(const V3DHashMethod&) = delete;
		V3DHashMethod(V3DHashMethod&&) = delete;
		~V3DHashMethod() = default;
		V3DHashMethod& operator=(const V3DHashMethod&) = delete;
		V3DHashMethod& operator=(V3DHashMethod&&) = delete;

		V3DCore::V3DString CreateHash(const V3DCore::V3DString& plainText) const;
		V3DCore::V3DString CreateHMAC(const V3DCore::V3DString& plainText, const V3DCore::V3DString& key) const;
	};
}
