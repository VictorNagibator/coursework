#include "ChooseOrderButton.h"
#include "../OrdersData.h"

ChooseOrderButton::ChooseOrderButton(const std::string& title, ChangeOrderMenu* menu) : Button(title)
{
	this->menu = menu;
}

void ChooseOrderButton::execute()
{
	std::cout << "Введите номер заказа: ";
	int orderNumber;
	std::cin >> orderNumber;
	std::cin.clear();
	while (std::cin.get() != '\n');
	system("cls");
	try
	{
		OrdersData::getOrder(orderNumber);
	}
	catch (const std::exception&)
	{
		std::cout << "Заказа с таким номером не существует!" << std::endl;
		std::cout << "Нажмите любую клавишу для продолжения...";
		_getch();
		return;
	}
	this->menu->setOrder(OrdersData::getOrder(orderNumber));
	std::cout << "Успешно выбран заказ!" << std::endl;
	std::cout << "Нажмите любую клавишу для продолжения...";
	_getch();
	
	this->menu->show();
}