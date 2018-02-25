#pragma once
#include "TwoDCoordinate.h"
#include "PolarCoordinate.h"
#include "globals.h"

#define NORTH_PRIME 0.00F
#define NORTH 360.00F
#define SOUTH 180.00F
#define EAST 90.00F
#define WEST 270.00F

class DllExport CoordinateConverter
{
private:
	static float DegreesToRadians(float);
	static float RadiansToDegrees(float);
public:
	static TwoDCoordinate ConvertFromPolarTo2D(PolarCoordinate, TwoDCoordinate);
	static TwoDCoordinate ConvertFromRelativeToAbsolute(TwoDCoordinate, float, float);
	static TwoDCoordinate ConvertFromAbsoluteToRelative(TwoDCoordinate, float, float);
	static PolarCoordinate ConvertFrom2DToPolar(TwoDCoordinate);
};

