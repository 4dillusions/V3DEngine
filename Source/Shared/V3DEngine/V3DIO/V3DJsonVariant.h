/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DJsonVariantTypes.h"
#include <stdint.h>
#include <string>

namespace V3D::V3DEngine::V3DIO
{
	class V3DENGINE_API V3DJsonVariant final
	{
	public:
		const char* name{};
		const char* parentName{};
		V3DJsonVariantTypes currentType = V3DJsonVariantTypes::Null;
		
		bool* boolean{};

		//long (x86), long long (x64), for using in real data suggested: long
		std::int64_t* intNumber{};

		//unsigned long (x86), unsigned long long (x64), for using in real data suggested: unsigned long
		std::uint64_t* unsignedIntNumber{};

		double* floatNumber{};

		std::string* text{};

		void* array{};
	};
}
