#ifndef BUTTON_H
#define BUTTON_H
#include<iostream>
#pragma once
#include<string>
#include<windows.h>
#include<conio.h>
#include "Point.h"
#include "support.h"
using namespace std;

class Button
{
public:
	Button() = default;
	Button(const Point &left, const string &text, const int &length, const int &height );
	void condition_of_button();
	bool stateButton();
	
private:

	Point left1;
	string text1;
	int length1, height1;
	bool state1;


	void createButton(const Point &positionFirst, const int &length, const int &height, const string &text= "" );
	void removeButton(const Point &positionFirst, const int &length, const int &height);
	void lightButton();
	void darkButton();
	

};
#endif
