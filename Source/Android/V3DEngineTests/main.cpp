/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEngine/android_native_app_glue.h"
#include "V3DEngineTests/V3DTestRunner.h"
#include "V3DEngine/V3DCore/V3DIoc.h"
#include "V3DEngine/V3DCore/V3DEnvironment.h"

struct engine
{
	struct android_app* app;
	int animating;
};

static int32_t engine_handle_input(struct android_app* app, AInputEvent* event)
{
	switch (AInputEvent_getType(event))
	{
	case AINPUT_EVENT_TYPE_KEY:
		if (AKeyEvent_getAction(event) == AKEY_EVENT_ACTION_UP)
			if (AKeyEvent_getKeyCode(event) == AKEYCODE_BACK)
			{
				V3D::V3DEngineTests::V3DEngine::V3DTestRunner::RunAllTests();

				return 1;
			}
		break;

	default:;
	}

	return 0;
}

static void engine_handle_cmd(struct android_app* app, int32_t cmd)
{
	auto engine = static_cast<struct engine*>(app->userData);

	switch (cmd)
	{
	case APP_CMD_TERM_WINDOW:
	case APP_CMD_LOST_FOCUS:
		engine->animating = 0;
		break;

	default:;
	}
}

void android_main(struct android_app* state)
{
	engine engine{}; //memset(&engine, 0, sizeof(engine));

	state->userData = &engine;
	state->onAppCmd = engine_handle_cmd;
	state->onInputEvent = engine_handle_input;

	engine.app = state;
	engine.animating = 1;
	
	int events;
	struct android_poll_source* source;

	V3D::V3DEngine::V3DCore::V3DIoc<V3D::V3DEngine::V3DCore::V3DEnvironment>::Get().SetApp(state);
	
	while (true)
	{
		while (ALooper_pollAll(engine.animating ? 0 : -1, nullptr, &events, reinterpret_cast<void**>(&source)) >= 0)
		{
			if (source != nullptr)
				source->process(state, source);

			if (state->destroyRequested != 0)
			{
				engine.animating = 0;
				return;
			}
		}
	}
}
