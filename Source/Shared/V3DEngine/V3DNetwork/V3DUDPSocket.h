/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DEngineLibrary.h"

namespace V3D::V3DEngine::V3DCore
{
	class V3DString;
}

namespace V3D::V3DEngine::V3DNetwork
{
	class V3DSocketAddress;

	class V3DENGINE_API V3DUDPSocket final
	{
		int udpSocket;
		static constexpr int MessageBufferSize{ 512 };

	public:
		V3DUDPSocket();
		explicit V3DUDPSocket(int udpSocket);
		V3DUDPSocket(const V3DUDPSocket&) = delete;
		V3DUDPSocket(V3DUDPSocket&&) = delete;
		~V3DUDPSocket();
		V3DUDPSocket& operator=(const V3DUDPSocket&) = delete;
		V3DUDPSocket& operator=(V3DUDPSocket&&) = delete;
	
		void Bind(const V3DSocketAddress& toAddress) const;
		void BindAny(unsigned short int port = 0) const;
		int SendTo(const char* message, int messageLenght, const V3DSocketAddress& toAddress) const;
		int SendTo(const V3DCore::V3DString& message, const V3DSocketAddress& toAddress) const;
		int SendToLocalAll(const char* message, int messageLenght, const V3DSocketAddress& localAddress) const;
		int SendToLocalAll(const V3DCore::V3DString& message, const V3DSocketAddress& localAddress) const;
		int ReceiveFrom(char* messageOut, int messageLenght, const V3DSocketAddress& fromAddressOut) const;
		V3DCore::V3DString ReceiveFrom(const V3DSocketAddress& fromAddressOut) const;
		int ReceiveFromAny(char* messageOut, int messageLenght) const;
		V3DCore::V3DString ReceiveFromAny() const;

		void SetNonBlocking() const;
	};
}
