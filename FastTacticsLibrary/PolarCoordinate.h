#pragma once
#include "globals.h"
#include <iostream> 
#include <string> 
#include <sstream> 
#include <iomanip>
#include "ClassShower.h"

class DllExport PolarCoordinate :
	protected ClassShower
{
protected:
	float _degrees;
	float _range;
public:
	PolarCoordinate();
	PolarCoordinate(float, float);
	PolarCoordinate(PolarCoordinate const &obj);
	~PolarCoordinate();
	float getDegrees() const;
	float getRange() const;
	void setDegrees(float const);
	void setRange(float const);
	bool operator == (const PolarCoordinate &Ref) const;
	PolarCoordinate operator -= (const PolarCoordinate &Ref) const;
	PolarCoordinate operator += (const PolarCoordinate &Ref) const;
	std::wstring toString(int rounding_digits) const override;

};

