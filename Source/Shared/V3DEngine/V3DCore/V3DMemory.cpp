/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DMemory.h"
// ReSharper disable once CppUnusedIncludeDirective
#include "V3DString.h" 
#include "V3DEngine/V3DIO/V3DLogger.h"

#include <unordered_map>

using namespace V3D::V3DEngine::V3DIO;

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

	void V3DMemory::WriteStatistics()
	{
		V3DLogger::Get().DeleteBuffer();
		V3DLogger::Get().WriteOutput("");
		V3DLogger::Get().WriteOutput("Leaked objects:");

		for (const auto i : memoryList)  // NOLINT(clang-diagnostic-range-loop-construct)
			V3DLogger::Get().WriteOutput(i.second);

		if (memoryList.empty())
			V3DLogger::Get().WriteOutput("0 leaked object");
	}

	void V3DMemory::WriteStatisticsForTests()
	{
		WriteStatistics();
		
		V3DLogger::Get().WriteOutput("");
		V3DLogger::Get().WriteOutput("Warnings:");
		V3DLogger::Get().WriteOutput(V3DLogger::Get().GetWarnings());

		V3DLogger::Get().WriteOutput("");
		V3DLogger::Get().WriteOutput("Errors:");
		V3DLogger::Get().WriteOutput(V3DLogger::Get().GetErrors());
	}
}
