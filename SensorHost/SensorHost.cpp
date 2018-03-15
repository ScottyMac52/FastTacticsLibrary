// SensorHost.cpp : Implementation of WinMain


#include "stdafx.h"
#include "resource.h"
#include "SensorHost_i.h"


using namespace ATL;


class CSensorHostModule : public ATL::CAtlExeModuleT< CSensorHostModule >
{
public :
	DECLARE_LIBID(LIBID_SensorHostLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_SENSORHOST, "{ef0f7f18-971d-4f1c-8f45-d033c1d2880b}")
};

CSensorHostModule _AtlModule;



//
extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/,
								LPTSTR /*lpCmdLine*/, int nShowCmd)
{
	return _AtlModule.WinMain(nShowCmd);
}

