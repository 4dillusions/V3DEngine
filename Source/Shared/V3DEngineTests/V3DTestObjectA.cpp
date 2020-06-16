/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTestObjectA.h"

namespace V3D::V3DEngineTests
{
	int V3DTestObjectA::referenceCounter = 0;

	V3DTestObjectA::V3DTestObjectA()
	{
		referenceCounter++;
	}

	V3DTestObjectA::V3DTestObjectA(const V3DTestObjectA& value)
	{
		referenceCounter++;
	}

	V3DTestObjectA::~V3DTestObjectA()
	{
		referenceCounter--;
	}

	char V3DTestObjectA::GetTypeCode()
	{
		return 'A';
	}

	int V3DTestObjectA::GetId()
	{
		return id;
	}

	void V3DTestObjectA::SetId(int id)
	{
		this->id = id;
	}

	bool V3DTestObjectA::GetIsAlive()
	{
		return isAlive;
	}

	void V3DTestObjectA::SetIsAlive(bool isAlive)
	{
		this->isAlive = isAlive;
	}

	int V3DTestObjectA::GetReferenceCounter()
	{
		return referenceCounter;
	}

	void V3DTestObjectA::SetReferenceCounter(int counter)
	{
		referenceCounter = counter;
	}
}
