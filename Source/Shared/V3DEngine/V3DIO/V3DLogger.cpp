/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DLogger.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngine/V3DCore/V3DDateTime.h"

using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngine::V3DIO
{
	V3DLogger::V3DLogger()
	{
		buffer = V3DMemory::NewExplicit<V3DString>(true);

		for (bool& outputType : outputTypes)
			outputType = false;
	}

	V3DLogger::~V3DLogger()
	{
		V3DMemory::Delete(buffer);
	}

	V3DLogger& V3DLogger::Get()
	{
		static V3DLogger instance;

		return instance;
	}
	
	void V3DLogger::SetOutputTypeFlag(V3DLogOutputType outputType, bool isEnable)
	{
		outputTypes[static_cast<unsigned int>(outputType)] = isEnable;
	}
	
	void V3DLogger::SetLogTrigger(const std::function<void(const V3DCore::V3DString& log)>& otherLogTrigger)
	{
		logTrigger = otherLogTrigger;
	}

	V3DString const* V3DLogger::GetBuffer() const
	{
		return buffer;
	}

	V3DString V3DLogger::GetWarnings() const
	{
		return V3DString(warnings);
	}

	V3DString V3DLogger::GetErrors() const
	{
		return V3DString(errors);
	}

	int V3DLogger::GetWarningCount() const
	{
		return warnings;
	}

	int V3DLogger::GetErrorCount() const
	{
		return errors;
	}

	void V3DLogger::WriteOutput(const V3DString& log) const
	{
		WriteOutput(log.ToChar());
	}

	void V3DLogger::WriteOutput(V3DLogMessageType messageType, const V3DCore::V3DString& log)
	{
		WriteOutput(messageType, log.ToChar());
	}

	void V3DLogger::WriteOutput(V3DLogMessageType messageType, const char* log)
	{
		V3DString text;

		switch (messageType)
		{
			case V3DLogMessageType::Info: text += V3DString(InfoTag) + " "; break;

			case V3DLogMessageType::Warning:
				text += V3DString(WarningTag) + " ";
				warnings++;
				break;

			case V3DLogMessageType::Error:
				text += V3DString(ErrorTag) + " ";
				errors++;
				break;
		}

		text += log;

		WriteOutput(text);
	}

	void V3DLogger::WriteOutput(const char* log) const
	{
		const V3DString Text = V3DDateTime::GetTimeStamp() + log;

		if (outputTypes[static_cast<unsigned int>(V3DLogOutputType::ToOutput)])
		{
			WriteLineToOutput(Text.ToChar());
		}

		if (outputTypes[static_cast<unsigned int>(V3DLogOutputType::ToFile)])
		{
			WriteLineToFile(Text.ToChar());
		}

		if (outputTypes[static_cast<unsigned int>(V3DLogOutputType::ToLogTrigger)] && logTrigger != nullptr)
		{
			logTrigger(Text);
		}

		if (outputTypes[static_cast<unsigned int>(V3DLogOutputType::ToBuffer)])
		{
			if (buffer != nullptr)
				*buffer += Text + '\n';
		}
	}
}
