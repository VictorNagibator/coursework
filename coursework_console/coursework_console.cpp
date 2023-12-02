#include <iostream>
#include <fstream>
#include <windows.h>
#include "OrderComponents/Order.h"
#include "MenuComponents/Menus/StandartMenuDirector.h"
#include "MenuComponents/Menus/Menu.h"
#include "MenuComponents/Menus/MenuBuilder.h"
#include "MenuComponents/Menus/MenuWithTable.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	MenuBuilder builder = MenuBuilder("Главное меню");
	StandartMenuDirector dir;
	dir.buildMenu(builder);
	Menu* menu = builder.getMenu();
	
	menu->show();

	return 0;
}