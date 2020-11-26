/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DSocketAddressTest.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DNetwork/V3DNet.h"
#include "V3DEngine/V3DNetwork/V3DSocketAddress.h"
#include "V3DEngine/V3DNetwork/V3DIpV4Address.h"
//#include "V3DEngine/V3DIO/V3DLogger.h"

using namespace V3D::V3DEngine::V3DNetwork;
using namespace V3D::V3DEngine::V3DCore;
//using namespace V3D::V3DEngine::V3DIO;

namespace V3D::V3DEngineTests::V3DEngine::V3DNetwork
{
	void V3DSocketAddressTest::CreateAddressTest()
	{
		const V3DSocketAddress Addr1(1234);
		V3DTest::AssertOk(Addr1.GetIp() == V3DString("0.0.0.0"), V3DFILE_INFO);
		V3DTest::AssertOk(Addr1.GetPort() == V3DString("1234"), V3DFILE_INFO);
		V3DTest::AssertOk(Addr1.ToString() == V3DString("0.0.0.0:1234"), V3DFILE_INFO);

		const V3DSocketAddress Addr2(23000, "196.168.12.2");
		V3DTest::AssertOk(Addr2.GetIp() == V3DString("196.168.12.2"), V3DFILE_INFO);
		V3DTest::AssertOk(Addr2.GetPort() == V3DString("23000"), V3DFILE_INFO);
		V3DTest::AssertOk(Addr2.ToString() == V3DString("196.168.12.2:23000"), V3DFILE_INFO);

		const V3DSocketAddress Addr3(23000, V3DIpV4Address(196, 168, 12, 2));
		V3DTest::AssertOk(Addr3.GetIp() == V3DString("196.168.12.2"), V3DFILE_INFO);
		V3DTest::AssertOk(Addr3.GetPort() == V3DString("23000"), V3DFILE_INFO);
		V3DTest::AssertOk(Addr3.ToString() == V3DString("196.168.12.2:23000"), V3DFILE_INFO);
	}

	void V3DSocketAddressTest::GetHostIpTest()
	{
		V3DNet::Init();
		V3DTest::AssertOk(V3DSocketAddress::GetPublicIpFromHostName("relay4.slayradio.org") == V3DString("89.45.232.7"), V3DFILE_INFO);

		const auto LocalIp = V3DSocketAddress::GetLocalIp();
		V3DTest::AssertOk(LocalIp != V3DString(""), V3DFILE_INFO);
		V3DTest::AssertOk(LocalIp != V3DString("127.0.0.1"), V3DFILE_INFO);
		V3DNet::Cleanup();

		/*V3DLogger::Get().SetOutputTypeFlag(V3DLogOutputType::ToOutput, true);
		V3DLogger::Get().WriteOutput(LocalIp);
		V3DLogger::Get().SetOutputTypeFlag(V3DLogOutputType::ToOutput, false);*/
	}
	
	void V3DSocketAddressTest::RunAllTests()
	{	
		CreateAddressTest();
		GetHostIpTest();
	}
}
