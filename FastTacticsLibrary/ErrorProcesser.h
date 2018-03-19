#ifndef __wtypes_h__
#include <wtypes.h>
#endif

#ifndef __WINDEF_
#include <windef.h>
#endif

#ifndef _WINUSER_
#include <winuser.h>
#endif

#ifndef __RPC_H__
#include <rpc.h>
#endif

#pragma once
#include "globals.h"

class DllExport ErrorProcesser
{
public:
	ErrorProcesser();
	static std::wstring GetLastErrorAsString(DWORD lastError);
	~ErrorProcesser();
};

