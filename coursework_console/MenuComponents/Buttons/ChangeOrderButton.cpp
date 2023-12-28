#include <conio.h>
#include "ChangeOrderButton.h"
#include "../OrdersData.h"
#include "../FileInfo.h"

ChangeOrderButton::ChangeOrderButton(const std::string& title, ChangeOrderMenu* menu, ChangableObject changableObject) : Button(title)
{
	this->parentMenu = menu;
	this->changableObject = changableObject;
}

void ChangeOrderButton::setPreviousMenu(ChangeOrderMenu* menu)
{
	this->parentMenu = menu;
}

void ChangeOrderButton::setChangableObject(ChangableObject changableObject)
{
	this->changableObject = changableObject;
}

void ChangeOrderButton::execute()
{
	Order newOrder = OrdersData::getOrder(this->parentMenu->getID());
	try
	{
		OrdersData::editOrder(newOrder, changableObject);
		OrdersData::saveOrders(FileInfo::getPath());

		std::cout << std::endl << "�������� ��������� ������ ������!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << std::endl << e.what() << std::endl;
	}
	std::cout << "������� ����� �������, ����� ����������...";
	_getch();
}