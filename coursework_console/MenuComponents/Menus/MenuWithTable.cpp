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
		std::cout << "���� � ����� �� ����������!" << std::endl;
		std::cout << "������� ����� ������� ��� �����������...";
		_getch();
	}
}

