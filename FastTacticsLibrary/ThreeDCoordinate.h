#pragma once
#include "PolarCoordinate.h"
#include "globals.h"

class DllExport ThreeDCoordinate :
	public PolarCoordinate
{
public:
	/*
	ThreeDCoordinate();
	ThreeDCoordinate(float const fDegrees, float const fRange, float const fAltitude);
	*/
	ThreeDCoordinate(float const fDegrees, float const fRange, float const fAltitude, int const iFloatPrecision);
	~ThreeDCoordinate();
	PolarCoordinate getPolarCoordinate() const;
	void setPolarCoordinate(PolarCoordinate pcPos);
	float getAltitude() const;
	void setAltitude(float const fAltitude);
	bool operator == (const ThreeDCoordinate &Ref) const;
	bool operator != (const ThreeDCoordinate &Ref) const;
	ThreeDCoordinate& operator -= (const ThreeDCoordinate &Ref);
	ThreeDCoordinate& operator += (const ThreeDCoordinate &Ref);
	virtual std::wstring toString() const override;
	std::wstring getAngels() const;
protected:
	float _altitude;
};

