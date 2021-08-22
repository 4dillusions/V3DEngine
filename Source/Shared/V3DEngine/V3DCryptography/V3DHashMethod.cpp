/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DHashMethod.h"

#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngine/V3DCore/V3DString.h"
#include "V3DEngine/V3DCryptography/V3DCryptographyHelper.h"

#include "ThirdParty/PicoHash/picohash.h"

using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngine::V3DCryptography
{
	V3DHashMethod::V3DHashMethod(V3DHashType hashType) : hashType{ hashType }
	{
		switch (hashType)
		{
			case V3DHashType::MD5: arraySize = PICOHASH_MD5_DIGEST_LENGTH; break;
			case V3DHashType::SHA1: arraySize = PICOHASH_SHA1_DIGEST_LENGTH; break;
			case V3DHashType::SHA224: arraySize = PICOHASH_SHA224_DIGEST_LENGTH; break;
			case V3DHashType::SHA256: arraySize = PICOHASH_SHA256_DIGEST_LENGTH; break;
			default: break;
		}
	}

	unsigned char* V3DHashMethod::CreateHexArray(int arraySize) const
	{
		return V3DMemory::NewArray<unsigned char>(V3DFILE_INFO, arraySize);;
	}

	void V3DHashMethod::InitPicohash(void* picoContext) const
	{
		const auto ctx = static_cast<picohash_ctx_t*>(picoContext);
		
		switch (hashType)
		{
			case V3DHashType::MD5: picohash_init_md5(ctx); break;
			case V3DHashType::SHA1: picohash_init_sha1(ctx); break;
			case V3DHashType::SHA224: picohash_init_sha224(ctx); break;
			case V3DHashType::SHA256: picohash_init_sha256(ctx); break;
			default: break;
		}
	}

	void V3DHashMethod::InitPicohashHMAC(void* picoContext, const V3DString& key) const
	{
		const auto ctx = static_cast<picohash_ctx_t*>(picoContext);
		
		switch (hashType)
		{
			case V3DHashType::MD5: picohash_init_hmac(ctx, picohash_init_md5, key.ToChar(), key.GetTextLength()); break;
			case V3DHashType::SHA1: picohash_init_hmac(ctx, picohash_init_sha1, key.ToChar(), key.GetTextLength()); break;
			case V3DHashType::SHA224: picohash_init_hmac(ctx, picohash_init_sha224, key.ToChar(), key.GetTextLength()); break;
			case V3DHashType::SHA256: picohash_init_hmac(ctx, picohash_init_sha256, key.ToChar(), key.GetTextLength()); break;
			default: break;
		}
	}

	V3DString V3DHashMethod::CreateHashOrHMAC(const V3DString& plainText, const V3DString& key) const
	{
		auto picoContext = V3DMemory::New<picohash_ctx_t>(V3DFILE_INFO);
		auto hexArray = CreateHexArray(arraySize);

		if (key.IsEmpty())
			InitPicohash(picoContext);
		else
			InitPicohashHMAC(picoContext, key);

		picohash_update(picoContext, plainText.ToChar(), plainText.GetTextLength());
		picohash_final(picoContext, hexArray);

		auto result = V3DCryptographyHelper::ConvertHexArrayToString(hexArray, arraySize);

		V3DMemory::Delete(picoContext);
		V3DMemory::DeleteArray(hexArray);

		return result;
	}
	
	V3DString V3DHashMethod::CreateHash(const V3DString& plainText) const
	{
		return CreateHashOrHMAC(plainText, V3DString(""));
	}
	
	V3DString V3DHashMethod::CreateHMAC(const V3DString& plainText, const V3DString& key) const
	{
		return CreateHashOrHMAC(plainText, key);
	}
}
