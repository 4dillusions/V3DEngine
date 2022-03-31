/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DNetwork
{
	class V3DSocketAddressTests final
	{
	public:
		V3DSocketAddressTests() = delete;
		V3DSocketAddressTests(const V3DSocketAddressTests&) = delete;
		V3DSocketAddressTests(V3DSocketAddressTests&&) = delete;
		~V3DSocketAddressTests() = delete;
		V3DSocketAddressTests& operator=(const V3DSocketAddressTests&) = delete;
		V3DSocketAddressTests& operator=(V3DSocketAddressTests&&) = delete;

		static void CreateAddressTest();
		static void GetHostIpTest();
		
		static void RunAllTests();
	};
}
