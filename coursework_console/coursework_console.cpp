#include <iostream>
#include <windows.h>
#include "OrderComponents/Order.h"
#include "Menu/StandartMenuDirector.h"
#include "Menu/Menu.h"
#include "Menu/MenuBuilder.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	MenuBuilder builder = MenuBuilder("Главное меню");
	StandartMenuDirector dir;
	dir.buildMenu(builder);
	Menu menu = builder.getMenu();
	
	menu.show();

	return 0;
}