/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DDelegateEventTest.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngineTests/V3DTestObjectB.h"

using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	void V3DDelegateEventTest::DelegateAddRemoveTest()
	{
		int x = 100;
		auto obj = V3DMemory::New<V3DTestObjectB>(V3DFILE_INFO);

		const std::function<void()> Func1 = [&x]() { x += 5; };
		obj->TestDelegate += Func1;
		const std::function<void()> Func2 = [&x]() { x += 10; };
		obj->TestDelegate += Func2;

		obj->TestDelegate();

		V3DTest::AssertOk(x == 115, V3DFILE_INFO);

		obj->TestDelegate -= Func1;
		obj->TestDelegate();
		V3DTest::AssertOk(x == 125, V3DFILE_INFO);
		
		obj->TestDelegate -= Func2;
		obj->TestDelegate();
		V3DTest::AssertOk(x == 125, V3DFILE_INFO);

		V3DMemory::Delete(obj);
	}
	
	void V3DDelegateEventTest::EventAddRemoveTest()
	{
		int x = 100;
		const V3DArgsTest EventArgs{ 5 };
		auto obj = V3DMemory::New<V3DTestObjectB>(V3DFILE_INFO);

		const std::function<void(const V3DArgsTest& args)> Func1 = [&x](const V3DArgsTest& args) { x += args.x; };
		obj->TestEvent += Func1;
		const std::function<void(const V3DArgsTest& args)> Func2 = [&x](const V3DArgsTest& args) { x += (args.x * 2); };
		obj->TestEvent += Func2;

		obj->TestEvent(EventArgs);

		V3DTest::AssertOk(x == 115, V3DFILE_INFO);

		obj->TestEvent -= Func1;
		obj->TestEvent(EventArgs);
		V3DTest::AssertOk(x == 125, V3DFILE_INFO);

		obj->TestEvent -= Func2;
		obj->TestEvent(EventArgs);
		V3DTest::AssertOk(x == 125, V3DFILE_INFO);

		V3DMemory::Delete(obj);
	}
	
	void V3DDelegateEventTest::RunAllTests()
	{
		DelegateAddRemoveTest();
		EventAddRemoveTest();
	}
}
