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

		constexpr int port = 24000;
		const V3DSocketAddress localHostAddress(port, V3DIpV4Address(127, 0, 0, 1));
		const V3DSocketAddress privateAddress(port, V3DIpV4Address(V3DSocketAddress::GetLocalIp()));
		constexpr int MessageByteBufferSize = 1024;
		char messageByteBuffer[MessageByteBufferSize];
		const V3DString Message(isToAll ? "Hello broadcast!" : "Hello!");

		auto receiverSocket = V3DMemory::New<V3DUDPSocket>(V3DFILE_INFO);
		receiverSocket->SetNonBlocking();
		receiverSocket->BindAny(port);

		auto senderSocket = V3DMemory::New<V3DUDPSocket>(V3DFILE_INFO);
		senderSocket->BindAny();

		int senderRes;
		if (isToAll)
			senderRes = senderSocket->SendToLocalAll(Message, privateAddress);
		else
			senderRes = senderSocket->SendTo(Message, localHostAddress);

		V3DTest::AssertOk(senderRes == Message.GetTextLength(), V3DFILE_INFO);

		memset(messageByteBuffer, 0, MessageByteBufferSize);
		const V3DSocketAddress senderAddress{};
		const int receiverRes = receiverSocket->ReceiveFrom(messageByteBuffer, MessageByteBufferSize, senderAddress);

		V3DTest::AssertOk(receiverRes == Message.GetTextLength(), V3DFILE_INFO);
		V3DTest::AssertOk(V3DString(messageByteBuffer) == Message, V3DFILE_INFO);

		if (isToAll)
			V3DTest::AssertOk(senderAddress.GetIp() == privateAddress.GetIp(), V3DFILE_INFO);
		else
			V3DTest::AssertOk(senderAddress.GetIp() == localHostAddress.GetIp(), V3DFILE_INFO);

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

	void V3DUDPSocketTests::RunAllUnitTests()
	{
		SendReceiveMessageTest();
		SendAllReceiveMessageTest();
	}

	void V3DUDPSocketTests::RegisterIntegrationTests()
	{
	}

	void V3DUDPSocketTests::RegisterTimingTests()
	{
	}
}
