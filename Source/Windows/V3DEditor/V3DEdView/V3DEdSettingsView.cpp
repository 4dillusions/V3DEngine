/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEdSettingsView.h"
#include "V3DEdViewBindings.h"
#include "V3DPropertyTreeBuilder.h"
//#include "V3DEditor/V3DEdModel/V3DEdCommands.h"
#include "V3DEditor/V3DEdModel/V3DEdSettingsModel.h"
//#include "V3DEditor/V3DEdModel/V3DEdBindingModel.h"

//using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEditor::V3DEdModel;

namespace V3D::V3DEditor::V3DEdView
{
    V3DEdSettingsView::V3DEdSettingsView(V3DEdSettingsModel* settingsModel, V3DEdViewBindings* viewBindings, V3DPropertyTreeBuilder* propertyTreeBuilder, QWidget* parent)
		: QDialog(parent), settingsModel{ settingsModel }, viewBindings{ viewBindings }, propertyTreeBuilder{ propertyTreeBuilder }
    {
        InitUI();
        InitBindings();
    }
    
    V3DEdSettingsView::~V3DEdSettingsView()
    {
        ViewActionRelease.Invoke();
        viewBindings->RemoveViewBindings(this);
    }

    QTreeWidget* V3DEdSettingsView::GetTreeEditorStyleProperties() const
    {
        return ui.treeEditorStyleProperties;
    }

    QTreeWidget* V3DEdSettingsView::GetTreeGameProperties() const
    {
        return ui.treeGameProperties;
    }

    void V3DEdSettingsView::ShowDialog()
    {
        LoadAction.Invoke();
        exec();
    }

    void V3DEdSettingsView::InitUI()
    {
        ui.setupUi(this);
        setWindowFlags(Qt::Dialog | Qt::Desktop);

        propertyTreeBuilder->InitTreeWidget(ui.treeEditorStyleProperties);
        propertyTreeBuilder->InitTreeWidget(ui.treeGameProperties);
    }
    
    void V3DEdSettingsView::InitBindings() const
    {
        viewBindings->UpdateCanExecuteBindings(this);
    }
    
    void V3DEdSettingsView::Update() const
    {
        viewBindings->Update(settingsModel->command);
    }
    
    void V3DEdSettingsView::OnSaveClicked() const
    {
        SaveAction.Invoke();
    }
}