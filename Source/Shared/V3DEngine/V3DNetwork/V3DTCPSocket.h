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

	class V3DENGINE_API V3DTCPSocket final
	{
		int tcpSocket;
		static constexpr int MessageBufferSize{ 512 };

	public:
		V3DTCPSocket();
		explicit V3DTCPSocket(int tcpSocket);
		V3DTCPSocket(const V3DTCPSocket&) = delete;
		V3DTCPSocket(V3DTCPSocket&&) = delete;
		~V3DTCPSocket();
		V3DTCPSocket& operator=(const V3DTCPSocket&) = delete;
		V3DTCPSocket& operator=(V3DTCPSocket&&) = delete;

		void Connect(const V3DSocketAddress& address) const;
		void Bind(const V3DSocketAddress& toAddress) const;
		void Listen() const;
		V3DTCPSocket* Accept(const V3DSocketAddress& fromAddress) const;
		int Send(const char* message, int messageLenght) const;
		int Send(const V3DCore::V3DString& message) const;
		int Receive(char* messageOut, int messageLenght) const;
		V3DCore::V3DString Receive() const;

		void SetNonBlocking() const;
	};
}
