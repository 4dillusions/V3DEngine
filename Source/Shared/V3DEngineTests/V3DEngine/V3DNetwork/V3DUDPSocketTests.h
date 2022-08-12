/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DNetwork
{
	class V3DUDPSocketTests final
	{
		static void SendReceiveMessage(bool isToAll);
		
	public:
		V3DUDPSocketTests() = delete;
		V3DUDPSocketTests(const V3DUDPSocketTests&) = delete;
		V3DUDPSocketTests(V3DUDPSocketTests&&) = delete;
		~V3DUDPSocketTests() = delete;
		V3DUDPSocketTests& operator=(const V3DUDPSocketTests&) = delete;
		V3DUDPSocketTests& operator=(V3DUDPSocketTests&&) = delete;

		static void SendReceiveMessageTest();
		static void SendAllReceiveMessageTest();
		
		static void RunAllUnitTests();
		static void RegisterIntegrationTests();
		static void RegisterTimingTests();
	};
}
