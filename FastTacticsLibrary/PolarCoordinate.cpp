/*!
* \file PolarCoordinate.cpp
* \date 2018/02/25 1:35
*
* \author Scott
* Contact: user@company.com
*
* \brief
*
* Encapsulates a PolarCoordinate as Degrees and Range
*
* \note
*/
#include "stdafx.h"
#include "PolarCoordinate.h"

PolarCoordinate::PolarCoordinate() : PolarCoordinate(0.0F, 0.0F, FLOAT_PRECISION)
{
}

//************************************
// Method:    PolarCoordinate
// FullName:  PolarCoordinate::PolarCoordinate
// Access:    public 
// Returns:   
// Qualifier:
// Parameter: float degrees
// Parameter: float range
//************************************
PolarCoordinate::PolarCoordinate(float degrees, float range) : PolarCoordinate(degrees, range, FLOAT_PRECISION)
{
}

//************************************
// Method:    PolarCoordinate
// FullName:  PolarCoordinate::PolarCoordinate
// Access:    public 
// Returns:   
// Qualifier:
// Parameter: PolarCoordinate const & obj
//************************************
PolarCoordinate::PolarCoordinate(PolarCoordinate const &obj, int iFloatPrecision) : PolarCoordinate(obj.getDegrees(), obj.getRange(), iFloatPrecision)
{
}

//************************************
// Method:    PolarCoordinate
// FullName:  PolarCoordinate::PolarCoordinate
// Access:    public 
// Returns:   
// Qualifier:
// Parameter: float degrees
// Parameter: float range
//************************************
PolarCoordinate::PolarCoordinate(float degrees, float range, int iFloatPrecision) : ClassShower(), Precision(iFloatPrecision)
{
	_degrees = degrees;
	_range = range;
}



PolarCoordinate::PolarCoordinate(PolarCoordinate const & obj) : PolarCoordinate(obj, FLOAT_PRECISION)
{
}


//************************************
// Method:    getDegrees
// FullName:  PolarCoordinate::getDegrees
// Access:    public 
// Returns:   float
// Qualifier: const
//************************************
float PolarCoordinate::getDegrees() const
{
	return _degrees;
}

//************************************
// Method:    getRange
// FullName:  PolarCoordinate::getRange
// Access:    public 
// Returns:   float
// Qualifier: const
//************************************
float PolarCoordinate::getRange() const
{
	return _range;
}

//************************************
// Method:    setDegrees
// FullName:  PolarCoordinate::setDegrees
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: float const degrees
//************************************
void PolarCoordinate::setDegrees(float const degrees)
{
	_degrees = degrees;
}

//************************************
// Method:    setRange
// FullName:  PolarCoordinate::setRange
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: float const range
//************************************
void PolarCoordinate::setRange(float const range)
{
	_range = range;
}

//************************************
// Method:    operator==
// FullName:  PolarCoordinate::operator==
// Access:    public 
// Returns:   bool
// Qualifier: const
// Parameter: const PolarCoordinate & Ref
//************************************
bool PolarCoordinate::operator==(const PolarCoordinate & Ref) const
{
	return this->_degrees == Ref.getDegrees() && this->_range == Ref.getRange();
}

//************************************
// Method:    operator!=
// FullName:  PolarCoordinate::operator!=
// Access:    public 
// Returns:   bool
// Qualifier: const
// Parameter: const PolarCoordinate & Ref
//************************************
bool PolarCoordinate::operator!=(const PolarCoordinate & Ref) const
{
	return this->_degrees != Ref.getDegrees() || this->_range != Ref.getRange();
}

//************************************
// Method:    operator-=
// FullName:  PolarCoordinate::operator-=
// Access:    public 
// Returns:   PolarCoordinate
// Qualifier: const
// Parameter: const PolarCoordinate & Ref
//************************************
PolarCoordinate PolarCoordinate::operator-=(const PolarCoordinate & Ref) const
{
	return PolarCoordinate(_degrees - Ref.getDegrees(), _range - Ref.getRange());
}

//************************************
// Method:    operator+=
// FullName:  PolarCoordinate::operator+=
// Access:    public 
// Returns:   PolarCoordinate
// Qualifier: const
// Parameter: const PolarCoordinate & Ref
//************************************
PolarCoordinate PolarCoordinate::operator+=(const PolarCoordinate & Ref) const
{
	return PolarCoordinate(_degrees + Ref.getDegrees(), _range + Ref.getRange());
}

//************************************
// Method:    toString
// FullName:  PolarCoordinate::toString
// Access:    virtual public 
// Returns:   std::wstring
// Qualifier:
// Parameter: int rounding_digits
//************************************
std::wstring PolarCoordinate::toString() const
{
	std::wostringstream oss;
	oss << std::fixed << std::showpoint;
	oss << std::setprecision(GetPrecision());
	oss << _degrees;
	oss << L"° at ";
	oss << _range;
	oss << L" units";
	std::wstring buffer = oss.str();
	return buffer;
}

PolarCoordinate::~PolarCoordinate()
{
}

