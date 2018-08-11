#include "support.h"

void console::gotoxy(const int &x, const int &y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x, y };
	SetConsoleCursorPosition(hStdout, position);

}

void console::textcolor(int x)
{
	HANDLE color;
	color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, x);
}

void console::resizeconsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void console::UI()
{


	textcolor(13);
	gotoxy(10, 1);
	cout << "##      ## ######## ##        ######   #######  ##     ## ######## " << endl;
	textcolor(13);
	gotoxy(10, 2);
	cout << "##  ##  ## ##       ##       ##    ## ##     ## ###   ### ##       " << endl;
	textcolor(13);
	gotoxy(10, 3);
	cout << "##  ##  ## ##       ##       ##       ##     ## #### #### ##       " << endl;
	textcolor(13);
	gotoxy(10, 4);
	cout << "##  ##  ## ######   ##       ##       ##     ## ## ### ## ######   " << endl;
	textcolor(13);
	gotoxy(10, 5);
	cout << "##  ##  ## ##       ##       ##       ##     ## ##     ## ##       " << endl;
	textcolor(13);
	gotoxy(10, 6);
	cout << "##  ##  ## ##       ##       ##    ## ##     ## ##     ## ##       " << endl;
	textcolor(13);
	gotoxy(10, 7);
	cout << " ###  ###  ######## ########  ######   #######  ##     ## ######## " << endl;

	gotoxy(12, 10);
	textcolor(13);
	cout << "#######   ######    #######  ##  ## ######    ####   ##  ##   " << endl;
	gotoxy(12, 11);
	textcolor(13);
	cout << "##        ##  ##   ##     ## ##  ## ##  ##  ##  ##   ##  ##  " << endl;
	gotoxy(12, 12);
	textcolor(13);
	cout << "##   #### ######   ##     ## ##  ## ######      ##   ######  " << endl;
	gotoxy(12, 13);
	textcolor(13);
	cout << "###### ## ##   ##   #######  ###### ##       ######      ##  " << endl;
	
}






		            ;