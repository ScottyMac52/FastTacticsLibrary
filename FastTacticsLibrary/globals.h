#pragma once
#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision

#define DllExport   __declspec( dllexport )
#define Square(a) (float) (a * a)
#define FLOAT_PI (float) M_PI

#define NORTH_PRIME 0.00F
#define NORTH 360.00F
#define SOUTH 180.00F
#define EAST 90.00F
#define WEST 270.00F

#define IsNegative(x) (bool) (x < 0.00F)
#define IsZero(x) (bool) (x == 0.00F)

enum ContactPersonality { Unknown, Friendly, Enemy };
enum ContactMission { AAM, SAM, CM, Air, Surface, Sub };
