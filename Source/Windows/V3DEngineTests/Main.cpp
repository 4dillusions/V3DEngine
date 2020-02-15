/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include <iostream>
using namespace std;

#include "V3DEngine/V3DEngine.h"

int main()
{
	V3DEngine::V3DEngineTest engineTest;
	if (engineTest.Test(1, 2) == 3)
		cout << "Test ok!\n";
	else
		cout << "Test failed!\n";

	system("pause");
	
	return 0;
}
