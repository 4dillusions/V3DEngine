/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests
{
	//unit test interface for basic test objects
	class V3DITestObject
	{
	public:
		virtual ~V3DITestObject() = default;
		
		virtual char GetTypeCode() = 0;
		virtual int GetId() = 0;
		virtual void SetId(int id) = 0;
		virtual bool GetIsAlive() = 0;
		virtual void SetIsAlive(bool isAlive) = 0;
	};
}
