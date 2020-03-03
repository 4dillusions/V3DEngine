/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DRandom.h"
#include "V3DVector2D.h"

using namespace std;

// ReSharper disable CppLocalVariableMayBeConst
namespace V3D::V3DEngine::V3DMathematics
{
	random_device V3DRandom::entropySource;
	mt19937 V3DRandom::randGenerator{ entropySource() };
	
	int V3DRandom::CreateRandom(int min, int max)
	{
		uniform_int_distribution theIntDist(min, max);
				
		return theIntDist(randGenerator);
	}

	V3DVector2D V3DRandom::CreateRandom(const V3DVector2D& min, const V3DVector2D& max)
	{
		uniform_real_distribution<float> theIntDistX(min.x, max.x);
		uniform_real_distribution<float> theIntDistY(min.y, max.y);
		
		return V3DVector2D{ theIntDistX(randGenerator), theIntDistY(randGenerator) };
	}
}