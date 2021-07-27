/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DUDPSocketTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DNetwork/V3DNet.h"
#include "V3DEngine/V3DNetwork/V3DUDPSocket.h"
#include "V3DEngine/V3DNetwork/V3DSocketAddress.h"
#include "V3DEngine/V3DNetwork/V3DIpV4Address.h"

using namespace V3D::V3DEngine::V3DNetwork;
using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngineTests::V3DEngine::V3DNetwork
{
	void V3DUDPSocketTests::SendReceiveMessage(bool isToAll)
	{
		V3DNet::Init();

		const int port = 24000;
		V3DSocketAddress localAddress(port, V3DIpV4Address(127, 0, 0, 1));
		const int MessageByteBufferSize = 1024;
		char messageByteBuffer[MessageByteBufferSize];
		const V3DString Message(isToAll ? "Hello broadcast" : "Hello!");

		auto receiverSocket = V3DMemory::New<V3DUDPSocket>(V3DFILE_INFO);
		receiverSocket->SetNonBlocking();
		receiverSocket->BindAny(port);

		auto senderSocket = V3DMemory::New<V3DUDPSocket>(V3DFILE_INFO);
		senderSocket->BindAny();

		if (isToAll)
		{
			V3DSocketAddress localPublicAddress(port, V3DIpV4Address(V3DSocketAddress::GetLocalIp()));
			senderSocket->SendToAll(Message, localPublicAddress);
		}
		else
			senderSocket->SendTo(Message, localAddress);

		memset(messageByteBuffer, 0, MessageByteBufferSize);
		V3DSocketAddress senderAddress{};
		receiverSocket->ReceiveFrom(messageByteBuffer, MessageByteBufferSize, senderAddress);

		if (isToAll)
		{
			V3DTest::AssertOk(V3DString(messageByteBuffer) != Message, V3DFILE_INFO);
		}
		else
		{
			V3DTest::AssertOk(senderAddress.GetIp() == localAddress.GetIp(), V3DFILE_INFO);
			V3DTest::AssertOk(V3DString(messageByteBuffer) == Message, V3DFILE_INFO);
		}

		V3DMemory::Delete(receiverSocket);
		V3DMemory::Delete(senderSocket);

		V3DNet::Cleanup();
	}
	
	void V3DUDPSocketTests::SendReceiveMessageTest()
	{
		SendReceiveMessage(false);
	}

	void V3DUDPSocketTests::SendAllReceiveMessageTest()
	{
		SendReceiveMessage(true);
	}

	void V3DUDPSocketTests::RunAllTests()
	{	
		SendReceiveMessageTest();
		SendAllReceiveMessageTest();
	}
}
