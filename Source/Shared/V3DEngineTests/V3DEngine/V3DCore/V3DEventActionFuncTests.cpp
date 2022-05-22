/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEventActionFuncTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngineTests/V3DTestObject/V3DTestEventActionFunc.h"
#include "V3DEngineTests/V3DTestObject/V3DTestObjectB.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngineTests::V3DTestObject;

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	void V3DEventActionFuncTests::ActionSetInvokeTest()
	{
		int x = 100;
		auto obj = V3DMemory::New<V3DTestObjectB>(V3DFILE_INFO);
		V3DTestEventActionFunc test(x);

		x = 100;
		auto Func = [&x] { x += 5; };
		obj->TestAction.Set(Func);
		obj->TestAction.Invoke();
		V3DTest::AssertOk(x == 105, V3DFILE_INFO);
		x = 100;
		obj->TestAction.Set(&V3DTestEventActionFunc::AddParam, test);
		obj->TestAction.Invoke();
		V3DTest::AssertOk(x == 110, V3DFILE_INFO);

		x = 100;
		auto Func1 = [&x](int param) { x += param; };
		obj->TestAction1.Set(Func1);
		obj->TestAction1.Invoke(5);
		V3DTest::AssertOk(x == 105, V3DFILE_INFO);
		x = 100;
		obj->TestAction1.Set(&V3DTestEventActionFunc::AddParam, test);
		obj->TestAction1.Invoke(10);
		V3DTest::AssertOk(x == 110, V3DFILE_INFO);

		x = 100;
		auto Func2 = [&x](int param1, int param2) { x += param1; x += param2; };
		obj->TestAction2.Set(Func2);
		obj->TestAction2.Invoke(10, 20);
		V3DTest::AssertOk(x == 130, V3DFILE_INFO);
		x = 100;
		obj->TestAction2.Set(&V3DTestEventActionFunc::AddParam, test);
		obj->TestAction2.Invoke(10, 20);
		V3DTest::AssertOk(x == 130, V3DFILE_INFO);

		x = 100;
		auto Func3 = [&x](int param1, int param2, int param3) { x += param1; x += param2; x += param3; };
		obj->TestAction3.Set(Func3);
		obj->TestAction3.Invoke(10, 20, 30);
		V3DTest::AssertOk(x == 160, V3DFILE_INFO);
		x = 100;
		obj->TestAction3.Set(&V3DTestEventActionFunc::AddParam, test);
		obj->TestAction3.Invoke(10, 20, 30);
		V3DTest::AssertOk(x == 160, V3DFILE_INFO);

		V3DMemory::Delete(obj);
	}

	void V3DEventActionFuncTests::FuncSetInvokeTest()
	{
		int x = 0;
		auto obj = V3DMemory::New<V3DTestObjectB>(V3DFILE_INFO);
		V3DTestEventActionFunc test(x);

		auto Func = [] { return 5; };
		obj->TestFunc.Set(Func);
		x = obj->TestFunc.Invoke();
		V3DTest::AssertOk(x == 5, V3DFILE_INFO);
		obj->TestFunc.Set(&V3DTestEventActionFunc::SumParam, test);
		x = obj->TestFunc.Invoke();
		V3DTest::AssertOk(x == 10, V3DFILE_INFO);
		
		auto Func1 = [](int param) { return param; };
		obj->TestFunc1.Set(Func1);
		x = obj->TestFunc1.Invoke(5);
		V3DTest::AssertOk(x == 5, V3DFILE_INFO);
		obj->TestFunc1.Set(&V3DTestEventActionFunc::SumParam, test);
		x = obj->TestFunc1.Invoke(10);
		V3DTest::AssertOk(x == 10, V3DFILE_INFO);
		
		auto Func2 = [](int param1, int param2) { return param1 + param2; };
		obj->TestFunc2.Set(Func2);
		x = obj->TestFunc2.Invoke(10, 20);
		V3DTest::AssertOk(x == 30, V3DFILE_INFO);
		obj->TestFunc2.Set(&V3DTestEventActionFunc::SumParam, test);
		x = obj->TestFunc2.Invoke(10, 20);
		V3DTest::AssertOk(x == 30, V3DFILE_INFO);
		
		auto Func3 = [](int param1, int param2, int param3) { return param1 + param2 + param3; };
		obj->TestFunc3.Set(Func3);
		x = obj->TestFunc3.Invoke(10, 20, 30);
		V3DTest::AssertOk(x == 60, V3DFILE_INFO);
		obj->TestFunc3.Set(&V3DTestEventActionFunc::SumParam, test);
		x = obj->TestFunc3.Invoke(10, 20, 30);
		V3DTest::AssertOk(x == 60, V3DFILE_INFO);

		V3DMemory::Delete(obj);
	}

	void V3DEventActionFuncTests::EventNoParamAddRemoveInvokeTest()
	{
		int x = 100;
		auto obj = V3DMemory::New<V3DTestObjectB>(V3DFILE_INFO);

		auto Func1 = [&x] { x += 5; };
		obj->TestNoParamEvent.Add(Func1);
		
		V3DTestEventActionFunc test(x, 10);
		obj->TestNoParamEvent.Add(&V3DTestEventActionFunc::IncrementXWithNumber, test);

		obj->TestNoParamEvent.Invoke();

		V3DTest::AssertOk(x == 115, V3DFILE_INFO);

		obj->TestNoParamEvent.Remove(Func1);
		obj->TestNoParamEvent.Invoke();
		V3DTest::AssertOk(x == 125, V3DFILE_INFO);

		obj->TestNoParamEvent.Remove(&V3DTestEventActionFunc::IncrementXWithNumber, test);
		obj->TestNoParamEvent.Invoke();
		V3DTest::AssertOk(x == 125, V3DFILE_INFO);

		V3DMemory::Delete(obj);
	}
	
	void V3DEventActionFuncTests::EventParamAddRemoveInvokeTest()
	{
		int x = 100;
		constexpr V3DArgsTest EventArgs{ 5 };
		auto obj = V3DMemory::New<V3DTestObjectB>(V3DFILE_INFO);
		
		V3DTestEventActionFunc test(x);
		obj->TestParamEvent.Add(&V3DTestEventActionFunc::IncrementXWithArgs, test);

		auto Func2 = [&x](const V3DArgsTest& args) { x += (args.x * 2); };
		obj->TestParamEvent.Add(Func2);

		obj->TestParamEvent.Invoke(EventArgs);

		V3DTest::AssertOk(x == 115, V3DFILE_INFO);

		obj->TestParamEvent.Remove(&V3DTestEventActionFunc::IncrementXWithArgs, test);
		obj->TestParamEvent.Invoke(EventArgs);
		V3DTest::AssertOk(x == 125, V3DFILE_INFO);

		obj->TestParamEvent.Remove(Func2);
		obj->TestParamEvent.Invoke(EventArgs);
		V3DTest::AssertOk(x == 125, V3DFILE_INFO);

		V3DMemory::Delete(obj);
	}
	
	void V3DEventActionFuncTests::RunAllTests()
	{
		ActionSetInvokeTest();
		FuncSetInvokeTest();
		EventNoParamAddRemoveInvokeTest();
		EventParamAddRemoveInvokeTest();
	}
}
