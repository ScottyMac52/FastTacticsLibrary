#pragma once
#include "PolarCoordinate.h"
#include "globals.h"

class DllExport ThreeDCoordinate :
	public PolarCoordinate
{
public:
	ThreeDCoordinate();
	ThreeDCoordinate(PolarCoordinate, float const);
	ThreeDCoordinate(ThreeDCoordinate const &obj);
	~ThreeDCoordinate();
	PolarCoordinate getPolarCoordinate() const;
	void setPolarCoordinate(PolarCoordinate);
	float getAltitude() const;
	void setAltitude(float);
	bool operator == (const ThreeDCoordinate &Ref) const;
	ThreeDCoordinate operator -= (const ThreeDCoordinate &Ref) const;
	ThreeDCoordinate operator += (const ThreeDCoordinate &Ref) const;

private:
	float _altitude;
};

