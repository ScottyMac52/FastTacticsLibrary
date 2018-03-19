/*!
 * \file TwoDCoordinate.cpp
 * \date 2018/02/25 2:30
 *
 * \author Scott
 * Contact: user@company.com
 *
 * \brief 
 *
 * TODO: long description
 *
 * \note
*/
#include "stdafx.h"
#include "globals.h"
#include "TwoDCoordinate.h"


//************************************
// Method:    TwoDCoordinate
// FullName:  TwoDCoordinate::TwoDCoordinate
// Access:    public 
// Returns:   
// Qualifier:
//************************************
TwoDCoordinate::TwoDCoordinate()
{
}

//************************************
// Method:    TwoDCoordinate
// FullName:  TwoDCoordinate::TwoDCoordinate
// Access:    public 
// Returns:   
// Qualifier:
// Parameter: float x
// Parameter: float y
//************************************
TwoDCoordinate::TwoDCoordinate(float x, float y)
{
	_x = x;
	_y = y;
}

//************************************
// Method:    TwoDCoordinate
// FullName:  TwoDCoordinate::TwoDCoordinate
// Access:    public 
// Returns:   
// Qualifier:
// Parameter: const TwoDCoordinate & obj
//************************************
TwoDCoordinate::TwoDCoordinate(const TwoDCoordinate & obj)
{
	_x = obj.getX();
	_y = obj.getY();
}

//************************************
// Method:    setX
// FullName:  TwoDCoordinate::setX
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: float x
//************************************
void TwoDCoordinate::setX(float x)
{
	_x = x;
}

//************************************
// Method:    setY
// FullName:  TwoDCoordinate::setY
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: float y
//************************************
void TwoDCoordinate::setY(float y)
{
	_y = y;
}

//************************************
// Method:    getX
// FullName:  TwoDCoordinate::getX
// Access:    public 
// Returns:   float
// Qualifier:
//************************************
float TwoDCoordinate::getX() const
{
	return _x;
}

//************************************
// Method:    getY
// FullName:  TwoDCoordinate::getY
// Access:    public 
// Returns:   float
// Qualifier:
//************************************
float TwoDCoordinate::getY() const
{
	return _y;
}

//************************************
// Method:    getAbsolutePosition
// FullName:  TwoDCoordinate::getAbsolutePosition
// Access:    public 
// Returns:   TwoDCoordinate
// Qualifier:
// Parameter: float sizeX
// Parameter: float sizeY
//************************************
TwoDCoordinate TwoDCoordinate::getAbsolutePosition(float sizeX, float sizeY)
{
	float newX, newY;
	float midX = roundf(sizeX / 2.00F);
	float midY = roundf(sizeY / 2.00F);

	if (_y <= 0)
	{
		newY = midY + abs(_y);
	}
	else
	{
		newY = midY - _y;
	}
	newX = midX + _x;
	return TwoDCoordinate(newX, newY);
}

//************************************
// Method:    getAbsolutePosition
// FullName:  TwoDCoordinate::getAbsolutePosition
// Access:    public 
// Returns:   TwoDCoordinate
// Qualifier:
// Parameter: TwoDCoordinate * size
//************************************
TwoDCoordinate TwoDCoordinate::getAbsolutePosition(TwoDCoordinate *size)
{
	return getAbsolutePosition(size->getX(), size->getY());
}

//************************************
// Method:    getRelativePosition
// FullName:  TwoDCoordinate::getRelativePosition
// Access:    public 
// Returns:   TwoDCoordinate
// Qualifier:
// Parameter: float sizeX
// Parameter: float sizeY
//************************************
TwoDCoordinate TwoDCoordinate::getRelativePosition(float sizeX, float sizeY)
{
	float newX, newY;
	float midX = roundf(sizeX / 2.00F);
	float midY = roundf(sizeY / 2.00F);

	if (_x >= midX)
	{
		newX = _x - midX;
	}
	else
	{
		newX = -1 * (midX - _x);
	}
	newY = midY - _y;
	return TwoDCoordinate(newX, newY);
}

//************************************
// Method:    getRelativePosition
// FullName:  TwoDCoordinate::getRelativePosition
// Access:    public 
// Returns:   TwoDCoordinate
// Qualifier:
// Parameter: TwoDCoordinate * size
//************************************
TwoDCoordinate TwoDCoordinate::getRelativePosition(TwoDCoordinate *size)
{
	return getRelativePosition(size->getX(), size->getY());
}

//************************************
// Method:    getDistance
// FullName:  TwoDCoordinate::getDistance
// Access:    public 
// Returns:   float
// Qualifier:
// Parameter: TwoDCoordinate dest
//************************************
float TwoDCoordinate::getDistance(TwoDCoordinate dest)
{
	float a = (_x - dest.getX());
	float b = (_y - dest.getY());
	return hypotf(a, b);
}

//************************************
// Method:    operator==
// FullName:  TwoDCoordinate::operator==
// Access:    public 
// Returns:   bool
// Qualifier:
// Parameter: TwoDCoordinate & Ref
//************************************
bool TwoDCoordinate::operator==(const TwoDCoordinate &Ref) const
{
	return this->_x == Ref.getX() && this->_y == Ref.getY();
}

//************************************
// Method:    operator!=
// FullName:  TwoDCoordinate::operator!=
// Access:    public 
// Returns:   bool
// Qualifier: const
// Parameter: const TwoDCoordinate & Ref
//************************************
bool TwoDCoordinate::operator!=(const TwoDCoordinate &Ref) const
{
	return this->_x != Ref.getX() || this->_y != Ref.getY();
}


//************************************
// Method:    operator-=
// FullName:  TwoDCoordinate::operator-=
// Access:    public 
// Returns:   TwoDCoordinate
// Qualifier: const
// Parameter: const TwoDCoordinate & Ref
//************************************
TwoDCoordinate& TwoDCoordinate::operator-=(const TwoDCoordinate & Ref)
{
	this->_x -= Ref.getX();
	this->_y -= Ref.getY();
	return *this;
}

//************************************
// Method:    operator+=
// FullName:  TwoDCoordinate::operator+=
// Access:    public 
// Returns:   TwoDCoordinate
// Qualifier: const
// Parameter: const TwoDCoordinate & Ref
//************************************
TwoDCoordinate& TwoDCoordinate::operator+=(const TwoDCoordinate & Ref) 
{
	this->_x += Ref.getX();
	this->_y += Ref.getY();
	return *this;
}

std::wstring TwoDCoordinate::toString(int rounding_digits) const
{
	std::wostringstream oss;
	oss << std::fixed << std::showpoint;
	oss << std::setprecision(rounding_digits);
	oss << _x;
	oss << L", ";
	oss << _y;
	std::wstring buffer = oss.str();
	return buffer;
}

TwoDCoordinate::~TwoDCoordinate()
{
}
