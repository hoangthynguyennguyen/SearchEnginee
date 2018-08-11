#include "menu.h"
#include "buttonSearch.h"

Menu::Menu()
{
	system("color 00");
	console::resizeconsole(1400, 700);
	console::UI();
	console::textcolor(13);


	Button *listbutton;
	listbutton = new Button[2];

	listbutton[0] = Button(Point(40, 25), "Start", 15, 2);
	listbutton[1] = Button(Point(40, 32), "Exit", 15, 2);



	listbutton[0].condition_of_button();// turn on button after drawing button
	int a = 0;
	bool isPressed = false;

	// Process
	while (true)
	{
		if (_kbhit()) {// Nhan biet mot phim bat ki khi nguoi dung nhap vao
			switch (_getch()) { // save phim do lai de xu ly
			case 13: // vertical tab
				isPressed = true;
				break;
			case 9: // TAB
				if (listbutton[a].stateButton())//neu dang bat thi tat
					listbutton[a].condition_of_button();
				if (a == 0)
					a = 1;
				else
					a = 0;
				break;
			}
			if (!listbutton[a].stateButton())
				listbutton[a].condition_of_button();
			if (isPressed)
				break;
		}
	}


	if (a == 0) {
		buttonSearch::buttonSearch();
	}

}
Menu::~Menu() {}
