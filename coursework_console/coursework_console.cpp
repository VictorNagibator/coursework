#include <iostream>
#include <windows.h>
#include "OrderComponents/Order.h"
#include "Menu/Menu.h"
#include "Menu/ExitItem.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Menu menu = Menu("Главное меню");
	menu.addButton(new Button("Закройся нахуй", new ExitItem()));
	menu.show();

	return 0;
}