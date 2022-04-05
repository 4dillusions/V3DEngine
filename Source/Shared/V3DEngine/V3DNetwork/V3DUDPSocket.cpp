/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DUDPSocket.h"
#include "V3DEngine/V3DNetwork/V3DNetworkSystem.h"
#include "V3DEngine/V3DNetwork/V3DIpV4Address.h"
#include "V3DSocketAddress.h"
#include "V3DSocketHelper.h"
#include "V3DEngine/V3DIO/V3DLogger.h"

using namespace V3D::V3DEngine::V3DIO;
using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngine::V3DNetwork
{
	V3DUDPSocket::V3DUDPSocket()
	{
		// ReSharper disable once CppRedundantCastExpression
		udpSocket = socket(AF_INET, SOCK_DGRAM, 0); // NOLINT(bugprone-narrowing-conversions, cppcoreguidelines-narrowing-conversions, clang-diagnostic-shorten-64-to-32)
		
		if (static_cast<SOCKET>(udpSocket) == INVALID_SOCKET)
			V3DLogger::Get().WriteOutput(V3DLogMessageType::Error, "Can't create UDPSocket!");
		else
			V3DLogger::Get().WriteOutput("OK - create UDPSocket");
	}
	
	V3DUDPSocket::V3DUDPSocket(int udpSocket) : udpSocket{ udpSocket }
	{ }
	
	V3DUDPSocket::~V3DUDPSocket()
	{
		V3DSocketHelper::Close(udpSocket);
	}
	
	void V3DUDPSocket::Bind(const V3DSocketAddress& toAddress) const
	{
		if (bind(udpSocket, reinterpret_cast<sockaddr*>(toAddress.GetSockAddress()), sizeof(sockaddr_in)) == SOCKET_ERROR)
			V3DLogger::Get().WriteOutput(V3DLogMessageType::Error, "Can't bind UDP socket!");
		else
			V3DLogger::Get().WriteOutput("OK - bind UDP socket");
	}

	void V3DUDPSocket::BindAny(unsigned short int port) const
	{
		const V3DSocketAddress anyAddress(port);
		Bind(anyAddress);
	}
	
	int V3DUDPSocket::SendTo(const char* message, int messageLenght, const V3DSocketAddress& toAddress) const
	{
		return sendto(udpSocket, message, messageLenght, 0, reinterpret_cast<sockaddr*>(toAddress.GetSockAddress()), sizeof(sockaddr_in));
	}

	int V3DUDPSocket::SendTo(const V3DString& message, const V3DSocketAddress& toAddress) const
	{
		return SendTo(message.ToChar(), message.GetTextLength(), toAddress);
	}

	int V3DUDPSocket::SendToAll(const char* message, int messageLenght, const V3DSocketAddress& localAddress) const
	{
		const unsigned short int port = static_cast<unsigned short>(localAddress.GetPort().ToInt());
		V3DIpV4Address ip(localAddress.GetIp());
		const int localIpAddr4 = ip.addr4;
		
		for (int ipAddr4 = 0; ipAddr4 < 255; ipAddr4++)
		{
			ip.addr4 = ipAddr4;

			if (ipAddr4 != localIpAddr4)
			{
				V3DSocketAddress address(port, ip);
				[[maybe_unused]] auto res = SendTo(message, messageLenght, address);
			}
		}

		return 0;
	}

	int V3DUDPSocket::SendToAll(const V3DString& message, const V3DSocketAddress& localAddress) const
	{
		return SendToAll(message.ToChar(), message.GetTextLength(), localAddress);
	}
	
	int V3DUDPSocket::ReceiveFrom(char* messageOut, int messageLenght, const V3DSocketAddress& fromAddressOut) const
	{
		socklen_t fromLenght = sizeof(sockaddr_in);
		return recvfrom(udpSocket, messageOut, messageLenght, 0, reinterpret_cast<sockaddr*>(fromAddressOut.GetSockAddress()), &fromLenght);
	}

	V3DString V3DUDPSocket::ReceiveFrom(const V3DSocketAddress& fromAddressOut) const
	{
		char messageBuffer[MessageBufferSize];
		ReceiveFrom(messageBuffer, MessageBufferSize, fromAddressOut);

		return V3DString(messageBuffer);
	}

	int V3DUDPSocket::ReceiveFromAny(char* messageOut, int messageLenght) const
	{
		const V3DSocketAddress anyAddress{};
		const int result = ReceiveFrom(messageOut, messageLenght, anyAddress);

		return result;
	}

	V3DString V3DUDPSocket::ReceiveFromAny() const
	{
		char messageBuffer[MessageBufferSize];
		ReceiveFromAny(messageBuffer, MessageBufferSize);

		return V3DString(messageBuffer);
	}

	void V3DUDPSocket::SetNonBlocking() const
	{
		V3DSocketHelper::SetNonBlocking(udpSocket);
	}
}
