/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	class V3DDelegateEventTest final
	{
	public:
		V3DDelegateEventTest() = delete;
		V3DDelegateEventTest(const V3DDelegateEventTest&) = delete;
		V3DDelegateEventTest(V3DDelegateEventTest&&) = delete;
		~V3DDelegateEventTest() = delete;
		V3DDelegateEventTest& operator=(const V3DDelegateEventTest&) = delete;
		V3DDelegateEventTest& operator=(V3DDelegateEventTest&&) = delete;

		static void DelegateNoParamAddRemoveTest();
		static void DelegateParamAddRemoveTest();
		static void EventNoParamAddRemoveTest();
		static void EventParamAddRemoveTest();

		static void RunAllTests();
	};
}
