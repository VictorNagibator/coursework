#include <conio.h>
#include "ShowTableButton.h"
#include "../../DataManagers/OrdersData.h"
#include "../../DataManagers/FileInfo.h"

ShowTableButton::ShowTableButton(const std::string& title) : Button(title)
{
	
}

void ShowTableButton::execute()
{
	if (FileInfo::isPathSet()) {
		Table table = Table();
		table.fullShow(OrdersData::getData());
		std::cout << "Нажмите любую клавишу, чтобы продолжить...";
		_getch();
	}
	else {
		std::cout << "Путь к файлу не установлен!" << std::endl;
		std::cout << "Нажмите любую клавишу для продолжения...";
		_getch();
	}
}