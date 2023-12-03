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
		std::cout << "Нажмите любую клавишу, чтобы продолжить...";
		_getch();
	}
	else {
		std::cout << "Путь к файлу не установлен!" << std::endl;
		std::cout << "Нажмите любую клавишу для продолжения...";
		_getch();
	}
}