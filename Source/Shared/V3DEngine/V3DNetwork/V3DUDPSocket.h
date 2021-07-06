/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DEngineLibrary.h"
#include "V3DEngine/V3DNetwork/V3DSocketHelper.h"

namespace V3D::V3DEngine::V3DCore
{
	class V3DString;
}

namespace V3D::V3DEngine::V3DNetwork
{
	class V3DSocketAddress;

	class V3DENGINE_API V3DUDPSocket final
	{
		SOCKET udpSocket;
		static const int MessageBufferSize{ 512 };

	public:
		V3DUDPSocket();
		explicit V3DUDPSocket(SOCKET udpSocket);
		V3DUDPSocket(const V3DUDPSocket&) = delete;
		V3DUDPSocket(V3DUDPSocket&&) = delete;
		~V3DUDPSocket();
		V3DUDPSocket& operator=(const V3DUDPSocket&) = delete;
		V3DUDPSocket& operator=(V3DUDPSocket&&) = delete;
	
		void Bind(V3DSocketAddress& toAddress) const;
		void BindAny(unsigned short int port = 0) const;
		int SendTo(const char* message, int messageLenght, V3DSocketAddress& toAddress) const;
		int SendTo(const V3DCore::V3DString& message, V3DSocketAddress& toAddress) const;
		int SendToAll(const char* message, int messageLenght, V3DSocketAddress& localAddress) const;
		int SendToAll(const V3DCore::V3DString& message, V3DSocketAddress& localAddress) const;
		int ReceiveFrom(char* messageOut, int messageLenght, V3DSocketAddress& fromAddressOut) const;
		V3DCore::V3DString ReceiveFrom(V3DSocketAddress& fromAddressOut) const;
		int ReceiveFromAny(char* messageOut, int messageLenght) const;
		V3DCore::V3DString ReceiveFromAny() const;

		void SetNonBlocking() const;
	};
}
