/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

// ReSharper disable CppMemberFunctionMayBeStatic
#pragma once

#include "V3DTestObjectB.h"

namespace V3D::V3DEngineTests::V3DTestObject
{
	class V3DTestEventActionFunc final
	{
		int& x;
		int number;

	public:
		V3DTestEventActionFunc(int& x, int number) : x{ x }, number{ number } {};
		V3DTestEventActionFunc(int& x) : V3DTestEventActionFunc{ x, 0 } {};

		void IncrementXWithNumber() const
		{
			x += number;
		}

		void MultiplicationXWithNumber() const
		{
			x *= number;
		}

		void IncrementXWithArgs(const V3DArgsTest& args) const
		{
			x += args.x;
		}

		void IncrementXWithParam(int param) const
		{
			x += param;
		}

		void MultiplicationXWithParam(int param) const
		{
			x *= param;
		}

		int SumParam() const
		{
			return 10;
		}

		int SumParam(int param) const
		{
			return param;
		}

		int SumParam(int param1, int param2) const
		{
			return param1 + param2;
		}

		int SumParam(int param1, int param2, int param3) const
		{
			return param1 + param2 + param3;
		}

		void AddParam() const
		{
			x += 10;
		}

		void AddParam(int param) const
		{
			x += param;
		}

		void AddParam(int param1, int param2) const
		{
			x += param1;
			x += param2;
		}

		void AddParam(int param1, int param2, int param3) const
		{
			x += param1;
			x += param2;
			x += param3;
		}
	};
}
