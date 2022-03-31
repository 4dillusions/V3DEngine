/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DDelegateEventTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngineTests/V3DTestObject/V3DTestObjectB.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngineTests::V3DTestObject;

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	void V3DDelegateEventTests::DelegateNoParamAddRemoveTest()
	{
		int x = 100;
		auto obj = V3DMemory::New<V3DTestObjectB>(V3DFILE_INFO);

		const std::function<void()> Func1 = [&x]() { x += 5; };
		obj->TestNoParamDelegate = Func1;
		obj->TestNoParamDelegate();
		V3DTest::AssertOk(x == 105, V3DFILE_INFO);

		const std::function<void()> Func2 = [&x]() { x += 10; };
		obj->TestNoParamDelegate = Func2;
		obj->TestNoParamDelegate();
		V3DTest::AssertOk(x == 115, V3DFILE_INFO);

		obj->TestNoParamDelegate = nullptr;
		obj->TestNoParamDelegate();
		V3DTest::AssertOk(x == 115, V3DFILE_INFO);

		V3DMemory::Delete(obj);
	}
	
	void V3DDelegateEventTests::DelegateParamAddRemoveTest()
	{
		const V3DArgsTest EventArgs{ 5 };
		int x = 100;
		auto obj = V3DMemory::New<V3DTestObjectB>(V3DFILE_INFO);

		const std::function<void(const V3DArgsTest& args)> Func1 = [&x](const V3DArgsTest& args) { x += args.x; };
		obj->TestParamDelegate = Func1;
		obj->TestParamDelegate(EventArgs);
		V3DTest::AssertOk(x == 105, V3DFILE_INFO);

		const std::function<void(const V3DArgsTest& args)> Func2 = [&x](const V3DArgsTest& args) { x += (args.x * 2); };
		obj->TestParamDelegate = Func2;
		obj->TestParamDelegate(EventArgs);
		V3DTest::AssertOk(x == 115, V3DFILE_INFO);

		obj->TestParamDelegate = nullptr;
		obj->TestParamDelegate(EventArgs);
		V3DTest::AssertOk(x == 115, V3DFILE_INFO);

		V3DMemory::Delete(obj);
	}

	void V3DDelegateEventTests::EventNoParamAddRemoveTest()
	{
		int x = 100;
		auto obj = V3DMemory::New<V3DTestObjectB>(V3DFILE_INFO);

		const std::function<void()> Func1 = [&x]() { x += 5; };
		obj->TestNoParamEvent += Func1;
		const std::function<void()> Func2 = [&x]() { x += 10; };
		obj->TestNoParamEvent += Func2;

		obj->TestNoParamEvent();

		V3DTest::AssertOk(x == 115, V3DFILE_INFO);

		obj->TestNoParamEvent -= Func1;
		obj->TestNoParamEvent();
		V3DTest::AssertOk(x == 125, V3DFILE_INFO);

		obj->TestNoParamEvent -= Func2;
		obj->TestNoParamEvent();
		V3DTest::AssertOk(x == 125, V3DFILE_INFO);

		V3DMemory::Delete(obj);
	}
	
	void V3DDelegateEventTests::EventParamAddRemoveTest()
	{
		int x = 100;
		const V3DArgsTest EventArgs{ 5 };
		auto obj = V3DMemory::New<V3DTestObjectB>(V3DFILE_INFO);

		const std::function<void(const V3DArgsTest& args)> Func1 = [&x](const V3DArgsTest& args) { x += args.x; };
		obj->TestParamEvent += Func1;
		const std::function<void(const V3DArgsTest& args)> Func2 = [&x](const V3DArgsTest& args) { x += (args.x * 2); };
		obj->TestParamEvent += Func2;

		obj->TestParamEvent(EventArgs);

		V3DTest::AssertOk(x == 115, V3DFILE_INFO);

		obj->TestParamEvent -= Func1;
		obj->TestParamEvent(EventArgs);
		V3DTest::AssertOk(x == 125, V3DFILE_INFO);

		obj->TestParamEvent -= Func2;
		obj->TestParamEvent(EventArgs);
		V3DTest::AssertOk(x == 125, V3DFILE_INFO);

		V3DMemory::Delete(obj);
	}
	
	void V3DDelegateEventTests::RunAllTests()
	{
		DelegateNoParamAddRemoveTest();
		DelegateParamAddRemoveTest();
		EventNoParamAddRemoveTest();
		EventParamAddRemoveTest();
	}
}
