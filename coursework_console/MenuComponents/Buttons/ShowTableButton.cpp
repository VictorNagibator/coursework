#include <conio.h>
#include "ShowTableButton.h"
#include "../FileInfo.h"

ShowTableButton::ShowTableButton(const std::string& title) : Button(title)
{
	
}

void ShowTableButton::execute()
{
	system("cls");
	if (FileInfo::isPathSet()) {
		Table table = Table();
		table.fullShow();
		std::cout << "������� ����� �������, ����� ����������...";
		_getch();
	}
	else {
		std::cout << "���� � ����� �� ����������!" << std::endl;
		std::cout << "������� ����� ������� ��� �����������...";
		_getch();
	}
}