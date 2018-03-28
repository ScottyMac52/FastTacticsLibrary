#include "stdafx.h"
#include "ThreeDCoordinate.h"

/*
ThreeDCoordinate::ThreeDCoordinate(float const fDegrees, float const fRange, float const fAltitude) : ThreeDCoordinate(fDegrees, fRange, fAltitude, FLOAT_PRECISION)
{
}
*/
//************************************
// Method:    ThreeDCoordinate
// FullName:  ThreeDCoordinate::ThreeDCoordinate
// Access:    public 
// Returns:   
// Qualifier:
// Parameter: PolarCoordinate position
// Parameter: float altitude
//************************************
ThreeDCoordinate::ThreeDCoordinate(float const fDegrees, float const fRange, float const fAltitude, int const iFloatPrecision) : PolarCoordinate(fDegrees, fRange, iFloatPrecision)
{
	_altitude = fAltitude;
	_iFloatingPrecision = iFloatPrecision;
}


//************************************
// Method:    getPolarCoordinate
// FullName:  ThreeDCoordinate::getPolarCoordinate
// Access:    public 
// Returns:   PolarCoordinate
// Qualifier:
//************************************
PolarCoordinate ThreeDCoordinate::getPolarCoordinate() const
{
	return PolarCoordinate(this->getDegrees(), this->getRange(), _iFloatingPrecision);
}

//************************************
// Method:    setPolarCoordinate
// FullName:  ThreeDCoordinate::setPolarCoordinate
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: PolarCoordinate polarCoordinate
//************************************
void ThreeDCoordinate::setPolarCoordinate(PolarCoordinate pcPos)
{
	setDegrees(pcPos.getDegrees());
	setRange(pcPos.getRange());
}

//************************************
// Method:    getAltitude
// FullName:  ThreeDCoordinate::getAltitude
// Access:    public 
// Returns:   float
// Qualifier:
//************************************
float ThreeDCoordinate::getAltitude() const
{
	return _altitude;
}

//************************************
// Method:    setAltitude
// FullName:  ThreeDCoordinate::setAltitude
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: float altitude
//************************************
void ThreeDCoordinate::setAltitude(float const fAltitude)
{
	_altitude = fAltitude;
}

//************************************
// Method:    operator==
// FullName:  ThreeDCoordinate::operator==
// Access:    public 
// Returns:   bool
// Qualifier: const
// Parameter: const ThreeDCoordinate & Ref
//************************************
bool ThreeDCoordinate::operator==(const ThreeDCoordinate & Ref) const
{
	return getPolarCoordinate() == Ref.getPolarCoordinate() && _altitude == Ref.getAltitude();
}

//************************************
// Method:    operator!=
// FullName:  ThreeDCoordinate::operator==
// Access:    public 
// Returns:   bool
// Qualifier: const
// Parameter: const ThreeDCoordinate & Ref
//************************************
bool ThreeDCoordinate::operator!=(const ThreeDCoordinate & Ref) const
{
	return getPolarCoordinate() != Ref.getPolarCoordinate() || _altitude != Ref.getAltitude();
}

//************************************
// Method:    operator-=
// FullName:  ThreeDCoordinate::operator-=
// Access:    public 
// Returns:   ThreeDCoordinate
// Qualifier: const
// Parameter: const ThreeDCoordinate & Ref
//************************************
ThreeDCoordinate& ThreeDCoordinate::operator-=(const ThreeDCoordinate & Ref)
{
	_degrees -= Ref._degrees;
	_range -= Ref._range;
	_altitude -= Ref._altitude;
	return *this;
}

//************************************
// Method:    operator+=
// FullName:  ThreeDCoordinate::operator+=
// Access:    public 
// Returns:   ThreeDCoordinate
// Qualifier: const
// Parameter: const ThreeDCoordinate & Ref
//************************************
ThreeDCoordinate& ThreeDCoordinate::operator+=(const ThreeDCoordinate & Ref)
{
	_degrees += Ref._degrees;
	_range += Ref._range;
	_altitude += Ref._altitude;
	return *this;
}

//************************************
// Method:    toString
// FullName:  ThreeDCoordinate::toString
// Access:    virtual public 
// Returns:   std::wstring
// Qualifier:
// Parameter: int rounding_digits
//************************************
std::wstring ThreeDCoordinate::toString() const 
{
	std::wostringstream oss;
	oss << std::fixed << std::showpoint;
	oss << std::setprecision(GetPrecision());
	oss << getPolarCoordinate().toString();
	oss << L" -> ";
	oss << getAngels();
	std::wstring buffer = oss.str();
	return buffer;
}

//************************************
// Method:    getAngels
// FullName:  ThreeDCoordinate::getAngels
// Access:    public 
// Returns:   std::wstring
// Qualifier:
//************************************
std::wstring ThreeDCoordinate::getAngels() const
{
	std::wostringstream angels_out;
	angels_out << std::fixed;
	angels_out << std::setprecision(0);
	angels_out << L"Angels ";
	angels_out << (int)_altitude / 1000.0F;
	return angels_out.str();
}

ThreeDCoordinate::~ThreeDCoordinate()
{
}

