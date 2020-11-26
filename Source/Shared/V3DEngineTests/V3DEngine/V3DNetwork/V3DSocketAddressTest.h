/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DNetwork
{
	class V3DSocketAddressTest final
	{
	public:
		V3DSocketAddressTest() = delete;
		V3DSocketAddressTest(const V3DSocketAddressTest&) = delete;
		V3DSocketAddressTest(V3DSocketAddressTest&&) = delete;
		~V3DSocketAddressTest() = delete;
		V3DSocketAddressTest& operator=(const V3DSocketAddressTest&) = delete;
		V3DSocketAddressTest& operator=(V3DSocketAddressTest&&) = delete;

		static void CreateAddressTest();
		static void GetHostIpTest();
		
		static void RunAllTests();
	};
}
