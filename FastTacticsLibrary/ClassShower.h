#pragma once
#include <iostream> 
#include <string> 
#include <sstream> 
#include <iomanip>
#include "globals.h"

class DllExport ClassShower
{
public:
	ClassShower();
	virtual std::wstring toString(int rounding_digits) const;
	~ClassShower();
};

