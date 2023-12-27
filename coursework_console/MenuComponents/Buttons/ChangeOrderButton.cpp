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
	OrdersData::editOrder(this->parentMenu->getOrder(), changableObject);
	OrdersData::saveOrders(FileInfo::getPath());
	std::cout << "Нажмите любую клавишу, чтобы продолжить...";
	_getch();
}