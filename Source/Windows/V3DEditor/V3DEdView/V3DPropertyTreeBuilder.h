/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "ThirdParty/Json/json_fwd.hpp"

namespace V3D::V3DEngine::V3DIO
{
	class V3DJsonVariant;
}

class QWidget;
class QTreeWidget;
class QTreeWidgetItem;
class QPushButton;

namespace V3D::V3DEditor::V3DEdView
{
	/*
	Scaffold builder helper for PropertyTree widget
	Using json text format for input/output communicate

	There are two use cases:
	I. Memory object settings:
		send json string from Camera DTO with V3DEdCameraJsonRepository for example (Camera is a node object in scenegraph)
		get json text from json object pointer result and init DTO with repository, update view

	II. Config json text:
		load json config text with V3DEdTextFileManager, pass it to Builder
		get json text from json object pointer result and save it with the FileManager

	This json text communication and serializing/deserializing between property tree and DTO
	is hard to implement and very difficult, but it is a workaround before C++23's reflection
	*/
	class V3DPropertyTreeBuilder final
	{
	public:
		void InitTreeWidget(const QTreeWidget* treeWidget);
		nlohmann::json* BuildTreeWidget(const char* jsonText, QTreeWidget* treeWidget);
		
		void DeleteTreeWidget(QTreeWidget* treeWidget);

	private:
		QWidget* CreateQCheckBox(QWidget* parent, bool checked);
		QWidget* CreateQTextOrLineEdit(QWidget* parent, const char* text);
		QWidget* CreateQSpinBox(QWidget* parent, unsigned int number);
		QWidget* CreateQSpinBox(QWidget* parent, int number);
		QWidget* CreateQDoubleSpinBox(QWidget* parent, double number);
		QWidget* CreateArrayEditQPushButton(QWidget* parent);

		void AddBindingToArrayButton(QPushButton* button, const V3DEngine::V3DIO::V3DJsonVariant& variant, QTreeWidgetItem* currentTreeItem, QTreeWidget* treeWidget);

		QWidget* CreateItemWidget(QTreeWidget* treeWidget, QWidget* parent, QTreeWidgetItem*& parentTreeItem, QTreeWidgetItem* currentTreeItem, const V3DEngine::V3DIO::V3DJsonVariant& variant);

		void DeleteTreeWidgetItem(QTreeWidgetItem* currentTreeItem, QTreeWidget* treeWidget);

		void BuildTreeNodeWidget(QTreeWidget* treeWidget, nlohmann::json* jsonNode);
		nlohmann::json* TreeWidgetBuilder(const char* jsonText, QTreeWidget* treeWidget, nlohmann::json* jsonNode);
	};
}
