#include "stdafx.h"
#include "ThreeDCoordinate.h"

//************************************
// Method:    ThreeDCoordinate
// FullName:  ThreeDCoordinate::ThreeDCoordinate
// Access:    public 
// Returns:   
// Qualifier:
//************************************
ThreeDCoordinate::ThreeDCoordinate()
{
}

//************************************
// Method:    ThreeDCoordinate
// FullName:  ThreeDCoordinate::ThreeDCoordinate
// Access:    public 
// Returns:   
// Qualifier:
// Parameter: PolarCoordinate position
// Parameter: float altitude
//************************************
ThreeDCoordinate::ThreeDCoordinate(PolarCoordinate position, float const altitude)
{
	setDegrees(position.getDegrees());
	setRange(position.getRange());
	_altitude = altitude;
}

//************************************
// Method:    ThreeDCoordinate
// FullName:  ThreeDCoordinate::ThreeDCoordinate
// Access:    public 
// Returns:   
// Qualifier:
// Parameter: ThreeDCoordinate const & obj
//************************************
ThreeDCoordinate::ThreeDCoordinate(ThreeDCoordinate const & obj)
{
	setDegrees(obj.getDegrees());
	setRange(obj.getRange());
	_altitude = obj.getAltitude();
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
	return (PolarCoordinate)*this;
}

//************************************
// Method:    setPolarCoordinate
// FullName:  ThreeDCoordinate::setPolarCoordinate
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: PolarCoordinate polarCoordinate
//************************************
void ThreeDCoordinate::setPolarCoordinate(PolarCoordinate polarCoordinate)
{
	setDegrees(polarCoordinate.getDegrees());
	setRange(polarCoordinate.getRange());
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
void ThreeDCoordinate::setAltitude(float altitude)
{
	_altitude = altitude;
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
	return getPolarCoordinate() == Ref.getPolarCoordinate();
}

//************************************
// Method:    operator-=
// FullName:  ThreeDCoordinate::operator-=
// Access:    public 
// Returns:   ThreeDCoordinate
// Qualifier: const
// Parameter: const ThreeDCoordinate & Ref
//************************************
ThreeDCoordinate ThreeDCoordinate::operator-=(const ThreeDCoordinate & Ref) const
{
	return ThreeDCoordinate(PolarCoordinate(getDegrees() - Ref.getDegrees(), getRange() - Ref.getRange()), _altitude - Ref.getAltitude());
}

//************************************
// Method:    operator+=
// FullName:  ThreeDCoordinate::operator+=
// Access:    public 
// Returns:   ThreeDCoordinate
// Qualifier: const
// Parameter: const ThreeDCoordinate & Ref
//************************************
ThreeDCoordinate ThreeDCoordinate::operator+=(const ThreeDCoordinate & Ref) const
{
	return ThreeDCoordinate(PolarCoordinate(getDegrees() + Ref.getDegrees(), getRange() + Ref.getRange()), _altitude + Ref.getAltitude());
}

ThreeDCoordinate::~ThreeDCoordinate()
{
}

