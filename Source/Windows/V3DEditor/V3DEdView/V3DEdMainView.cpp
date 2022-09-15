/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEdMainView.h"
#include "V3DEdViewBindings.h"
#include "V3DEditor/V3DEdModel/V3DEdCommands.h"
#include "V3DEditor/V3DEdModel/V3DEdMainModel.h"
#include "V3DEditor/V3DEdModel/V3DEdBindingModel.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEditor::V3DEdModel;

namespace V3D::V3DEditor::V3DEdView
{
    V3DEdMainView::V3DEdMainView(V3DEdMainModel* mainModel, V3DEdViewBindings* viewBindings, QWidget* parent) : QMainWindow(parent), mainModel{ mainModel }, viewBindings{ viewBindings }
    {
        InitUI();
        InitBindings();
    }
    
    V3DEdMainView::~V3DEdMainView()
    {
        ViewActionRelease.Invoke();
        viewBindings->RemoveBindings(this);
    }

    void V3DEdMainView::InitUI()
    {
        ui.setupUi(this);

        tabifyDockWidget(ui.dockLevelGraph, ui.dockAssetBrowser);
        ui.dockLevelGraph->raise();

        tabifyDockWidget(ui.dockEngineLog, ui.dockOutputLog);
        ui.dockEngineLog->raise();
    }

    void V3DEdMainView::InitBindings()
    {
        viewBindings->AddBinding(V3DEdCommands::AddEngineLogItem, { this, ui.listEngineLog, &mainModel->engineLog });
        viewBindings->AddBinding(V3DEdCommands::ClearEngineLogItem, { this, ui.listEngineLog, &mainModel->engineLog });

        viewBindings->AddBinding(V3DEdCommands::AddOutputLogItem, { this, ui.listOutputLog, &mainModel->outputLog });
        viewBindings->AddBinding(V3DEdCommands::ClearOutputLogItem, { this, ui.listOutputLog, &mainModel->outputLog });
    }

    void V3DEdMainView::Update() const
    {
        viewBindings->Update(mainModel->command);
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

    void V3DEdMainView::OnEngineLogDeleteAllClicked() const
    {
        EngineLogDeleteAllAction.Invoke();
    }

    void V3DEdMainView::OnOutputLogDeleteAllClicked() const
    {
        OutputLogDeleteAllAction.Invoke();
    }
}
