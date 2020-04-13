/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DMemory.h"

#include <unordered_map>

using namespace std;

namespace V3D::V3DEngine::V3DCore
{
	std::unordered_map<int*, const char*> V3DMemory::memoryList;

	int V3DMemory::GetMemoryLeakCount()
	{
		return static_cast<int>(memoryList.size());
	}

	void V3DMemory::Add(int* address, const char* info)
	{
		memoryList.insert({ address, info });
	}

	void V3DMemory::Remove(int* address)
	{
		const auto search = memoryList.find(address);
		if (search != memoryList.end())
			memoryList.erase(search);
	}

	void V3DMemory::WriteStatistics(bool isTest)
	{
		/*V3DIoc<V3DLogger>::Get().ReleaseBuffer();

		V3DIoc<V3DLogger>::Get().WriteOutput("");
		V3DIoc<V3DLogger>::Get().WriteOutput("Leaked objects:");

		for (auto i : memoryList)
			V3DIoc<V3DLogger>::Get().WriteOutput(i.second);

		if (memoryList.size() == 0)
			V3DIoc<V3DLogger>::Get().WriteOutput("0 leaked object");

		if (!isTest)
		{
			V3DIoc<V3DLogger>::Get().WriteOutput("");
			V3DIoc<V3DLogger>::Get().WriteOutput("Warnings:");
			V3DIoc<V3DLogger>::Get().WriteOutput(V3DIoc<V3DLogger>::Get().GetWarnings());

			V3DIoc<V3DLogger>::Get().WriteOutput("");
			V3DIoc<V3DLogger>::Get().WriteOutput("Errors:");
			V3DIoc<V3DLogger>::Get().WriteOutput(V3DIoc<V3DLogger>::Get().GetErrors());
		}

		V3DIoc<V3DLogger>::Get().WriteOutput("");*/
	}
}
