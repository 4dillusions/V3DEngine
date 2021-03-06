/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DNetworkSystem.h"

namespace V3D::V3DEngine::V3DNetwork
{
	inline void V3DSocketClose(SOCKET socket)
	{
		close(socket);
	}

	inline void V3DSocketSetNonBlocking(SOCKET socket)
	{
		int flags = fcntl(socket, F_GETFL, 0);
		flags = flags | O_NONBLOCK;
		fcntl(socket, F_SETFL, flags);
	}
}
