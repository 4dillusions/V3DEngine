/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTCPSocket.h"
#include "V3DEngine/V3DNetwork/V3DSocketHelper.h"
#include "V3DSocketAddress.h"
#include "V3DEngine/V3DIO/V3DLogger.h"

using namespace V3D::V3DEngine::V3DIO;
using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngine::V3DNetwork
{
	V3DTCPSocket::V3DTCPSocket()
	{
		tcpSocket = socket(AF_INET, SOCK_STREAM, 0);
		
		if (tcpSocket == INVALID_SOCKET)
			V3DLogger::Get().WriteOutput(V3DLogMessageType::Error, "Can't create TCPSocket!");
		else
			V3DLogger::Get().WriteOutput("OK - create TCPSocket");
	}
	
	V3DTCPSocket::V3DTCPSocket(SOCKET tcpSocket) : tcpSocket{ tcpSocket }
	{ }
	
	V3DTCPSocket::~V3DTCPSocket()
	{
		V3DSocketClose(tcpSocket);
	}
	
	void V3DTCPSocket::Connect(V3DSocketAddress& address) const
	{
		if (connect(tcpSocket, reinterpret_cast<sockaddr*>(address.GetSockAddress()), sizeof(sockaddr_in)) == SOCKET_ERROR)
			V3DLogger::Get().WriteOutput(V3DLogMessageType::Error, "Can't connect to TCP server!");
		else
			V3DLogger::Get().WriteOutput("Ok - connect to TCP server");
	}
	
	void V3DTCPSocket::Bind(V3DSocketAddress& toAddress) const
	{
		if (bind(tcpSocket, reinterpret_cast<sockaddr*>(toAddress.GetSockAddress()), sizeof(sockaddr_in)) == SOCKET_ERROR)
			V3DLogger::Get().WriteOutput(V3DLogMessageType::Error, "Can't bind TCP socket!");
		else
			V3DLogger::Get().WriteOutput("OK - bind TCP socket");
	}
	
	void V3DTCPSocket::Listen() const
	{
		if (listen(tcpSocket, SOMAXCONN) < 0)
			V3DLogger::Get().WriteOutput(V3DLogMessageType::Error, "Listen failed on TCP socket");
		else
			V3DLogger::Get().WriteOutput("Ok - listen on TCP socket");
	}
	
	V3DTCPSocket* V3DTCPSocket::Accept(V3DSocketAddress& fromAddress) const
	{
		socklen_t length = sizeof(sockaddr_in);
		const auto newSocket = accept(tcpSocket, reinterpret_cast<sockaddr*>(fromAddress.GetSockAddress()), &length);
		if (newSocket == INVALID_SOCKET)
		{
			V3DLogger::Get().WriteOutput(V3DLogMessageType::Error, "Invalid accept TCP socket");
			return nullptr;
		}

		V3DLogger::Get().WriteOutput("OK - accept TCP socket");
		return V3DMemory::New<V3DTCPSocket>(V3DFILE_INFO, newSocket);
	}
	
	int V3DTCPSocket::Send(const char* message, int messageLenght) const
	{
		return send(tcpSocket, message, messageLenght, 0);
	}

	int V3DTCPSocket::Send(const V3DString& message) const
	{
		return Send(message.ToChar(), message.GetTextLength());
	}

	int V3DTCPSocket::Receive(char* messageOut, int messageLenght) const
	{
		return recv(tcpSocket, messageOut, messageLenght, 0);
	}

	V3DString V3DTCPSocket::Receive() const
	{
		char messageBuffer[MessageBufferSize];
		Receive(messageBuffer, MessageBufferSize);

		return V3DString(messageBuffer);
	}

	void V3DTCPSocket::SetNonBlocking() const
	{
		V3DSocketSetNonBlocking(tcpSocket);
	}
}
