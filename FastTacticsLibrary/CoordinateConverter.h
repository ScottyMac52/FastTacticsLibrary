#pragma once
#include "TwoDCoordinate.h"
#include "PolarCoordinate.h"
#include "globals.h"

class DllExport CoordinateConverter
{
private:
	static float DegreesToRadians(float);
	static float RadiansToDegrees(float);
public:
	static TwoDCoordinate ConvertFromPolarTo2D(PolarCoordinate, TwoDCoordinate = TwoDCoordinate(0.0F, 0.0F));
	static TwoDCoordinate ConvertFromRelativeToAbsolute(TwoDCoordinate, float, float);
	static TwoDCoordinate ConvertFromAbsoluteToRelative(TwoDCoordinate, float, float);
	static PolarCoordinate ConvertFrom2DToPolar(TwoDCoordinate);
	static TwoDCoordinate CalculatePointFromDegrees(TwoDCoordinate offset, float fDegrees, float fRadius);
};

