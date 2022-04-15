/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DFakeitTests.h"

/*
	Cancelled, because of Fakeit library doesn't work on Android API 19
*/
//#include "V3DEngineTests/V3DTest.h"
//#include "V3DEngine/V3DMacros.h"
//
//#include "ThirdParty/Fakeit/standalone/fakeit.hpp"
//#include "V3DEngineTests/V3DTestObject/V3DITestInterface.h"
//
//using namespace fakeit;
//using namespace V3D::V3DEngineTests::V3DTestObject;

namespace V3D::V3DEngineTests::V3DTestMock
{
	void V3DFakeitTests::RunAllTests()
	{
       /* Mock<V3DITestInterface> mock;
        V3DITestInterface& interf = mock.get();

        When(Method(mock, GetResult)).AlwaysDo([&]()
        {
            if (interf.GetIsSucceed())
                return interf.GetCount() * 10;
            else
                return interf.GetCount() * 100;
        });
        When(Method(mock, GetIsSucceed)).AlwaysReturn(false);
        When(Method(mock, GetCount)).AlwaysReturn(10);

        V3DTest::AssertOk(!interf.GetIsSucceed(), V3DFILE_INFO);
        V3DTest::AssertOk(interf.GetCount() == 10, V3DFILE_INFO);
        V3DTest::AssertOk(interf.GetResult() == 1000, V3DFILE_INFO);*/
	}
}
