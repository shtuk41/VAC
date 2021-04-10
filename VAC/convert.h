#pragma once

#include "math_defines.h"

double degToRad(double &deg)
{
	return deg *  PI / 180.0;
}

double radToDeg(double &rad)
{
	return rad * 180.0 / PI;
}