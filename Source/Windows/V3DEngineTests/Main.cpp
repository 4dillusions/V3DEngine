/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEngineTests/V3DTestRunner.h"
#include <iostream>

int main()
{
	V3D::V3DEngineTests::V3DEngine::V3DTestRunner::RunAllTests();
	std::system("pause");  // NOLINT(concurrency-mt-unsafe)
	
	return 0;
}
