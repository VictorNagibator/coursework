#include "MenuWithTable.h"
#include "../FileInfo.h"

MenuWithTable::MenuWithTable(const std::string& text) : Menu(text)
{
	
};

void MenuWithTable::show()
{
	system("cls");
	if (FileInfo::isPathSet()) {
		Table table = Table();
		table.shortShow();
		Menu::show();
	}	
	else {
		std::cout << "Путь к файлу не установлен!" << std::endl;
		std::cout << "Нажмите любую клавишу для продолжения...";
		_getch();
	}
}

