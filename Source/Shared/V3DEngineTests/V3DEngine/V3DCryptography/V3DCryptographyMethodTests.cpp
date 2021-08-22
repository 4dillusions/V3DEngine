/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DCryptographyMethodTests.h"

#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DCore/V3DString.h"
#include "V3DEngine/V3DCryptography/V3DHashMethod.h"

using namespace V3D::V3DEngine::V3DCryptography;
using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngineTests::V3DEngine::V3DCryptography
{
	void V3DCryptographyMethodTests::HashMethodTest()
	{
		V3DString plainText("abc");
		V3DString key("123");
		const V3DHashMethod md5Method(V3DHashType::MD5);
		const V3DHashMethod sha1Method(V3DHashType::SHA1);
		const V3DHashMethod sha224Method(V3DHashType::SHA224);
		const V3DHashMethod sha256Method(V3DHashType::SHA256);
		
		V3DTest::AssertOk(md5Method.CreateHash(plainText) == V3DString("900150983cd24fb0d6963f7d28e17f72"), V3DFILE_INFO);
		V3DTest::AssertOk(sha1Method.CreateHash(plainText) == V3DString("a9993e364706816aba3e25717850c26c9cd0d89d"), V3DFILE_INFO);
		V3DTest::AssertOk(sha224Method.CreateHash(plainText) == V3DString("23097d223405d8228642a477bda255b32aadbce4bda0b3f7e36c9da7"), V3DFILE_INFO);
		V3DTest::AssertOk(sha256Method.CreateHash(plainText) == V3DString("ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad"), V3DFILE_INFO);

		V3DTest::AssertOk(md5Method.CreateHMAC(plainText, key) == V3DString("ffb7c0fc166f7ca075dfa04d59aed232"), V3DFILE_INFO);
		V3DTest::AssertOk(sha1Method.CreateHMAC(plainText, key) == V3DString("540b0c53d4925837bd92b3f71abe7a9d70b676c4"), V3DFILE_INFO);
		V3DTest::AssertOk(sha224Method.CreateHMAC(plainText, key) == V3DString("dcc62feedb358eacbef83bc56d756663c2d504ce9e20431972433c6e"), V3DFILE_INFO);
		V3DTest::AssertOk(sha256Method.CreateHMAC(plainText, key) == V3DString("8f16771f9f8851b26f4d460fa17de93e2711c7e51337cb8a608a0f81e1c1b6ae"), V3DFILE_INFO);

		plainText = "The quick brown fox jumps over the lazy dog 123.";
		key = "NcrBR5~+bxEp[s^{";

		V3DTest::AssertOk(md5Method.CreateHash(plainText) == V3DString("a9e650c3abc7fc78331220844b301040"), V3DFILE_INFO);
		V3DTest::AssertOk(sha1Method.CreateHash(plainText) == V3DString("e81d68d085b03320422414b7b1a2466cb175252e"), V3DFILE_INFO);
		V3DTest::AssertOk(sha224Method.CreateHash(plainText) == V3DString("695982a6268eebee5e4a1d70eaa7cea6c4e6d969599ea10be8b5d5c2"), V3DFILE_INFO);
		V3DTest::AssertOk(sha256Method.CreateHash(plainText) == V3DString("d097371f9b18eb186bed024d0c70692cf6f0bd2cc59f7274f0cec8df23b1db3c"), V3DFILE_INFO);

		V3DTest::AssertOk(md5Method.CreateHMAC(plainText, key) == V3DString("a22fb482eaadc4626ba660624e3a5b38"), V3DFILE_INFO);
		V3DTest::AssertOk(sha1Method.CreateHMAC(plainText, key) == V3DString("5641907c2c3c0f13e275f3361a46f7db033e73b9"), V3DFILE_INFO);
		V3DTest::AssertOk(sha224Method.CreateHMAC(plainText, key) == V3DString("4cdda99d4151f59afa2bf323adbac98e7c3a5bcbb65cff56c32a073d"), V3DFILE_INFO);
		V3DTest::AssertOk(sha256Method.CreateHMAC(plainText, key) == V3DString("4e82d5229aa08327932610b7c6f7e7cb7858da46cebf61120be734abc5672c38"), V3DFILE_INFO);
	}

	void V3DCryptographyMethodTests::RunAllTests()
	{	
		HashMethodTest();
	}
}
