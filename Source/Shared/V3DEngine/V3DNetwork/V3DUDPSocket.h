/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DEngineLibrary.h"
#include "V3DEngine/V3DNetwork/V3DSocketHelper.h"

namespace V3D::V3DEngine::V3DNetwork
{
	class V3DSocketAddress;

	class V3DENGINE_API V3DUDPSocket final
	{
		SOCKET udpSocket;

	public:
		V3DUDPSocket();
		explicit V3DUDPSocket(SOCKET udpSocket);
		V3DUDPSocket(const V3DUDPSocket&) = delete;
		V3DUDPSocket(V3DUDPSocket&&) = delete;
		~V3DUDPSocket();
		V3DUDPSocket& operator=(const V3DUDPSocket&) = delete;
		V3DUDPSocket& operator=(V3DUDPSocket&&) = delete;
	
		void Bind(V3DSocketAddress& toAddress) const;
		int SendTo(const char* message, int messageLenght, V3DSocketAddress& toAddress) const;
		int SendToAll(const char* message, int messageLenght, V3DSocketAddress& localAddress) const;
		int ReceiveFrom(char* messageOut, int messageLenght, V3DSocketAddress& fromAddressOut) const;

		void SetNonBlocking() const;
	};
}
