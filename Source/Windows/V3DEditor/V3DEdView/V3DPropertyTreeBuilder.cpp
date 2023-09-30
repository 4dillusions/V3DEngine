/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DPropertyTreeBuilder.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngine/V3DCore/V3DString.h"
#include "V3DEngine/V3DIO/V3DJsonIO.h"
#include "V3DEngine/V3DIO/V3DJsonVariant.h"
#include "V3DEngine/V3DMacros.h"

#include "ThirdParty/Json/json.hpp"

#include <QTreeWidget>
#include <QHeaderView>
#include <QCheckBox>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QSpinBox>
#include <QInputDialog>
#include <QMessageBox>

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DIO;

using json = nlohmann::json;

namespace V3D::V3DEditor::V3DEdView
{
	void V3DPropertyTreeBuilder::InitTreeWidget(const QTreeWidget* treeWidget)
	{
		treeWidget->headerItem()->setText(0, "Property");
		treeWidget->headerItem()->setText(1, "Value");
		treeWidget->header()->resizeSections(QHeaderView::Interactive);
	}

	nlohmann::json* V3DPropertyTreeBuilder::BuildTreeWidget(const char* jsonText, QTreeWidget* treeWidget)
	{
		return TreeWidgetBuilder(jsonText, treeWidget, nullptr);
	}

	void V3DPropertyTreeBuilder::BuildTreeNodeWidget(QTreeWidget* treeWidget, nlohmann::json* jsonNode)
	{
		TreeWidgetBuilder(nullptr, treeWidget, jsonNode);
	}
	
	json* V3DPropertyTreeBuilder::TreeWidgetBuilder(const char* jsonText, QTreeWidget* treeWidget, nlohmann::json* jsonNode)
	{
		const auto Result = jsonNode == nullptr ? V3DMemory::New<json>(V3DFILE_INFO, V3DJsonIO::GetJsonObject(jsonText)) : jsonNode;
		QTreeWidgetItem* parentTreeItem;
		V3DAction1<const V3DJsonVariant&> traversalAction;
		traversalAction.Set([&](const V3DJsonVariant& variant)
		{
			const V3DString Name(variant.name);
			const bool IsArrayItem = Name.IsEmpty();
			QTreeWidgetItem* currentTreeItem;
			
			if (IsArrayItem)
				currentTreeItem = V3DMemory::New<QTreeWidgetItem>(V3DFILE_INFO, parentTreeItem);
			else
				currentTreeItem = V3DMemory::New<QTreeWidgetItem>(V3DFILE_INFO, treeWidget);
			
			currentTreeItem->setText(0, Name.ToChar());

			QWidget* parent = IsArrayItem ? dynamic_cast<QWidget*>(parentTreeItem) : dynamic_cast<QWidget*>(treeWidget);
			QWidget* currentItemWidget = CreateItemWidget(treeWidget, parent, parentTreeItem, currentTreeItem, variant);

			if (currentItemWidget != nullptr)
				treeWidget->setItemWidget(currentTreeItem, 1, currentItemWidget);
			
			if (IsArrayItem)
				parentTreeItem->addChild(currentTreeItem);
			else
				treeWidget->addTopLevelItem(currentTreeItem);
		});
		V3DJsonIO::TraversalJsonHierarchy(*Result, nullptr, traversalAction);

		return Result;
	}
	
	QWidget* V3DPropertyTreeBuilder::CreateQCheckBox(QWidget* parent, bool checked)
	{
		const auto Result = V3DMemory::New<QCheckBox>(V3DFILE_INFO, parent);
		Result->setChecked(checked);

		return Result;
	}

	QWidget* V3DPropertyTreeBuilder::CreateQTextOrLineEdit(QWidget* parent, const char* text)
	{
		QWidget* result;

		if (QString(text).contains('\n'))
		{
			result = V3DMemory::New<QTextEdit>(V3DFILE_INFO, parent);
			dynamic_cast<QTextEdit*>(result)->setText(text);
		}
		else
		{
			result = V3DMemory::New<QLineEdit>(V3DFILE_INFO, parent);
			dynamic_cast<QLineEdit*>(result)->setText(text);
		}

		return result;
	}

	QWidget* V3DPropertyTreeBuilder::CreateQSpinBox(QWidget* parent, int number)
	{
		const auto Result = V3DMemory::New<QSpinBox>(V3DFILE_INFO, parent);
		Result->setMinimum(std::numeric_limits<int>::min());
		Result->setMaximum(std::numeric_limits<int>::max());
		Result->setValue(number);

		return Result;
	}

	QWidget* V3DPropertyTreeBuilder::CreateQSpinBox(QWidget* parent, unsigned int number)
	{
		const auto Result = dynamic_cast<QSpinBox*>(CreateQSpinBox(parent, static_cast<int>(number)));
		Result->setMinimum(0);
		Result->setMaximum(std::numeric_limits<int>::max());

		return Result;
	}

	QWidget* V3DPropertyTreeBuilder::CreateQDoubleSpinBox(QWidget* parent, double number)
	{
		const auto Result = V3DMemory::New<QDoubleSpinBox>(V3DFILE_INFO, parent);
		Result->setMinimum(std::numeric_limits<double>::min());
		Result->setMaximum(std::numeric_limits<double>::max());
		Result->setDecimals(7);
		Result->setValue(number);

		return Result;
	}

