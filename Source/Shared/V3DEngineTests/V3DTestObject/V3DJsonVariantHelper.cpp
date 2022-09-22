#include "V3DJsonVariantHelper.h"
#include "V3DEngine/V3DCore/V3DString.h"
#include "V3DEngine/V3DIO/V3DJsonVariant.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DIO;

namespace V3D::V3DEngineTests::V3DTestObject
{
	V3DString V3DJsonVariantHelper::ToStringType(const V3DJsonVariant& variant)
	{
		switch (variant.currentType)
		{
			case V3DJsonVariantTypes::Null: return V3DString("Null");
			case V3DJsonVariantTypes::Boolean: return V3DString("Bool");
			case V3DJsonVariantTypes::IntNumber: return V3DString("Int");
			case V3DJsonVariantTypes::UnsignedIntNumber: return V3DString("UInt");
			case V3DJsonVariantTypes::DoubleNumber: return V3DString("Double");
			case V3DJsonVariantTypes::Text: return V3DString("Text");
			case V3DJsonVariantTypes::Object: return V3DString("Object");
			case V3DJsonVariantTypes::Array: return V3DString("Array");
		}

		return V3DString("\t");
	}

	V3DString V3DJsonVariantHelper::ToStringValue(const V3DJsonVariant& variant)
	{
		switch (variant.currentType)
		{
			case V3DJsonVariantTypes::Null: return V3DString("null");
			case V3DJsonVariantTypes::Boolean: return *variant.boolean ? V3DString("true") : V3DString("false");
			case V3DJsonVariantTypes::IntNumber: return V3DString(static_cast<int>(*variant.intNumber));
			case V3DJsonVariantTypes::UnsignedIntNumber: return V3DString(static_cast<int>(*variant.unsignedIntNumber));
			case V3DJsonVariantTypes::DoubleNumber: return V3DString(static_cast<float>(*variant.floatNumber));
			case V3DJsonVariantTypes::Text: return V3DString(variant.text->c_str());

			case V3DJsonVariantTypes::Object:
			case V3DJsonVariantTypes::Array:
				return V3DString("#");
		}

		return V3DString("\t");
	}
}
