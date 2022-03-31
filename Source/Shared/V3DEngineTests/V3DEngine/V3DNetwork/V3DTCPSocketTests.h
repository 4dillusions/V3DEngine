/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DNetwork
{
	class V3DTCPSocketTests final
	{
	public:
		V3DTCPSocketTests() = delete;
		V3DTCPSocketTests(const V3DTCPSocketTests&) = delete;
		V3DTCPSocketTests(V3DTCPSocketTests&&) = delete;
		~V3DTCPSocketTests() = delete;
		V3DTCPSocketTests& operator=(const V3DTCPSocketTests&) = delete;
		V3DTCPSocketTests& operator=(V3DTCPSocketTests&&) = delete;

		static void SendReceiveMessageTest();
		
		static void RunAllTests();
	};
}
