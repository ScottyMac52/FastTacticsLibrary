#include "stdafx.h"
#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision
#include "CoordinateConverter.h"
#include "globals.h"

using namespace std;

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
TwoDCoordinate CoordinateConverter::ConvertFromPolarTo2D(PolarCoordinate source, TwoDCoordinate offSet)
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

	return TwoDCoordinate(newX, newY) += offSet;
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
	float sine = 0.00, cos = 0.00, tan = 0.00;
	// Calculate the z
	float z = sqrt(Square(source.getX()) + Square(source.getY()));
	float angleTheta = NORTH;
	// Get the sine, cos and tan
	sine = source.getY() / z;
	cos = source.getX() / z;
	tan = source.getY() / source.getX();

	if (isnan(sine) && isnan(cos) && isnan(tan))
	{
		angleTheta = NORTH_PRIME;
	}
	else if (IsZero(sine) && cos == -1.00 && IsZero(tan))
	{
		angleTheta = WEST;
	}
	else if (IsZero(sine) && cos == 1.00 && IsZero(tan))
	{
		angleTheta = EAST;
	}
	else if (!IsNegative(sine) && !IsNegative(cos) && !IsNegative(tan))
	{
		// Quadrant One 
		angleTheta = EAST - RadiansToDegrees(atan(source.getY() / source.getX()));
	}
	else if (!IsNegative(sine) && IsNegative(cos) && IsNegative(tan))
	{
		// Quadrant Two 
		angleTheta = WEST + RadiansToDegrees(asin(source.getY() / z));
	}
	else if (IsNegative(sine) && IsNegative(cos) && !IsNegative(tan))
	{
		// Quadrant Three
		angleTheta = WEST - RadiansToDegrees(atan(source.getY() / source.getX()));
	}
	else if (IsNegative(sine) && !IsNegative(cos) && IsNegative(tan))
	{
		// Quadrant Four
		angleTheta = EAST + abs(RadiansToDegrees(atan(source.getY() / source.getX())));
	}
	else if (isnan(tan) && !isnan(sine) && !isnan(cos))
	{
		if (sine == 1.00F && IsZero(cos))
		{
			angleTheta = NORTH;
		}
		else if (sine == -1.00F && IsZero(cos))
		{
			angleTheta = SOUTH;
		}
	}

	return PolarCoordinate(angleTheta, z);
}

//************************************
// Method:    CalculatePointFromDegrees
// FullName:  CoordinateConverter::CalculatePointFromDegrees
// Access:    public static 
// Returns:   TwoDCoordinate
// Qualifier:
// Parameter: TwoDCoordinate offset
// Parameter: float fDegrees
// Parameter: float fRadius
//************************************
TwoDCoordinate CoordinateConverter::CalculatePointFromDegrees(TwoDCoordinate offset, float fDegrees, float fRadius)
{
	float fTheta = NORTH_PRIME;
	
	if(fDegrees >= NORTH_PRIME && fDegrees <= EAST)
	{
		fTheta = EAST - fDegrees;
	}
	else if (fDegrees > WEST && fDegrees <= NORTH)
	{
		fTheta = EAST + (NORTH - fDegrees);
	}
	// Quadrant 3
	else if (fDegrees > SOUTH && fDegrees <= WEST)
	{
		fTheta = WEST - (fDegrees - SOUTH);
	}
	// Quadrant 4, y is negative so sin is negative
	else if (fDegrees > EAST && fDegrees <= SOUTH)
	{
		fTheta = WEST + (SOUTH - fDegrees);
	}

	float fRadians = DegreesToRadians(fTheta);
	// X is radius * Cos(theta in radians)
	float fXvalue = fRadius * cos(fRadians);
	// Y is radius * Sin(theta in radians)
	float fYvalue = fRadius * sin(fRadians);

	// Account for specified offset
	float x = offset.getX() + fXvalue;
	float y = offset.getY() + fYvalue;

	return TwoDCoordinate(x,y);
}


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

