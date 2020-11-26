/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DNetTest.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DNetwork/V3DNet.h"

using namespace V3D::V3DEngine::V3DNetwork;

namespace V3D::V3DEngineTests::V3DEngine::V3DNetwork
{
	void V3DNetTest::InitTest()
	{
		V3DTest::AssertOk(V3DNet::Init(), V3DFILE_INFO);
		V3DNet::Cleanup();
	}
	
	void V3DNetTest::RunAllTests()
	{	
		InitTest();
	}
}
