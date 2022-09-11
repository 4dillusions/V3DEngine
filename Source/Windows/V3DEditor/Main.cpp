/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEdClient.h"
#include "V3DEngine/V3DCore/V3DIoc.h"
#include "V3DEngine/V3DCore/V3DIocManager.h"

#include <QApplication>

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEditor;

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	V3DIocManager::Init();
	
	auto client = V3DIoc<V3DEdClient>::CreateTransient();
	const int Result = client->Execute();
	V3DMemory::Delete(client);
	
	V3DIocManager::Clean();

	return Result;
}
