/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEngine/V3DIO/V3DJsonIO.h"
#include "V3DJsonVariantTypes.h"
#include "V3DJsonVariant.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngine/V3DIO/V3DLogger.h"

#include "ThirdParty/Json/json.hpp"

using namespace V3D::V3DEngine::V3DCore;

using json = nlohmann::json;

namespace V3D::V3DEngine::V3DIO
{
	const char* V3DJsonIO::GetLastError()
	{
		return nlohmann::ExceptionData::lastException.c_str();
	}

	char* V3DJsonIO::GetByteStream(const json& jsonObj)
	{
		NoOp();

		const auto jsonText = jsonObj.dump();
		const auto result = V3DMemory::NewArray<char>(V3DFILE_INFO, static_cast<unsigned int>(jsonText.length()) + 1);
		strcpy(result, jsonText.c_str());

		return result;
	}

	json V3DJsonIO::GetJsonObject(const char* jsonText)
	{
		NoOp();

		json result;

		if (json::accept(jsonText))
			return json::parse(jsonText);

		nlohmann::ExceptionData::lastException.clear();
		json::parse(jsonText);  // NOLINT(clang-diagnostic-unused-result)

		if (!V3DEnvironment::GetIsUnitTestMode())
			V3DLogger::Get().WriteOutput(V3DLogMessageType::Error, nlohmann::ExceptionData::lastException.c_str());
		
		return result;
	}
	
	void V3DJsonIO::TraversalJsonHierarchy(const json& jsonObj, void* parent, const V3DAction1<const V3DJsonVariant&>& action)
	{
		NoOp();

		for (auto it = jsonObj.begin(); it != jsonObj.end(); ++it)
		{
			V3DJsonVariant variant{};
			
			if (it->is_structured()) //array or object
			{
				if (parent == nullptr || !static_cast<json::const_iterator*>(parent)->value().is_array()) //if the parent is array the child items no have any name
					variant.name = it.key().c_str();

				if (parent != nullptr)
					variant.parentName = static_cast<json::const_iterator*>(parent)->key().c_str();
				
				variant.currentType = it->type() == nlohmann::detail::value_t::array ? V3DJsonVariantTypes::Array : V3DJsonVariantTypes::Object;
				if (variant.currentType == V3DJsonVariantTypes::Array)
				{
					variant.currentType = V3DJsonVariantTypes::Array;
					variant.array = const_cast<json::array_t*>(it.value().get_ptr<const json::array_t*>());
				}

				action.Invoke(variant);

				// ReSharper disable once CppCStyleCast
				TraversalJsonHierarchy(*it, &it, action);
			}
			else
			{
				if (parent == nullptr || !static_cast<json::const_iterator*>(parent)->value().is_array()) //if the parent is array the child items no have any name
					variant.name = it.key().c_str();
				
				if (parent != nullptr)
					variant.parentName = static_cast<json::const_iterator*>(parent)->key().c_str();
				
				switch (it->type())
				{
					//< null value
				case nlohmann::detail::value_t::null:
					variant.currentType = V3DJsonVariantTypes::Null;
					break;

					//< object (unordered set of name/value pairs)
				case nlohmann::detail::value_t::object:
					variant.currentType = V3DJsonVariantTypes::Object;
					break;

					//< array (ordered collection of values)
				case nlohmann::detail::value_t::array:
					variant.currentType = V3DJsonVariantTypes::Array;
					variant.array = const_cast<json::array_t*>(it.value().get_ptr<const json::array_t*>());
					break;

					//< string value
				case nlohmann::detail::value_t::string:
					variant.currentType = V3DJsonVariantTypes::Text;
					variant.text = const_cast<json::string_t*>(it.value().get_ptr<const json::string_t*>());
					break;

					//< boolean value
				case nlohmann::detail::value_t::boolean:
					variant.currentType = V3DJsonVariantTypes::Boolean;
					variant.boolean = const_cast<bool*>(it.value().get_ptr<const json::boolean_t*>());
					break;

					//< number value (signed/unsigned integer integer)
				case nlohmann::detail::value_t::number_integer:
					variant.currentType = V3DJsonVariantTypes::IntNumber;
					variant.intNumber = const_cast<std::int64_t*>(it.value().get_ptr<const json::number_integer_t*>());
					break;

				case nlohmann::detail::value_t::number_unsigned:
					variant.currentType = V3DJsonVariantTypes::UnsignedIntNumber;
					variant.unsignedIntNumber = const_cast<std::uint64_t*>(it.value().get_ptr<const json::number_unsigned_t*>());
					break;

					//< number value (floating-point)
				case nlohmann::detail::value_t::number_float:
					variant.currentType = V3DJsonVariantTypes::DoubleNumber;
					variant.floatNumber = const_cast<double*>(it.value().get_ptr<const json::number_float_t*>());
					break;

					//< binary array (ordered collection of bytes)
				case nlohmann::detail::value_t::binary:  // NOLINT(bugprone-branch-clone)
					break;

					//< discarded by the parser callback function
				case nlohmann::detail::value_t::discarded:
					break;
				}

				action.Invoke(variant);
			}
		}
	}
}
