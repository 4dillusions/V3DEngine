/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTCPSocketTest.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DNetwork/V3DNet.h"
#include "V3DEngine/V3DNetwork/V3DTCPSocket.h"
#include "V3DEngine/V3DNetwork/V3DSocketAddress.h"
#include "V3DEngine/V3DNetwork/V3DIpV4Address.h"

#include <thread>
#include <chrono>

using namespace V3D::V3DEngine::V3DNetwork;
using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngineTests::V3DEngine::V3DNetwork
{
	void V3DTCPSocketTest::SendReceiveMessageTest()
	{
		V3DNet::Init();

		V3DSocketAddress localAddress(24000, V3DIpV4Address(127, 0, 0, 1));
		const int MessageByteBufferSize = 1024;
		char messageByteBuffer[MessageByteBufferSize];
		const V3DString Message("Hello!");

		auto Server = [&]()
		{
			V3DSocketAddress remoteAddress{};
			auto listenerSocket = V3DMemory::New<V3DTCPSocket>(V3DFILE_INFO);
			listenerSocket->Bind(localAddress);
			listenerSocket->Listen();
			auto remoteSocket = listenerSocket->Accept(remoteAddress);
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			V3DTest::AssertOk(remoteAddress.GetIp() == V3DString("127.0.0.1"), V3DFILE_INFO);
			V3DMemory::Delete(listenerSocket);

			memset(messageByteBuffer, 0, MessageByteBufferSize);
			const auto bytesReceived = remoteSocket->Receive(messageByteBuffer, MessageByteBufferSize);
			V3DTest::AssertOk(bytesReceived != SOCKET_ERROR, V3DFILE_INFO);
			V3DTest::AssertOk(V3DString(messageByteBuffer) == Message, V3DFILE_INFO);

			V3DMemory::Delete(remoteSocket);
		};

		auto Client = [&]()
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			auto senderSocket = V3DMemory::New<V3DTCPSocket>(V3DFILE_INFO);
			senderSocket->Connect(localAddress);
			const auto SendRet = senderSocket->Send(Message.ToChar(), Message.GetTextLength());
			V3DTest::AssertOk(SendRet != SOCKET_ERROR, V3DFILE_INFO);
			
			V3DMemory::Delete(senderSocket);
		};

		std::thread serverThread(Server);
		std::thread clientThread(Client);
		serverThread.join();
		clientThread.join();
		
		V3DNet::Cleanup();
	}

	void V3DTCPSocketTest::RunAllTests()
	{	
		SendReceiveMessageTest();
	}
}
