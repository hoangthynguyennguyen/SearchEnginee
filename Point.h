#ifndef POINT_H
#define POINT_H
#pragma once
#include<iostream>
#include<windows.h>
using namespace std;

struct Point{
	int x1, y1;
	Point() : x1(0), y1(0){}
	Point(const int &x, const int&y) : x1(x), y1(y){
		if (x < 0)
		{
			x1 = 0;
		}
		if (y < 0)
		{
			y1 = 0;
		}
	}
};
#endif