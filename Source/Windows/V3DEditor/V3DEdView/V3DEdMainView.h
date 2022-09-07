/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_V3DEdMainView.h"

class V3DEdMainView : public QMainWindow
{
    Q_OBJECT

public:
    V3DEdMainView(QWidget *parent = nullptr);
    ~V3DEdMainView();

private:
    Ui::V3DEdMainViewClass ui;
};
