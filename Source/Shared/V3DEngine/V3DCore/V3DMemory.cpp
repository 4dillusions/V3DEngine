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
	std::unordered_map<void*, V3DMemoryInfo> V3DMemory::memoryDictionary;

	int V3DMemory::GetMemoryLeakCount()
	{
		return static_cast<int>(memoryDictionary.size());
	}

	std::string V3DMemory::GetMemoryAllocatorTypeText(V3DMemoryAllocatorType allocType)
	{
		std::string result;

		switch (allocType)
		{
			case V3DMemoryAllocatorType::NewMem: result.append("(NewMem) "); break;
			case V3DMemoryAllocatorType::NewArrayMem: result.append("(NewArrayMem) "); break;
			case V3DMemoryAllocatorType::NewMatrixMem: result.append("(NewMatrixMem) "); break;
			case V3DMemoryAllocatorType::NewPointerArrayMem: result.append("(NewPointerArrayMem) "); break;
		}

		return result;
	}

	V3DString V3DMemory::GetStatistics()
	{
		std::string result;
		result = "Leaked objects:\n";

		for (const auto& i : memoryDictionary)  // NOLINT(clang-diagnostic-range-loop-construct)
		{
			const auto allocType = GetMemoryAllocatorTypeText(i.second.allocType);
			result += allocType + i.second.info + static_cast<const char>('\n');
		}

		if (memoryDictionary.empty())
			result += "0 leaked object";
		
		return V3DString(result.c_str());
	}

	void V3DMemory::Add(void* address, const V3DMemoryInfo& info)
	{
		memoryDictionary.insert({ address, info });
	}

	// ReSharper disable once CppParameterMayBeConstPtrOrRef
	void V3DMemory::Remove(void* address, V3DMemoryAllocatorType allocType)
	{
		const auto search = memoryDictionary.find(address);
		if (search != memoryDictionary.end() && search->second.allocType == allocType)
			memoryDictionary.erase(search);
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
