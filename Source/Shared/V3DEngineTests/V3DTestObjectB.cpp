/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTestObjectB.h"

namespace V3D::V3DEngineTests
{
	/*void V3DTestObjectB::PerformTestEvent(Args args)
	{
		TestEvent(args);
	}*/

	char V3DTestObjectB::GetTypeCode()
	{
		return 'B';
	}

	int V3DTestObjectB::GetId()
	{
		return id;
	}

	void V3DTestObjectB::SetId(int id)
	{
		this->id = id;
	}
	
	bool V3DTestObjectB::GetIsAlive()
	{
		return isAlive;
	}
	
	void V3DTestObjectB::SetIsAlive(bool isAlive)
	{
		this->isAlive = isAlive;
	}
}
