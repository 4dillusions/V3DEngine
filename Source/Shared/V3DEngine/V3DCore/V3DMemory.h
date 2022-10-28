/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DCore/V3DEnvironment.h"
#include "V3DMemoryInfo.h"
#include "V3DMemoryAllocatorTypes.h"

// ReSharper disable once CppUnusedIncludeDirective
#include <unordered_map>

namespace V3D::V3DEngine::V3DCore
{
	//Avoid memory leaks with New/Delete instead of new/delete_ naked operators
	class V3DENGINE_API V3DMemory final
	{
		static std::unordered_map<void*, V3DMemoryInfo> memoryDictionary;
		inline static bool isDebugMode{ V3DEnvironment::GetIsRunModeDebug() };

		static std::string GetMemoryAllocatorTypeText(V3DMemoryAllocatorType allocType);
		
	public:
		V3DMemory() = default;
		V3DMemory(const V3DMemory&) = delete;
		V3DMemory(V3DMemory&&) = delete;
		~V3DMemory() = delete;
		V3DMemory& operator=(const V3DMemory&) = delete;
		V3DMemory& operator=(V3DMemory&&) = delete;

		static V3DString GetStatistics();

		static void Add(void* address, const V3DMemoryInfo& info);
		static void Remove(void* address, V3DMemoryAllocatorType allocType);
		static int GetMemoryLeakCount();
		static void WriteStatistics();
		static void WriteStatisticsForTests();

		template <typename T> static T* PlacementNew(T* address)
		{
			return new (address) T;
		}

		template <typename T, typename TInfo> static T* New(TInfo info)
		{
			T* result = new T;

			const static bool isUnitTestMode{ V3DEnvironment::GetIsUnitTestMode() };
			if (isDebugMode || isUnitTestMode)
				V3DMemory::Add(static_cast<void*>(result), { info , V3DMemoryAllocatorType::NewMem });

			return result;
		}
		
		template <typename T, typename TInfo, typename... TParams> static T* New(TInfo info, TParams... params)
		{
			T* result = new T(std::forward<TParams>(params)...);

			const static bool isUnitTestMode{ V3DEnvironment::GetIsUnitTestMode() };
			if (isDebugMode || isUnitTestMode)
				V3DMemory::Add(static_cast<void*>(result), { info , V3DMemoryAllocatorType::NewMem });

			return result;
		}

		template <typename T, typename TParam> static T* NewExplicit(TParam param)
		{
			return new T(param);
		}
		
		template <typename T> static void Delete(T& obj)
		{
			const static bool isUnitTestMode{ V3DEnvironment::GetIsUnitTestMode() };
			if (isDebugMode || isUnitTestMode)
				Remove(static_cast<void*>(obj), V3DMemoryAllocatorType::NewMem);

			delete obj;
			obj = nullptr;
		}

		template <typename T, typename TInfo> static T* NewArray(TInfo info, unsigned int size)
		{
			T* result = new T[size];

			const static bool isUnitTestMode{ V3DEnvironment::GetIsUnitTestMode() };
			if (isDebugMode || isUnitTestMode)
				V3DMemory::Add(static_cast<void*>(result), { info , V3DMemoryAllocatorType::NewArrayMem });

			return result;
		}

		template <typename T> static T* NewArrayExplicit(unsigned int size)
		{
			return new T[size];
		}

		template <typename T> static void DeleteArray(T& obj)
		{
			const static bool isUnitTestMode{ V3DEnvironment::GetIsUnitTestMode() };
			if (isDebugMode || isUnitTestMode)
				Remove(static_cast<void*>(obj), V3DMemoryAllocatorType::NewArrayMem);

			delete[]obj;
			obj = nullptr;
		}

		template <typename T, typename TInfo> static T** NewMatrix(TInfo info, unsigned int size)
		{
			T** result = new T * [size];

			const static bool isUnitTestMode{ V3DEnvironment::GetIsUnitTestMode() };
			if (isDebugMode || isUnitTestMode)
				V3DMemory::Add(static_cast<void*>(result), { info , V3DMemoryAllocatorType::NewMatrixMem });

			for (unsigned int x = 0; x < size; ++x)
			{
				result[x] = new T[size];

				if (isDebugMode || isUnitTestMode)
					V3DMemory::Add(static_cast<void*>(result[x]), { info , V3DMemoryAllocatorType::NewMatrixMem });
			}

			return result;
		}

		template <typename T> static void DeleteMatrix(T& obj, unsigned int sizeX)
		{
			const static bool isUnitTestMode{ V3DEnvironment::GetIsUnitTestMode() };
			
			for (unsigned int x = 0; x < sizeX; ++x)
			{
				if (isDebugMode || isUnitTestMode)
					Remove(static_cast<void*>(obj[x]), V3DMemoryAllocatorType::NewMatrixMem);

				delete[] obj[x];
			}

			if (isDebugMode || isUnitTestMode)
				Remove(static_cast<void*>(obj), V3DMemoryAllocatorType::NewMatrixMem);

			delete[] obj;

			obj = nullptr;
		}

		template <typename T, typename TInfo> static T** NewPointerArray(TInfo info, unsigned int size)
		{
			T** result = new T * [size];

			const static bool isUnitTestMode{ V3DEnvironment::GetIsUnitTestMode() };
			if (isDebugMode || isUnitTestMode)
				V3DMemory::Add(static_cast<void*>(result), { info , V3DMemoryAllocatorType::NewPointerArrayMem });

			return result;
		}

		template <typename T> static void DeletePointerArray(T& obj)
		{
			const static bool isUnitTestMode{ V3DEnvironment::GetIsUnitTestMode() };
			if (isDebugMode || isUnitTestMode)
				Remove(static_cast<void*>(obj), V3DMemoryAllocatorType::NewPointerArrayMem);

			delete[] obj;

			obj = nullptr;
		}
	};
}
