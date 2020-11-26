/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

//Error	C4996 'inet_ntoa': Use inet_ntop() or InetNtop() instead or define _WINSOCK_DEPRECATED_NO_WARNINGS to disable deprecated API warnings
//Error	C4996 'gethostbyname': Use getaddrinfo() or GetAddrInfoW() instead or define _WINSOCK_DEPRECATED_NO_WARNINGS to disable deprecated API warnings
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "Windows.h"
#include "WinSock2.h"
#include "WS2tcpip.h"
