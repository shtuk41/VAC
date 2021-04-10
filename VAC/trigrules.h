#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdexcept>

/******************************************
	Sine Rule

	lenA / sin(radA) = lenB / sin(radB)

	http://mathematics.laerd.com/maths/trigonometry-sine-and-cosine-rules-intro.php

*******************************************/

double useSinRuleFindLength(double radA, double lenB, double radB)
{
	if (radA > 0.0 && radA < 180.0 &&
		lenB > 0 &&
		radB > 0.0 && radB < M_PI)
	{
		return lenB / sin(radB) * sin(radA);
	}
	else
	{
		throw std::invalid_argument("check useSinRuleFindLength arguments");
	}
}

double useSinRuleFindAngle(double lenA, double lenB, double radB)
{
	if (lenA > 0 &&
		lenB > 0 &&
		radB > 0 & radB < M_PI)
	{
		return asin(lenA / lenB * sin(radB));
	}
	else
	{
		throw std::invalid_argument("check useSinRuleFindAngle arguments");
	}
}


/******************************************
Cosine Rule


http://mathematics.laerd.com/maths/trigonometry-sine-and-cosine-rules-intro.php

lenA * lenA = lenB * lenB + lenC * lenC - 2 * lenB * lenC * cos (radA)

*******************************************/

double useCosRuleFindLength(double lenB, double lenC, double radA)
{
	if (lenB > 0 && lenC > 0 && radA > 0 && radA < M_PI)
	{
		return sqrt(lenB * lenB + lenC * lenC - 2 * lenB * lenC * cos(radA));
	}
	else
	{
		throw std::invalid_argument("check useCosRuleFindLength arguments");
	}
}

double useCosRuleFindAngle(double lenA, double lenB, double lenC)
{
	if (lenB > 0 && lenC > 0 && lenA > 0)
	{
		return acos((lenB * lenB + lenC * lenC - lenA * lenA) / (2.0 * lenB * lenC));
	}
	else
	{
		throw std::invalid_argument("check useCosRuleFindAngle arguments");
	}
}