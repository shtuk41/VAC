// VAC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "vec3.h"


int main()
{
	vec3 b = vec3(1, 3, 0);
	vec3 a = vec3(1, 1, 0);

	double num = b.dot(a.unit());


	
	std::cout << a.unit() * num << std::endl;

	system("pause");


    return 0;
}

