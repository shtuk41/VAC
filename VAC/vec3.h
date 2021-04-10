#pragma once

#include <math.h>
#include <iostream>

class vec3
{
public:
	vec3() : x(0), y(0), z(0) {}
	vec3(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
	double mag()
	{
		return sqrt(x * x + y * y + z * z);
	}

	friend std::ostream & operator<<(std::ostream& os, const vec3 &v)
	{
		os << "[" << v.x << "," << v.y << "," << v.z << "]";
		return os;
	}

	friend vec3 & operator+(const vec3 &v1, const vec3 &v2)
	{
		vec3 output(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
		return output;
	}

	friend vec3 & operator-(const vec3 &v1, const vec3 &v2)
	{
		vec3 output(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
		return output;
	}

	vec3 unit()
	{
		double magnitude = mag();
		return vec3(x / magnitude, y / magnitude, z / magnitude);
	}

	vec3 operator+=(vec3 &v2)
	{
		vec3 output = *this;

		output.x += v2.x;
		output.y += v2.y;
		output.z += v2.z;
	}

	vec3 operator-=(vec3 &v2)
	{
		vec3 output;

		output.x = x - v2.x;
		output.y = y - v2.y;
		output.z = z - v2.z;
	}

	vec3 neg()
	{
		vec3 output;

		output.x = -x;
		output.y = -y;
		output.z = -z;
	}

	vec3 operator*(double var)
	{
		vec3 output;

		output.x = x * var;
		output.y = y * var;
		output.z = z * var;

		return output;
	}

	double dot(const vec3 &v2)
	{
		return x* v2.x + y * v2.y + z * v2.z;
	}

	/*
		|i	j  k|
		|a1 a2 a3|
		|b1 b2 b3|
	*/
	vec3 cross(const vec3 &v2)
	{
		vec3 u = unit();

		return vec3((y * v2.z - z * v2.y),
			(z * v2.x - x * v2.z),
			(x * v2.y - y * v2.x));
	}

private:
	double x;
	double y;
	double z;
};

class point3
{
public:
	point3(double _x, double _y, double _z) : x(_x), y(_y), z(-z) {}
	point3() : x(0), y(0), z(0) {}

	vec3 operator-(const point3 &a)
	{
		return vec3(a.x - x, a.y - y, a.z - z);
	}

private:
	double x;
	double y;
	double z;
};

class line3
{
public:
	line3(vec3 pos_vector, vec3 dir_vector) : position_vector(pos_vector), direction_vector(dir_vector) {}
	line3(point3 first_point, point3 second_point) : position_vector(first_point - point3()), direction_vector(second_point - first_point) {}
	vec3 getValueAt(double lambda)
	{
		vec3 output = position_vector + direction_vector * lambda;
		return output;
	}

	vec3 getUnitValueAt(double lambda)
	{
		vec3 output = position_vector + direction_vector.unit() * lambda;
	}

	vec3 shortestFromPoint(point3 c)
	{
		vec3 vecC = c - point3();
		vec3 atoc = position_vector - vecC;
		
		double distance = (atoc.cross(direction_vector.unit())).mag();

	}

private:

	vec3 position_vector;
	vec3 direction_vector;

};
