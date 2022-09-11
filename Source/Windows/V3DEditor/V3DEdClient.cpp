/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEdClient.h"
#include "V3DEdCore/V3DEdEnvironment.h"
#include "V3DEdCore/V3DEdAssetPathType.h"
#include "V3DEdView/V3DEdMainView.h"

#include <QApplication>
#include <qsplashscreen.h>
#include <qfile.h>

#include <thread>

#include "V3DEdCore/V3DEdIWindowManager.h"

using namespace V3D::V3DEditor::V3DEdCore;
using namespace V3D::V3DEditor::V3DEdView;
using namespace std;
using namespace std::chrono_literals;

namespace V3D::V3DEditor
{
	V3DEdClient::V3DEdClient(V3DEdIWindowManager* windowManager) : windowManager{ windowManager }
	{ }

	int V3DEdClient::Execute() const
	{
		windowManager->ShowSplashScreen();
		
		QFile file(V3DEdEnvironment::GetAssetPath(V3DEdAssetPathType::EditorSkinStyle));
		file.open(QFile::ReadOnly);
		const QString StyleSheet = QLatin1String(file.readAll());
		qApp->setStyleSheet(StyleSheet);
		
		windowManager->ShowMainWindow();

		return QApplication::exec();
	}
}
