/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEngine/V3DNetwork/V3DSocketHelper.h"
#include "V3DNetworkSystem.h"

namespace V3D::V3DEngine::V3DNetwork
{
	void V3DSocketHelper::Close(int socket)
	{
		closesocket(socket);
	}

	void V3DSocketHelper::SetNonBlocking(int socket)
	{
		u_long arg = 1;
		ioctlsocket(socket, FIONBIO, &arg);
	}
}
