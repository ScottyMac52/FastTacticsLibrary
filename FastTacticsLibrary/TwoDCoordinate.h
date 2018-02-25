#pragma once
#include "globals.h"

class DllExport TwoDCoordinate
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
	TwoDCoordinate getRelativePosition(float, float);
	float getDistance(TwoDCoordinate);
	bool operator == (const TwoDCoordinate &Ref) const;
	TwoDCoordinate operator -= (const TwoDCoordinate &Ref) const;
	TwoDCoordinate operator += (const TwoDCoordinate &Ref) const;
	~TwoDCoordinate();
};