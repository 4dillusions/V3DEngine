/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DNetwork
{
	class V3DUDPSocketTest final
	{
		static void SendReceiveMessage(bool isToAll);
		
	public:
		V3DUDPSocketTest() = delete;
		V3DUDPSocketTest(const V3DUDPSocketTest&) = delete;
		V3DUDPSocketTest(V3DUDPSocketTest&&) = delete;
		~V3DUDPSocketTest() = delete;
		V3DUDPSocketTest& operator=(const V3DUDPSocketTest&) = delete;
		V3DUDPSocketTest& operator=(V3DUDPSocketTest&&) = delete;

		static void SendReceiveMessageTest();
		static void SendAllReceiveMessageTest();
		
		static void RunAllTests();
	};
}
