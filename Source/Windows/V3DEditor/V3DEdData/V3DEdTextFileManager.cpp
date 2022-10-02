/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEdTextFileManager.h"
#include "V3DEditor/V3DEdCore/V3DEdEnvironment.h"
#include "V3DEngine/V3DCore/V3DString.h"
#include "V3DEngine/V3DIO/V3DTextRW.h"

using namespace V3D::V3DEditor::V3DEdCore;
using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DIO;

namespace V3D::V3DEditor::V3DEdData
{
	V3DString* V3DEdTextFileManager::ReadEditorStyle() const
	{
		return V3DTextRW::Read(V3DAssetPathType::EditorContent, V3DEdEnvironment::GetEditorStyleFileName());
	}

	void V3DEdTextFileManager::WriteEditorStyle(const V3DString& text) const
	{
		V3DTextRW::Write(V3DEdEnvironment::GetFileFullName(V3DAssetPathType::EditorContent, V3DEdEnvironment::GetEditorStyleFileName()), text);
	}

	V3DString* V3DEdTextFileManager::ReadOptions(const char* fileName) const
	{
		return V3DTextRW::Read(V3DAssetPathType::Options, fileName);
	}

	void V3DEdTextFileManager::WriteOptions(const char* fileName, const V3DString& text) const
	{
		V3DTextRW::Write(V3DEdEnvironment::GetFileFullName(V3DAssetPathType::Options, fileName), text);
	}
}
