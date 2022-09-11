/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEdWindowManager.h"
#include "V3DEdEnvironment.h"
#include "V3DEdAssetPathType.h"
#include "V3DEditor/V3DEdView/V3DEdMainView.h"

#include <qsplashscreen.h>

#include <thread>

using namespace V3D::V3DEditor::V3DEdView;

using namespace std;
using namespace std::chrono_literals;

namespace V3D::V3DEditor::V3DEdCore
{
	V3DEdWindowManager::V3DEdWindowManager(V3DEdMainView* mainView) : mainView { mainView }
	{ }

	void V3DEdWindowManager::ShowSplashScreen()
	{
		const QPixmap pixmap(V3DEdEnvironment::GetAssetPath(V3DEdAssetPathType::EditorLogo));
		QSplashScreen splash(pixmap);
		splash.show();
		this_thread::sleep_for(1s);
		splash.close();
		//QApplication::processEvents();
	}

	void V3DEdWindowManager::ShowMainWindow()
	{
		mainView->setWindowState(Qt::WindowFullScreen);
		mainView->showMaximized();
	}
}
