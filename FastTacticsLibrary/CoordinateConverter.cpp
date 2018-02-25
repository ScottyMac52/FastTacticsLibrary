#include "stdafx.h"
#include "CoordinateConverter.h"

#define FLOAT_PI (float) roundf(M_PI)

//************************************
// Method:    ConvertFromRelativeToAbsolute
// FullName:  CoordinateConverter::ConvertFromRelativeToAbsolute
// Access:    public static 
// Returns:   TwoDCoordinate
// Qualifier:
// Parameter: TwoDCoordinate source
// Parameter: float sizeX
// Parameter: float sizeY
//************************************
TwoDCoordinate CoordinateConverter::ConvertFromRelativeToAbsolute(TwoDCoordinate source, float sizeX, float sizeY)
{
	return source.getAbsolutePosition(sizeX, sizeY);
}

//************************************
// Method:    ConvertFromAbsoluteToRelative
// FullName:  CoordinateConverter::ConvertFromAbsoluteToRelative
// Access:    public static
// Returns:   TwoDCoordinate
// Qualifier:
// Parameter: TwoDCoordinate source
// Parameter: float sizeX
// Parameter: float sizeY
//************************************
TwoDCoordinate CoordinateConverter::ConvertFromAbsoluteToRelative(TwoDCoordinate source, float sizeX, float sizeY)
{
	return source.getRelativePosition(sizeX, sizeY);
}

//************************************
// Method:    ConvertFromPolarTo2D
// FullName:  CoordinateConverter::ConvertFromPolarTo2D
// Access:    public static
// Returns:   TwoDCoordinate
// Qualifier:
// Parameter: PolarCoordinate source
// Parameter: TwoDCoordinate offSet
//************************************
TwoDCoordinate CoordinateConverter::ConvertFromPolarTo2D(PolarCoordinate source, TwoDCoordinate offSet = TwoDCoordinate(0, 0))
{
	float newX, newY, degrees, range;

	degrees = source.getDegrees();
	range = source.getRange();

	// Subtract the 90 degree offset to account for conversion from polar to compass coordinates
	// when the angle is >= 90
	float theta = NORTH_PRIME;

	// Have to offset Degrees back to normal based on Quadrant
	// Quadrant 1
	if (degrees >= NORTH_PRIME && degrees <= EAST)
	{
		theta = EAST - degrees;
	}
	// Quadrant 2
	else if (degrees > WEST && degrees <= NORTH)
	{
		theta = EAST + (NORTH - degrees);
	}
	// Quadrant 3
	else if (degrees > SOUTH && degrees <= WEST)
	{
		theta = WEST - (degrees - SOUTH);
	}
	// Quadrant 4, y is negative so sin is negative
	else if (degrees > EAST && degrees <= SOUTH)
	{
		theta = WEST + (SOUTH - degrees);
	}

	// Calculate the degrees into Radians 
	float radians = DegreesToRadians(theta);
	// X is radius * Cos(theta in radians)
	newX = range * cos(radians);
	// Y is radius * Sin(theta in radians)
	newY = range * sin(radians);

	// Apply the Offset
	newX = offSet.getX() + newX;
	newY = offSet.getY() + newY;

	return TwoDCoordinate(newX, newY);
}

//************************************
// Method:    ConvertFrom2DToPolar
// FullName:  CoordinateConverter::ConvertFrom2DToPolar
// Access:    public static 
// Returns:   PolarCoordinate
// Qualifier:
// Parameter: TwoDCoordinate source
//************************************
PolarCoordinate CoordinateConverter::ConvertFrom2DToPolar(TwoDCoordinate source)
{
	return PolarCoordinate();
}

#pragma warning( push )
#pragma warning( disable : 4305)
//************************************
// Method:    DegreesToRadians
// FullName:  CoordinateConverter::DegreesToRadians
// Access:    private static 
// Returns:   float
// Qualifier:
// Parameter: float degrees
//************************************
float CoordinateConverter::DegreesToRadians(float degrees)
{
	return degrees * (FLOAT_PI / 180.00F);
}

//************************************
// Method:    RadiansToDegrees
// FullName:  CoordinateConverter::RadiansToDegrees
// Access:    private static 
// Returns:   float
// Qualifier:
// Parameter: float radians
//************************************
float CoordinateConverter::RadiansToDegrees(float radians)
{
	return radians * (180.00F / FLOAT_PI);
}
#pragma warning( pop ) 
