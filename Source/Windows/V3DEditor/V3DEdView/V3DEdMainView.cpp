/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEdMainView.h"

namespace V3D::V3DEditor::V3DEdView
{
    V3DEdMainView::V3DEdMainView(QWidget* parent) : QMainWindow(parent), ui{}
    {
        ui.setupUi(this);
    }
}
