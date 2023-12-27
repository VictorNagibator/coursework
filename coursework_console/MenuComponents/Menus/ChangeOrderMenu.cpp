#include "ChangeOrderMenu.h"
#include "../Table.h"
#include "../OrdersData.h"

ChangeOrderMenu::ChangeOrderMenu(const std::string& title) : Menu(title) 
{
	
}

ChangeOrderMenu::ChangeOrderMenu(const std::string& title, int idOfOrder) : Menu(title) 
{
	this->changableOrder = OrdersData::getOrder(idOfOrder);
}

ChangeOrderMenu::ChangeOrderMenu(const std::string& title, const Order& order) : Menu(title)
{
	this->changableOrder = order;
}

void ChangeOrderMenu::show()
{
	system("cls");
	Table table = Table();
	table.showOrder(this->changableOrder);
	Menu::show();
}

const Order& ChangeOrderMenu::getOrder() const
{
	return this->changableOrder;
}

void ChangeOrderMenu::setOrder(const Order& order)
{
	this->changableOrder = order;
}