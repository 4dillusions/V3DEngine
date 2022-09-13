/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEdViewManager.h"

#include "V3DEdEnvironment.h"
#include "V3DEdAssetPathType.h"
#include "V3DEngine/V3DCore/V3DIoc.h"
#include "V3DEditor/V3DEdView/V3DEdMainView.h"
#include "V3DEditor/V3DEdController/V3DEdMainController.h"

#include <qsplashscreen.h>
#include <QMessageBox>
#include <QAbstractButton>

#include <thread>

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEditor::V3DEdView;
using namespace V3D::V3DEditor::V3DEdController;

using namespace std;
using namespace std::chrono_literals;

namespace V3D::V3DEditor::V3DEdCore
{
	V3DEdViewManager::V3DEdViewManager(V3DEdMainView* mainView) : mainView { mainView } //ez csak azért lett injektálva mert singleton, a többi transient elemet nem kell
	{ }

	void V3DEdViewManager::ShowSplashView()
	{
		QSplashScreen splashView(QPixmap(V3DEdEnvironment::GetAssetPath(V3DEdAssetPathType::EditorLogo)));
		splashView.show();
		this_thread::sleep_for(1s);
		splashView.close();
		//QApplication::processEvents();
	}

	void V3DEdViewManager::ShowMainView()
	{
		const auto MainController = V3DIoc<V3DEdMainController>::CreateTransient();
		mainView->ToolBarActionAboutEditor.Set([=] { MainController->OnToolBarAboutEditor(); });
		mainView->ToolBarActionAboutQt.Set([=] { MainController->OnToolBarAboutQt(); });
		mainView->ViewActionRelease.Set([=]
		{
			auto controller = MainController;
			V3DMemory::Delete(controller);
		});

		mainView->setWindowState(Qt::WindowFullScreen);
		mainView->showMaximized();
	}

	void V3DEdViewManager::ShowAboutEditorView()
	{
		QMessageBox messageBox;
		messageBox.setIconPixmap(QPixmap(V3DEdEnvironment::GetAssetPath(V3DEdAssetPathType::EditorLogo)));
		messageBox.setWindowTitle("About V3DEditor");
		messageBox.setDetailedText("V3D Game engine editor. This is free and open source project.\ngithub repo: github.com/4dillusions\nteam website: 4dillusions.com\n\n© 2022 4D Illusions - Robert Oze");

		const auto BtnDetails = messageBox.buttons().takeLast();
		BtnDetails->click();
		
		messageBox.exec();
	}

	void V3DEdViewManager::ShowAboutQtView()
	{
		QApplication::aboutQt();
	}
}
