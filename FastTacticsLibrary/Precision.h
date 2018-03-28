#pragma once
#include "globals.h"

class DllExport	 Precision
{
public:
	Precision(int iFloatingPrecision);
	int GetPrecision() const;
	~Precision();
protected:
	int _iFloatingPrecision = FLOAT_PRECISION;
};

