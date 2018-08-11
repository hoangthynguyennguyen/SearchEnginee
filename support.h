#ifndef SUPPORT_H
#define SUPPORT_H
#include<iostream>
#pragma once
#include<windows.h>
using namespace std;

class console{
public:
	static void gotoxy(const int &x, const int &y);
	static void textcolor(int  x);
	static void resizeconsole(int width, int height);
	static void UI();

};
#endif