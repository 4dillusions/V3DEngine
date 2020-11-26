/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DNetwork
{
	class V3DTCPSocketTest final
	{
	public:
		V3DTCPSocketTest() = delete;
		V3DTCPSocketTest(const V3DTCPSocketTest&) = delete;
		V3DTCPSocketTest(V3DTCPSocketTest&&) = delete;
		~V3DTCPSocketTest() = delete;
		V3DTCPSocketTest& operator=(const V3DTCPSocketTest&) = delete;
		V3DTCPSocketTest& operator=(V3DTCPSocketTest&&) = delete;

		static void SendReceiveMessageTest();
		
		static void RunAllTests();
	};
}
