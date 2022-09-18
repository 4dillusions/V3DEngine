/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEdViewManager.h"
#include "V3DEdMainView.h"
#include "V3DEdSettingsView.h"
#include "V3DEditor/V3DEdCore/V3DEdEnvironment.h"
#include "V3DEditor/V3DEdCore/V3DEdAssetPathType.h"
#include "V3DEditor/V3DEdLocator/V3DEdModelLocator.h"
#include "V3DEditor/V3DEdLocator/V3DEdControllerLocator.h"
#include "V3DEditor/V3DEdController/V3DEdMainController.h"
#include "V3DEngine/V3DCore/V3DIoc.h"

//log test
//#include "V3DEngine/V3DCore/V3DString.h"
//#include "V3DEngine/V3DIO/V3DLogger.h"
//#include "V3DEditor/V3DEdService/V3DEdMainService.h"

#include <qsplashscreen.h>
#include <QMessageBox>
#include <QAbstractButton>

#include <thread>

using namespace V3D::V3DEditor::V3DEdCore;
using namespace V3D::V3DEditor::V3DEdModel;
using namespace V3D::V3DEditor::V3DEdLocator;
using namespace V3D::V3DEditor::V3DEdController;
using namespace V3D::V3DEngine::V3DCore;

using namespace std;
using namespace std::chrono_literals;

namespace V3D::V3DEditor::V3DEdView
{
	V3DEdViewManager::V3DEdViewManager(V3DEdControllerLocator* controllerLocator, V3DEdMainView* mainView)
		: controllerLocator{ controllerLocator }, mainView{ mainView } //mainView etc. are singleton, no need inject the other transient depencies
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
		const auto MainController = controllerLocator->CreateOrGetMainController();

		mainView->ToolBarActionSettings.Set([=] { MainController->OnToolBarSettings(); });
		mainView->ToolBarActionAboutEditor.Set([=] { MainController->OnToolBarAboutEditor(); });
		mainView->ToolBarActionAboutQt.Set([=] { MainController->OnToolBarAboutQt(); });

		mainView->EngineLogDeleteAllAction.Set([=] { MainController->OnEngineLogDeleteAll(); });
		mainView->OutputLogDeleteAllAction.Set([=] { MainController->OnOutputLogDeleteAll(); });

		mainView->ViewActionRelease.Set([=]
		{
			V3DIoc<V3DEdModelLocator>::GetSingleton()->ReleaseMainModel(); //created & injected for View and Service by IoCManager with locator
			V3DIoc<V3DEdControllerLocator>::GetSingleton()->ReleaseMainController();
		});

		mainView->setWindowState(Qt::WindowFullScreen);
		mainView->showMaximized();
	}

	void V3DEdViewManager::ShowSettingsView()
	{
		auto settingsView = V3DIoc<V3DEdSettingsView>::CreateTransient();

		settingsView->ViewActionRelease.Set([=]
		{
			V3DIoc<V3DEdModelLocator>::GetSingleton()->ReleaseSettingsModel(); //created & injected for View and Service by IoCManager with locator
			//V3DIoc<V3DEdControllerLocator>::GetSingleton()->ReleaseSettingsController(); //TODO
		});

		settingsView->exec();

		V3DMemory::Delete(settingsView);
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

		//V3DEngine::V3DIO::V3DLogger::Get().WriteOutput(V3DEngine::V3DIO::V3DLogMessageType::Info, "void V3DEdViewManager::ShowAboutQtView()"); //log test
	}

	void V3DEdViewManager::ShowAboutQtView()
	{
		QApplication::aboutQt();

		//V3DIoc<V3DEdService::V3DEdMainService>::GetSingleton()->OutputLogWrite(V3DEngine::V3DIO::V3DLogMessageType::Info, V3DString("void V3DEdViewManager::ShowAboutEditorView()")); //log test
	}

	void V3DEdViewManager::UpdateMainView()
	{
		mainView->Update();
	}
}
