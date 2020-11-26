/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DUDPSocketTest.h"
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
	void V3DUDPSocketTest::SendReceiveMessage(bool isToAll)
	{
		V3DNet::Init();

		const int port = 24000;
		V3DSocketAddress localAddress(port, V3DIpV4Address(127, 0, 0, 1));
		const int MessageByteBufferSize = 1024;
		char messageByteBuffer[MessageByteBufferSize];
		const V3DString Message(isToAll ? "Hello broadcast" : "Hello!");

		auto receiverSocket = V3DMemory::New<V3DUDPSocket>(V3DFILE_INFO);
		receiverSocket->SetNonBlocking();
		receiverSocket->Bind(localAddress);

		auto senderSocket = V3DMemory::New<V3DUDPSocket>(V3DFILE_INFO);

		if (isToAll)
		{
			V3DSocketAddress localPublicAddress(port, V3DIpV4Address(V3DSocketAddress::GetLocalIp()));
			senderSocket->SendToAll(Message.ToChar(), Message.GetTextLength(), localPublicAddress);
		}
		else
			senderSocket->SendTo(Message.ToChar(), Message.GetTextLength(), localAddress);

		memset(messageByteBuffer, 0, MessageByteBufferSize);
		receiverSocket->ReceiveFrom(messageByteBuffer, MessageByteBufferSize, localAddress);

		if (isToAll)
			V3DTest::AssertOk(V3DString(messageByteBuffer) != Message, V3DFILE_INFO);
		else
			V3DTest::AssertOk(V3DString(messageByteBuffer) == Message, V3DFILE_INFO);

		V3DMemory::Delete(receiverSocket);
		V3DMemory::Delete(senderSocket);

		V3DNet::Cleanup();
	}
	
	void V3DUDPSocketTest::SendReceiveMessageTest()
	{
		SendReceiveMessage(false);
	}

	void V3DUDPSocketTest::SendAllReceiveMessageTest()
	{
		SendReceiveMessage(true);
	}

	void V3DUDPSocketTest::RunAllTests()
	{	
		SendReceiveMessageTest();
		SendAllReceiveMessageTest();
	}
}
