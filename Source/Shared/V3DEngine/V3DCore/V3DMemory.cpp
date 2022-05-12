/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

// ReSharper disable CppUnusedIncludeDirective
#include "V3DMemory.h"
#include "V3DString.h" 
#include "V3DEngine/V3DIO/V3DLogger.h"

#include <unordered_map>
#include <string>

using namespace V3D::V3DEngine::V3DIO;

namespace V3D::V3DEngine::V3DCore
{
	std::unordered_map<int*, V3DMemoryInfo> V3DMemory::memoryList;

	int V3DMemory::GetMemoryLeakCount()
	{
		return static_cast<int>(memoryList.size());
	}

	V3DString V3DMemory::GetStatistics()
	{
		std::string result;
		result = "Leaked objects:\n";

		for (const auto& i : memoryList)  // NOLINT(clang-diagnostic-range-loop-construct)
			result += i.second.info + static_cast<const char>('\n');

		if (memoryList.empty())
			result += "0 leaked object";
		
		return V3DString(result.c_str());
	}

	void V3DMemory::Add(int* address, const V3DMemoryInfo& info)
	{
		memoryList.insert({ address, info });
	}

	// ReSharper disable once CppParameterMayBeConstPtrOrRef
	void V3DMemory::Remove(int* address, V3DMemoryAllocatorType allocType)
	{
		const auto search = memoryList.find(address);
		if (search != memoryList.end() && search->second.allocType == allocType)
			memoryList.erase(search);
	}

	void V3DMemory::WriteStatistics()
	{
		V3DLogger::Get().WriteOutput("");
		V3DLogger::Get().WriteOutput(GetStatistics());
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