	QWidget* V3DPropertyTreeBuilder::CreateArrayEditQPushButton(QWidget* parent)
	{
		const auto Result = V3DMemory::New<QPushButton>(V3DFILE_INFO, parent);
		Result->setText("[...]");

		return Result;
	}

	void V3DPropertyTreeBuilder::AddBindingToArrayButton(QPushButton* button, const V3DJsonVariant& variant, QTreeWidgetItem* currentTreeItem, QTreeWidget* treeWidget)
	{
		QObject::connect(button, &QPushButton::clicked, [=]
		{
			QStringList items;
			auto originalJsonArrayObject = *static_cast<json::array_t*>(variant.array);
			for (const auto& Item : originalJsonArrayObject)
			{
				items.append(Item.dump().c_str());
				items.append(",");
			}
			items.removeLast();

			const QString OriginalText = items.join("");
			bool dialogOk{};
			QString dialogResultText;
			json resultJsonObject;
			
			auto ShowJsonBuildDialog = [=, &dialogOk, &dialogResultText, &resultJsonObject](const QString& input)
			{
				dialogResultText = QInputDialog::getText(button, QString(variant.name), "Edit items:", QLineEdit::Normal, input, &dialogOk);
				const auto ResultJSonText = V3DString("{\"") + variant.name + "\":[" + dialogResultText.toStdString().c_str() + "]}";
				resultJsonObject = V3DJsonIO::GetJsonObject(ResultJSonText.ToChar());
			};
			
			ShowJsonBuildDialog(OriginalText);
			
			while(dialogOk && resultJsonObject.empty())
			{
				QMessageBox::critical(button, "Json parse error", QString(V3DJsonIO::GetLastError()));
				ShowJsonBuildDialog(dialogResultText);
			}

			if (dialogOk && !resultJsonObject.empty() && dialogResultText != OriginalText)
			{
				DeleteTreeWidgetItem(currentTreeItem, treeWidget);

				originalJsonArrayObject.clear();
				for (const auto& Item : resultJsonObject.begin().value())
					originalJsonArrayObject.push_back(Item);
				
				BuildTreeNodeWidget(treeWidget, &resultJsonObject); //második gombnyomáskor kiakad, de elsőre se jó, mert nem az eredeti array megy, így a variant se arra fog mutatni stb
				//a bindingolás az egyes widgetekhez majd bekerül az elemekhez egyúttal, ahogy itt is

				//kellene egy dump plusz tree item utoljára, ahhoz meg valami create metódus
			}
		});
	}
	
	QWidget* V3DPropertyTreeBuilder::CreateItemWidget(QTreeWidget* treeWidget, QWidget* parent, QTreeWidgetItem*& parentTreeItem, QTreeWidgetItem* currentTreeItem, const V3DJsonVariant& variant)
	{
		QWidget* result{};

		switch (variant.currentType)
		{
		case V3DJsonVariantTypes::Null:
			currentTreeItem->setText(1, "NULL");
			break;

		case V3DJsonVariantTypes::Boolean:
			result = CreateQCheckBox(parent, *variant.boolean);
			break;

		case V3DJsonVariantTypes::IntNumber:
			result = CreateQSpinBox(parent, static_cast<unsigned int>(*variant.intNumber));
			break;

		case V3DJsonVariantTypes::UnsignedIntNumber:
			result = CreateQSpinBox(parent, static_cast<int>(*variant.unsignedIntNumber));
			break;

		case V3DJsonVariantTypes::DoubleNumber:
			result = CreateQDoubleSpinBox(parent, *variant.floatNumber);
			break;

		case V3DJsonVariantTypes::Text:
			result = CreateQTextOrLineEdit(parent, variant.text->c_str());
			break;

		case V3DJsonVariantTypes::Object:
			parentTreeItem = currentTreeItem;
			break;

		case V3DJsonVariantTypes::Array:
			result = CreateArrayEditQPushButton(parent);
			AddBindingToArrayButton(dynamic_cast<QPushButton*>(result), variant, currentTreeItem, treeWidget);
			
			parentTreeItem = currentTreeItem;
			break;
		}

		return result;
	}

	void V3DPropertyTreeBuilder::DeleteTreeWidgetItem(QTreeWidgetItem* currentTreeItem, QTreeWidget* treeWidget)
	{
		for (int index = 0; index < currentTreeItem->childCount(); index++)
			DeleteTreeWidgetItem(currentTreeItem->child(index), treeWidget);

		if (currentTreeItem->childCount() == 0)
		{
			if (treeWidget != nullptr)
				if (auto widget = treeWidget->itemWidget(currentTreeItem, 1))
				{
					treeWidget->removeItemWidget(currentTreeItem, 1);
					V3DMemory::Delete(widget);
				}

			V3DMemory::Delete(currentTreeItem);
		}
		else
			DeleteTreeWidgetItem(currentTreeItem, treeWidget);
	}

	void V3DPropertyTreeBuilder::DeleteTreeWidget(QTreeWidget* treeWidget)
	{
		while(treeWidget->topLevelItemCount() > 0)
			DeleteTreeWidgetItem(treeWidget->topLevelItem(0), treeWidget);
	}
}
