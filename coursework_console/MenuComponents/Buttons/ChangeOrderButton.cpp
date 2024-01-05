#include <conio.h>
#include "ChangeOrderButton.h"
#include "../../DataManagers/OrdersData.h"
#include "../../DataManagers/FileInfo.h"

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
		
		system("cls");
		std::cout << "Успешное изменение данных заказа!" << std::endl;
	}
	catch (const std::exception& e)
	{
		system("cls");
		std::cout << std::endl << e.what() << std::endl;
	}
	std::cout << "Нажмите любую клавишу, чтобы продолжить...";
	_getch();
}