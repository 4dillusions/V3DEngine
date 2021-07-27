/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	class V3DDelegateEventTests final
	{
	public:
		V3DDelegateEventTests() = delete;
		V3DDelegateEventTests(const V3DDelegateEventTests&) = delete;
		V3DDelegateEventTests(V3DDelegateEventTests&&) = delete;
		~V3DDelegateEventTests() = delete;
		V3DDelegateEventTests& operator=(const V3DDelegateEventTests&) = delete;
		V3DDelegateEventTests& operator=(V3DDelegateEventTests&&) = delete;

		static void DelegateNoParamAddRemoveTest();
		static void DelegateParamAddRemoveTest();
		static void EventNoParamAddRemoveTest();
		static void EventParamAddRemoveTest();

		static void RunAllTests();
	};
}
