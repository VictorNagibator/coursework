#include "ChooseOrderButton.h"
#include "../OrdersData.h"

ChooseOrderButton::ChooseOrderButton(const std::string& title, ChangeOrderMenu* menu) : Button(title)
{
	this->menu = menu;
}

void ChooseOrderButton::execute()
{
	std::cout << "������� ID ������: ";
	int orderNumber;
	std::cin >> orderNumber;
	std::cin.clear();
	while (std::cin.get() != '\n');
	system("cls");
	try
	{
		OrdersData::getOrder(orderNumber);
		this->menu->setID(orderNumber);
		std::cout << "������� ������ �����!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << std::endl << e.what() << std::endl;
		std::cout << "������� ����� ������� ��� �����������...";
		_getch();
		return;
	}
	std::cout << "������� ����� ������� ��� �����������...";
	_getch();
	
	this->menu->show();
}