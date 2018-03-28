#pragma once
#include "globals.h"
#include "ClassShower.h"
#include "Precision.h"

class DllExport TwoDCoordinate :
	protected ClassShower, Precision
{
private:
	float _x;
	float _y;
public:
	TwoDCoordinate();
	TwoDCoordinate(float, float);
	TwoDCoordinate(float x, float y, int iFloatPrecision);
	TwoDCoordinate(const TwoDCoordinate & obj, int iFloatPrecision);
	void setX(float);
	void setY(float);
	float getX() const;
	float getY() const;
	TwoDCoordinate getAbsolutePosition(float, float);
	TwoDCoordinate getAbsolutePosition(TwoDCoordinate *);
	TwoDCoordinate getRelativePosition(float, float);
	TwoDCoordinate getRelativePosition(TwoDCoordinate *);
	float getDistance(TwoDCoordinate);
	bool operator == (const TwoDCoordinate &Ref) const;
	bool operator != (const TwoDCoordinate &Ref) const;
	TwoDCoordinate& operator-=(const TwoDCoordinate &Ref);
	TwoDCoordinate& operator+=(const TwoDCoordinate & Ref);
	virtual std::wstring toString() const override;
	~TwoDCoordinate();
};