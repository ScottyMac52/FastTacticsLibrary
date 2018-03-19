#pragma once
#include "PolarCoordinate.h"
#include "globals.h"

class DllExport ThreeDCoordinate :
	public PolarCoordinate
{
public:
	ThreeDCoordinate();
	ThreeDCoordinate(PolarCoordinate const pcPos, float const fAltitude);
	ThreeDCoordinate(ThreeDCoordinate const &obj);
	~ThreeDCoordinate();
	PolarCoordinate getPolarCoordinate() const;
	void setPolarCoordinate(PolarCoordinate pcPos);
	float getAltitude() const;
	void setAltitude(float const fAltitude);
	bool operator == (const ThreeDCoordinate &Ref) const;
	bool operator != (const ThreeDCoordinate &Ref) const;
	ThreeDCoordinate& operator -= (const ThreeDCoordinate &Ref);
	ThreeDCoordinate& operator += (const ThreeDCoordinate &Ref);
	virtual std::wstring toString(int const iRoundDigits) const override;
	std::wstring getAngels() const;
protected:
	float _altitude;
};

