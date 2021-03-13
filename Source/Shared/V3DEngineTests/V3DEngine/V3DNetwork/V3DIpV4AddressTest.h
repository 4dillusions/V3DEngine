/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DNetwork
{
	class V3DIpV4AddressTest final
	{
	public:
		V3DIpV4AddressTest() = delete;
		V3DIpV4AddressTest(const V3DIpV4AddressTest&) = delete;
		V3DIpV4AddressTest(V3DIpV4AddressTest&&) = delete;
		~V3DIpV4AddressTest() = delete;
		V3DIpV4AddressTest& operator=(const V3DIpV4AddressTest&) = delete;
		V3DIpV4AddressTest& operator=(V3DIpV4AddressTest&&) = delete;

		static void CreateAndConvertAddressTest();
		
		static void RunAllTests();
	};
}
