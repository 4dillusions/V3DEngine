/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEditor::V3DEdModel
{
	struct V3DEdBindingModel;
	enum class V3DEdCommands;
}
	
namespace V3D::V3DEditor::V3DEdView
{
	class V3DEdViewBindings final
	{
		void* bindings;

	public:
		V3DEdViewBindings();
		V3DEdViewBindings(const V3DEdViewBindings&) = delete;
		V3DEdViewBindings(V3DEdViewBindings&&) = delete;
		~V3DEdViewBindings();
		V3DEdViewBindings& operator=(const V3DEdViewBindings&) = delete;
		V3DEdViewBindings& operator=(V3DEdViewBindings&&) = delete;

		void AddBinding(V3DEdModel::V3DEdCommands command, const V3DEdModel::V3DEdBindingModel& bindingModel) const;
		void Update(V3DEdModel::V3DEdCommands command) const;
		void RemoveBindings(const void* view) const;

	private:
		void UpdateAddLogItem(void* widget, void* data) const;
		void UpdateClearLogItem(void* widget, void* data) const;
	};
}
