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
	static TwoDCoordinate ConvertFromRelativeToAbsolute(TwoDCoordinate source, float sizeX, float sizeY);
	static TwoDCoordinate ConvertFromAbsoluteToRelative(TwoDCoordinate source, float sizeX, float sizeY);
	static TwoDCoordinate ConvertFromPolarTo2D(float fDegrees, float fRange, int iFloatPrecision, TwoDCoordinate offSet);
	/*
	static TwoDCoordinate ConvertFromPolarTo2D(float fDegrees, float fRange, int iFloatPrecision);
	static TwoDCoordinate ConvertFromPolarTo2D(float fDegrees, float fRange, int iFloatPrecision, TwoDCoordinate offSet);
	*/
	static TwoDCoordinate ConvertFromPolarTo2D(PolarCoordinate, TwoDCoordinate);
	static PolarCoordinate ConvertFrom2DToPolar(TwoDCoordinate source);
	static TwoDCoordinate CalculatePointFromDegrees(TwoDCoordinate offset, float fDegrees, float fRadius);
};

