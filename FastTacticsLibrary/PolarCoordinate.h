#pragma once
#include "globals.h"

class DllExport PolarCoordinate
{
private:
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

};

