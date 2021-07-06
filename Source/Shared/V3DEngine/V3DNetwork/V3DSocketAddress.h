/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DCore/V3DString.h"

struct sockaddr_in;

namespace V3D::V3DEngine::V3DNetwork
{
	struct V3DIpV4Address;
	
	class V3DENGINE_API V3DSocketAddress final
	{
		sockaddr_in* sockAddress;
		
	public:
		V3DSocketAddress();
		V3DSocketAddress(unsigned short int port);
		V3DSocketAddress(unsigned short int port, const char* ip);
		V3DSocketAddress(unsigned short int port, const V3DIpV4Address& ip);
		V3DSocketAddress(const V3DSocketAddress&) = delete;
		V3DSocketAddress(V3DSocketAddress&&) = delete;
		~V3DSocketAddress();
		V3DSocketAddress& operator=(const V3DSocketAddress&) = delete;
		V3DSocketAddress& operator=(V3DSocketAddress&&) = delete;

		sockaddr_in* GetSockAddress() const;
		V3DCore::V3DString GetIp() const;
		V3DCore::V3DString GetPort() const;
		
		static V3DCore::V3DString GetPublicIpFromHostName(const char* hostname);
		//static V3DCore::V3DString GetLocalHostName();
		static V3DCore::V3DString GetLocalIp();

		V3DCore::V3DString ToString() const;
	};
}
