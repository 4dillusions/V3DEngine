/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEdMainView.h"

namespace V3D::V3DEditor::V3DEdView
{
    V3DEdMainView::V3DEdMainView(QWidget* parent) : QMainWindow(parent)
    {
        ui.setupUi(this);

        tabifyDockWidget(ui.dockLevelGraph, ui.dockAssetBrowser);
        ui.dockLevelGraph->raise();

        tabifyDockWidget(ui.dockEngineLog, ui.dockOutput);
        ui.dockEngineLog->raise();
    }
    
    V3DEdMainView::~V3DEdMainView()
    {
        ViewActionRelease.Invoke();
    }
    
    // ReSharper disable once CppParameterMayBeConstPtrOrRef
    void V3DEdMainView::OnToolBarAction(QAction* action) const
    {
	    const auto ActionName = action->objectName();

        if (ActionName == ui.actionAboutEditor->objectName())
            ToolBarActionAboutEditor.Invoke();
        else if (ActionName == ui.actionAboutQt->objectName())
            ToolBarActionAboutQt.Invoke();
    }
}
