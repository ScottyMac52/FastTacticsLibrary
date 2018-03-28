#include "stdafx.h"
#include "Precision.h"


Precision::Precision(int iFloatingPrecision)
{
	_iFloatingPrecision = iFloatingPrecision;
}

int Precision::GetPrecision() const
{
	return _iFloatingPrecision;
}


Precision::~Precision()
{
}
