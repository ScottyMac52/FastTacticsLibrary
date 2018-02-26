#pragma once
#include "PolarCoordinate.h"
#include "globals.h"

class DllExport ThreeDCoordinate :
	protected PolarCoordinate
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
	ThreeDCoordinate& operator -= (const ThreeDCoordinate &Ref);
	ThreeDCoordinate& operator += (const ThreeDCoordinate &Ref);
	virtual std::wstring toString(int rounding_digits) const override;
	std::wstring getAngels() const;
private:
	float _altitude;
};

