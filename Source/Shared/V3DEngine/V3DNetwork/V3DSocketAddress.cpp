/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DSocketAddress.h"
#include "V3DIpV4Address.h"
#include "V3DEngine/V3DIO/V3DLogger.h"
#include "V3DEngine/V3DNetwork/V3DNetworkSystem.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DIO;

namespace V3D::V3DEngine::V3DNetwork
{
	V3DSocketAddress::V3DSocketAddress()
	{
		sockAddress = V3DMemory::New<sockaddr_in>(V3DFILE_INFO);
	}
	
	V3DSocketAddress::V3DSocketAddress(unsigned short int port) : V3DSocketAddress()
	{
		sockAddress->sin_family = AF_INET;
		sockAddress->sin_port = htons(port);
		sockAddress->sin_addr.s_addr = htonl(INADDR_ANY); //sockAddress->sin_addr.S_un.S_addr = INADDR_ANY;
	}
	
	V3DSocketAddress::V3DSocketAddress(unsigned short int port, const char* ip) : V3DSocketAddress(port)
	{
		inet_pton(AF_INET, ip, &sockAddress->sin_addr);
	}
	
	V3DSocketAddress::V3DSocketAddress(unsigned short int port, const V3DIpV4Address& ip) : V3DSocketAddress(port)
	{
		constexpr int Multiply1 = 256 * 256 * 256;
		constexpr int Multiply2 = 256 * 256;
		
		sockAddress->sin_addr.s_addr = htonl(ip.addr1 * Multiply1 + ip.addr2 * Multiply2 + ip.addr3 * 256 + ip.addr4); //inet_pton(AF_INET, ip.ToString().ToChar(), &sockAddress->sin_addr);
	}
	
	V3DSocketAddress::~V3DSocketAddress()
	{
		V3DMemory::Delete(sockAddress);
	}
	
	sockaddr_in* V3DSocketAddress::GetSockAddress() const
	{
		return sockAddress;
	}

	V3DString V3DSocketAddress::GetIp() const
	{
		constexpr int HostNameLenght = 16;
		char host[HostNameLenght] = {};
		inet_ntop(AF_INET, &sockAddress->sin_addr, host, HostNameLenght);

		int realLen = 0;
		for (const char i : host)
		{
			if (i == '\00')
				break;

			realLen++;
		}

		V3DString res(host);
		return res;
	}

	V3DString V3DSocketAddress::GetPort() const
	{
		const auto port = ntohs(sockAddress->sin_port);

		return V3DString(port);
	}
	
	V3DString V3DSocketAddress::GetPublicIpFromHostName(const char* hostname)
	{
		addrinfo* addressInfo;
		if (getaddrinfo(hostname, nullptr, nullptr, &addressInfo) != 0)
		{
			V3DLogger::Get().WriteOutput(V3DLogMessageType::Error, V3DString("Can't get ip from hostname! '") + hostname + "'");
			return {};
		}

		const auto* address = reinterpret_cast<struct sockaddr_in*>(addressInfo->ai_addr);
		char str[INET_ADDRSTRLEN];
		inet_ntop(AF_INET, &address->sin_addr, str, INET_ADDRSTRLEN);

		return V3DString(str);
	}
	
	/*V3DString V3DSocketAddress::GetLocalHostName()
	{
		char host[256];
		gethostname(host, sizeof host);

		return V3DString(host);
	}*/
	
	V3DString V3DSocketAddress::ToString() const
	{
		return GetIp() + ":" + GetPort();
	}
}
