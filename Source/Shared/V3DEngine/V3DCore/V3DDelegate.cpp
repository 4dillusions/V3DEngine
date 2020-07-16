/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DDelegate.h"

namespace V3D::V3DEngine::V3DCore
{
	void V3DDelegate::operator+=(const std::function<void()>& function)
	{
		functionList.Add(function);
	}

	void V3DDelegate::operator-=(const std::function<void()>& function)
	{
		for (functionList.First(); functionList.IsDone(); functionList.Next())
			if (functionList.GetCurrent()->target<void()>() == function.target<void()>())
			{
				functionList.RemoveCurrent();
				break;
			}
	}
	
	void V3DDelegate::operator()()
	{
		for (functionList.First(); functionList.IsDone(); functionList.Next())
			(*functionList.GetCurrent())();
	}
}
