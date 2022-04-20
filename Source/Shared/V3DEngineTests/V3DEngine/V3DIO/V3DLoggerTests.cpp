/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DLoggerTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DCore/V3DString.h"
#include "V3DEngine/V3DIO/V3DLogger.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DIO;

namespace V3D::V3DEngineTests::V3DEngine::V3DIO
{
	void V3DLoggerTests::LoggerTest()
	{
		auto logTriggerText = V3DMemory::New<V3DString>(V3DFILE_INFO);
		auto& logger = V3DLogger::Get();
		logger.SetLogTrigger([&logTriggerText](const V3DString& log) { *logTriggerText += log; });

		logger.WriteOutput(V3DLogMessageType::Error, V3DString("Testing log system 1"));
		logger.WriteOutput(V3DLogMessageType::Info, "Testing log system 2");
		logger.WriteOutput("Testing log system 3");
		V3DTest::AssertOk(logger.GetBuffer()->IsEmpty(), V3DFILE_INFO);
		V3DTest::AssertOk(logger.GetErrorCount() == 1, V3DFILE_INFO);
		V3DTest::AssertOk(logger.GetErrors().ToInt() == 1, V3DFILE_INFO);
		V3DTest::AssertOk(logger.GetWarningCount() == 0, V3DFILE_INFO);
		V3DTest::AssertOk(logger.GetWarnings().ToInt() == 0, V3DFILE_INFO);
		V3DTest::AssertOk(logTriggerText->IsEmpty(), V3DFILE_INFO);

		//logger.SetOutputTypeFlag(V3DLogOutputType::ToOutput, true); //TODO: visualize output
		logger.SetOutputTypeFlag(V3DLogOutputType::ToFile, true);
		logger.WriteOutput(V3DLogMessageType::Error, V3DString("Testing log system 11"));
		logger.WriteOutput(V3DLogMessageType::Warning, "Testing log system 21");
		logger.WriteOutput("Testing log system 31");
		logger.WriteOutput(V3DString("logger.GetErrors(): ") + logger.GetErrors() + " logger.GetWarnings(): " + logger.GetWarnings());
		V3DTest::AssertOk(logger.GetBuffer()->IsEmpty(), V3DFILE_INFO);
		V3DTest::AssertOk(logger.GetErrorCount() == 2, V3DFILE_INFO);
		V3DTest::AssertOk(logger.GetErrors().ToInt() == 2, V3DFILE_INFO);
		V3DTest::AssertOk(logger.GetWarningCount() == 1, V3DFILE_INFO);
		V3DTest::AssertOk(logger.GetWarnings().ToInt() == 1, V3DFILE_INFO);
		V3DTest::AssertOk(logTriggerText->IsEmpty(), V3DFILE_INFO);

		logger.SetOutputTypeFlag(V3DLogOutputType::ToLogTrigger, true);
		logger.WriteOutput(V3DLogMessageType::Error, V3DString("Testing log system 111"));
		logger.WriteOutput(V3DLogMessageType::Warning, "Testing log system 222");
		logger.WriteOutput("Testing log system 333");
		logger.WriteOutput(V3DString("logger.GetErrors(): ") + logger.GetErrors() + " logger.GetWarnings(): " + logger.GetWarnings());
		V3DTest::AssertOk(logger.GetBuffer()->IsEmpty(), V3DFILE_INFO);
		V3DTest::AssertOk(logger.GetErrorCount() == 3, V3DFILE_INFO);
		V3DTest::AssertOk(logger.GetErrors().ToInt() == 3, V3DFILE_INFO);
		V3DTest::AssertOk(logger.GetWarningCount() == 2, V3DFILE_INFO);
		V3DTest::AssertOk(logger.GetWarnings().ToInt() == 2, V3DFILE_INFO);
		V3DTest::AssertOk(logTriggerText->Contains(V3DString("Testing log system 111")), V3DFILE_INFO);
		V3DTest::AssertOk(logTriggerText->Contains(V3DString("Testing log system 222")), V3DFILE_INFO);
		V3DTest::AssertOk(logTriggerText->Contains(V3DString("Testing log system 333")), V3DFILE_INFO);

		logger.SetOutputTypeFlag(V3DLogOutputType::ToBuffer, true);
		logger.WriteOutput(V3DLogMessageType::Error, V3DString("Testing log system 1110"));
		logger.WriteOutput(V3DLogMessageType::Warning, "Testing log system 2220");
		logger.WriteOutput("Testing log system 3330");
		logger.WriteOutput(V3DString("logger.GetErrors(): ") + logger.GetErrors() + " logger.GetWarnings(): " + logger.GetWarnings());
		V3DTest::AssertOk(logger.GetBuffer()->Contains(V3DString("Testing log system 1110")), V3DFILE_INFO);
		V3DTest::AssertOk(logger.GetBuffer()->Contains(V3DString("Testing log system 2220")), V3DFILE_INFO);
		V3DTest::AssertOk(logger.GetBuffer()->Contains(V3DString("Testing log system 3330")), V3DFILE_INFO);
		V3DTest::AssertOk(logger.GetErrorCount() == 4, V3DFILE_INFO);
		V3DTest::AssertOk(logger.GetErrors().ToInt() == 4, V3DFILE_INFO);
		V3DTest::AssertOk(logger.GetWarningCount() == 3, V3DFILE_INFO);
		V3DTest::AssertOk(logger.GetWarnings().ToInt() == 3, V3DFILE_INFO);
		V3DTest::AssertOk(logTriggerText->Contains(V3DString("Testing log system 1110")), V3DFILE_INFO);
		V3DTest::AssertOk(logTriggerText->Contains(V3DString("Testing log system 2220")), V3DFILE_INFO);
		V3DTest::AssertOk(logTriggerText->Contains(V3DString("Testing log system 3330")), V3DFILE_INFO);

		V3DMemory::Delete(logTriggerText);
		logger.SetLogTrigger(nullptr);
		logger.SetOutputTypeFlag(V3DLogOutputType::ToFile, false);
		logger.SetOutputTypeFlag(V3DLogOutputType::ToBuffer, false);
		logger.SetOutputTypeFlag(V3DLogOutputType::ToLogTrigger, false);

		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}

	void V3DLoggerTests::RunAllTests()
	{
		LoggerTest();
	}
}
