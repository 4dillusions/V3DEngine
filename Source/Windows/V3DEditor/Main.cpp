/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEdView/V3DEdMainView.h"

#include <QtWidgets/QApplication>
#include <qsplashscreen.h>
#include <qfile.h>

#include <thread>

using namespace std;
using namespace std::chrono_literals;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    const QPixmap pixmap("Assets/EditorContent/V3DLogoLarge.png");
	QSplashScreen splash(pixmap);
	splash.show();
	this_thread::sleep_for(1s);
    splash.close();
    QApplication::processEvents();

	QFile File("Assets/EditorContent/darkorange.qss");
	File.open(QFile::ReadOnly);
    const QString StyleSheet = QLatin1String(File.readAll());
	qApp->setStyleSheet(StyleSheet);

    V3DEdMainView w;
    w.setWindowState(Qt::WindowFullScreen);
    w.showMaximized();
    return QApplication::exec();
}
