#include "button.h"

void Button::createButton(const Point &positionFirst, const int &length, const int &height, const string&text){
	console::gotoxy(positionFirst.x1 - height, positionFirst.y1 - height);

	cout << char(218);

	for (int i = 0; i < length; ++i)
		cout << char(196);
	cout << char(191);

	for (int i = -height + 1; i <= height - 1; ++i) {
		console::gotoxy(positionFirst.x1 - height, positionFirst.y1 + i);
		cout << char(179);
	}

     console::gotoxy(positionFirst.x1 - height, positionFirst.y1+ height);
	cout << char(192);

	for (int i = 0; i < length; ++i)
		cout << char(196);
	cout << char(217);

	for (int i = -height + 1; i <= height - 1; ++i) {
		console::gotoxy(positionFirst.x1+ length +1 - height, positionFirst.y1 + i);
		cout << char(179);
	}

	int text_center = (length - text.length()) / 2;
	console::gotoxy(positionFirst.x1 + text_center, positionFirst.y1);
	cout << text;
}

void Button::removeButton(const Point &positionFirst, const int&length, const int &height)
{
	console::gotoxy(positionFirst.x1 - height, positionFirst.y1 - height);
	cout << " ";

	for (int i = 0; i < length; i++)
		cout << " ";
	cout << " ";

	for (int i = -height + 1; i <= height - 1; i++)
	{
		console::gotoxy(positionFirst.x1 - height, positionFirst.y1 + i);
		cout << " ";
	}

	console::gotoxy(positionFirst.x1 - height, positionFirst.y1 + height);
	cout << " ";

	for (int i = 0; i < length; i++)
		cout << " ";
	cout << " ";

	for (int i = -height + 1; i <= height - 1; i++)
	{
		console::gotoxy(positionFirst.x1 + length + 1 - height, positionFirst.y1 + i);
		cout << " ";
	}
}

Button::Button(const Point &left, const string &text, const int &length, const int &height)
	{
		left1 = left;
		text1 = text;
		length1 = length;
		height1 = height;
		state1 = false;
		
		if (length > 0)
			length1 = length;
		else
			length1 = 4;

		if (height > 0)
			height1 = height;
		else
			height1 = 3;

		createButton(left1, length1, height1, text1);

	}

void Button::lightButton()
{
	createButton(left1, length1 + 2 , height1 +1 );

}
void Button::darkButton()
{
	removeButton(left1, length1 +2, height1 +1);
}
void Button::condition_of_button()
{
	if (state1)
	{
		darkButton();
		state1 = false;
	}

	else
	{
		lightButton();
		state1 = true;
	}

}
bool Button::stateButton()
{
	return state1;
}
