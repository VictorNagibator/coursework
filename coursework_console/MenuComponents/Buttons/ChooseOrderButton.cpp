#include "ChooseOrderButton.h"
#include "../OrdersData.h"

ChooseOrderButton::ChooseOrderButton(const std::string& title, ChangeOrderMenu* menu) : Button(title)
{
	this->menu = menu;
}

void ChooseOrderButton::execute()
{
	std::cout << "������� ����� ������: ";
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
		std::cout << "������ � ����� ������� �� ����������!" << std::endl;
		std::cout << "������� ����� ������� ��� �����������...";
		_getch();
		return;
	}
	this->menu->setOrder(OrdersData::getOrder(orderNumber));
	std::cout << "������� ������ �����!" << std::endl;
	std::cout << "������� ����� ������� ��� �����������...";
	_getch();
	
	this->menu->show();
}