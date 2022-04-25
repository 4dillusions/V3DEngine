/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DCore/V3DEnvironment.h"
#include "V3DMemoryInfo.h"
#include "V3DMemoryAllocatorTypes.h"

#include <unordered_map>

namespace V3D::V3DEngine::V3DCore
{
	//Avoid memory leaks with New/Delete instead of new/delete_ naked operators
	class V3DENGINE_API V3DMemory final
	{
		static std::unordered_map<int*, V3DMemoryInfo> memoryList;
		inline static bool isDebugMode{ V3DEnvironment::GetIsRunModeDebug() };
		
	public:
		V3DMemory() = default;
		V3DMemory(const V3DMemory&) = delete;
		V3DMemory(V3DMemory&&) = delete;
		~V3DMemory() = delete;
		V3DMemory& operator=(const V3DMemory&) = delete;
		V3DMemory& operator=(V3DMemory&&) = delete;

		static V3DString GetStatistics();

		static void Add(int* address, const V3DMemoryInfo& info);
		static void Remove(int* address, V3DMemoryAllocatorType allocType);
		static int GetMemoryLeakCount();
		static void WriteStatistics();
		static void WriteStatisticsForTests();

		template <typename T, typename TInfo> static T* New(TInfo info)
		{
			T* result = new T;

			const static bool isUnitTestMode{ V3DEnvironment::GetIsUnitTestMode() };
			if (isDebugMode || isUnitTestMode)
				V3DMemory::Add(reinterpret_cast<int*>(result), { info , V3DMemoryAllocatorType::NewMem });

			return result;
		}
		
		template <typename T, typename TInfo, typename P1> static T* New(TInfo info, P1 p1)
		{
			T* result = new T(p1);

			const static bool isUnitTestMode{ V3DEnvironment::GetIsUnitTestMode() };
			if (isDebugMode || isUnitTestMode)
				V3DMemory::Add(reinterpret_cast<int*>(result), { info , V3DMemoryAllocatorType::NewMem });

			return result;
		}

		template <typename T, typename P1> static T* NewExplicit(P1 p1)
		{
			return new T(p1);
		}

		template <typename T, typename TInfo, typename P1, typename P2> static T* New(TInfo info, P1 p1, P2 p2)
		{
			T* result = new T(p1, p2);

			const static bool isUnitTestMode{ V3DEnvironment::GetIsUnitTestMode() };
			if (isDebugMode || isUnitTestMode)
				V3DMemory::Add(reinterpret_cast<int*>(result), { info , V3DMemoryAllocatorType::NewMem });

			return result;
		}

		template <typename T, typename TInfo, typename P1, typename P2, typename P3> static T* New(TInfo info, P1 p1, P2 p2, P3 p3)
		{
			T* result = new T(p1, p2, p3);

			const static bool isUnitTestMode{ V3DEnvironment::GetIsUnitTestMode() };
			if (isDebugMode || isUnitTestMode)
				V3DMemory::Add(reinterpret_cast<int*>(result), { info , V3DMemoryAllocatorType::NewMem });

			return result;
		}

		template <typename T, typename TInfo, typename P1, typename P2, typename P3, typename P4> static T* New(TInfo info, P1 p1, P2 p2, P3 p3, P4 p4)
		{
			T* result = new T(p1, p2, p3, p4);

			const static bool isUnitTestMode{ V3DEnvironment::GetIsUnitTestMode() };
			if (isDebugMode || isUnitTestMode)
				V3DMemory::Add(reinterpret_cast<int*>(result), { info , V3DMemoryAllocatorType::NewMem });

			return result;
		}

		template <typename T, typename TInfo, typename P1, typename P2, typename P3, typename P4, typename P5> static T* New(TInfo info, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
		{
			T* result = new T(p1, p2, p3, p4, p5);

			const static bool isUnitTestMode{ V3DEnvironment::GetIsUnitTestMode() };
			if (isDebugMode || isUnitTestMode)
				V3DMemory::Add(reinterpret_cast<int*>(result), { info , V3DMemoryAllocatorType::NewMem });

			return result;
		}

		template <typename T, typename TInfo, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6> static T* New(TInfo info, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6)
		{
			T* result = new T(p1, p2, p3, p4, p5, p6);

			const static bool isUnitTestMode{ V3DEnvironment::GetIsUnitTestMode() };
			if (isDebugMode || isUnitTestMode)
				V3DMemory::Add(reinterpret_cast<int*>(result), { info , V3DMemoryAllocatorType::NewMem });

			return result;
		}

		template <typename T> static void Delete(T& obj)
		{
			const static bool isUnitTestMode{ V3DEnvironment::GetIsUnitTestMode() };
			if (isDebugMode || isUnitTestMode)
				Remove(reinterpret_cast<int*>(obj), V3DMemoryAllocatorType::NewMem);

			delete obj;
			obj = nullptr;
		}

		template <typename T, typename TInfo> static T* NewArray(TInfo info, unsigned int size)
		{
			T* result = new T[size];

			const static bool isUnitTestMode{ V3DEnvironment::GetIsUnitTestMode() };
			if (isDebugMode || isUnitTestMode)
				V3DMemory::Add(reinterpret_cast<int*>(result), { info , V3DMemoryAllocatorType::NewArrayMem });

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
				Remove(reinterpret_cast<int*>(obj), V3DMemoryAllocatorType::NewArrayMem);

			delete[]obj;
			obj = nullptr;
		}

		template <typename T, typename TInfo> static T** NewMatrix(TInfo info, unsigned int size)
		{
			T** result = new T * [size];

			const static bool isUnitTestMode{ V3DEnvironment::GetIsUnitTestMode() };
			if (isDebugMode || isUnitTestMode)
				V3DMemory::Add(reinterpret_cast<int*>(result), { info , V3DMemoryAllocatorType::NewMatrixMem });

			for (unsigned int x = 0; x < size; ++x)
			{
				result[x] = new T[size];

				if (isDebugMode || isUnitTestMode)
					V3DMemory::Add(reinterpret_cast<int*>(result[x]), { info , V3DMemoryAllocatorType::NewMatrixMem });
			}

			return result;
		}

		template <typename T> static void DeleteMatrix(T& obj, unsigned int sizeX)
		{
			const static bool isUnitTestMode{ V3DEnvironment::GetIsUnitTestMode() };
			
			for (unsigned int x = 0; x < sizeX; ++x)
			{
				if (isDebugMode || isUnitTestMode)
					Remove(reinterpret_cast<int*>(obj[x]), V3DMemoryAllocatorType::NewMatrixMem);

				delete[] obj[x];
			}

			if (isDebugMode || isUnitTestMode)
				Remove(reinterpret_cast<int*>(obj), V3DMemoryAllocatorType::NewMatrixMem);

			delete[] obj;

			obj = nullptr;
		}

		template <typename T, typename TInfo> static T** NewPointerArray(TInfo info, unsigned int size)
		{
			T** result = new T * [size];

			const static bool isUnitTestMode{ V3DEnvironment::GetIsUnitTestMode() };
			if (isDebugMode || isUnitTestMode)
				V3DMemory::Add(reinterpret_cast<int*>(result), { info , V3DMemoryAllocatorType::NewPointerArrayMem });

			return result;
		}

		template <typename T> static void DeletePointerArray(T& obj)
		{
			const static bool isUnitTestMode{ V3DEnvironment::GetIsUnitTestMode() };
			if (isDebugMode || isUnitTestMode)
				Remove(reinterpret_cast<int*>(obj), V3DMemoryAllocatorType::NewPointerArrayMem);

			delete[] obj;

			obj = nullptr;
		}
	};
}
