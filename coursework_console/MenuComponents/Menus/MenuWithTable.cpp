#include "MenuWithTable.h"
#include "../FileInfo.h"
#include "../OrdersData.h"

MenuWithTable::MenuWithTable(const std::string& text) : Menu(text)
{
	
};

void MenuWithTable::show()
{
	system("cls");
	if (FileInfo::isPathSet()) {
		Table table = Table();
		table.shortShow(OrdersData::getData());
		std::cout << std::endl;
		Menu::show();
	}	
	else {
		std::cout << "Путь к файлу не установлен!" << std::endl;
		std::cout << "Нажмите любую клавишу для продолжения...";
		_getch();
	}
}

