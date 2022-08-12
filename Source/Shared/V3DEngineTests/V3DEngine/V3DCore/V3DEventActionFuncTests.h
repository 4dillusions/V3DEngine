/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	class V3DEventActionFuncTests final
	{
	public:
		V3DEventActionFuncTests() = delete;
		V3DEventActionFuncTests(const V3DEventActionFuncTests&) = delete;
		V3DEventActionFuncTests(V3DEventActionFuncTests&&) = delete;
		~V3DEventActionFuncTests() = delete;
		V3DEventActionFuncTests& operator=(const V3DEventActionFuncTests&) = delete;
		V3DEventActionFuncTests& operator=(V3DEventActionFuncTests&&) = delete;

		static void ActionSetInvokeTest();
		static void FuncSetInvokeTest();
		static void EventNoParamAddRemoveInvokeTest();
		static void EventParamAddRemoveInvokeTest();

		static void RunAllUnitTests();
		static void RegisterIntegrationTests();
		static void RegisterTimingTests();
	};
}
