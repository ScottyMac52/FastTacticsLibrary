#pragma once
#include "globals.h"
#include "ClassShower.h"

class DllExport TwoDCoordinate :
	protected ClassShower
{
private:
	float _x;
	float _y;
public:
	TwoDCoordinate();
	TwoDCoordinate(float, float);
	TwoDCoordinate(const TwoDCoordinate &obj);
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
	virtual std::wstring toString(int rounding_digits) const override;
	~TwoDCoordinate();
};