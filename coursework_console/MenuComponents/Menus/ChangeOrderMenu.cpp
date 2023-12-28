#include "ChangeOrderMenu.h"
#include "../Table.h"
#include "../OrdersData.h"

ChangeOrderMenu::ChangeOrderMenu(const std::string& title) : Menu(title)
{
	
}

ChangeOrderMenu::ChangeOrderMenu(const std::string& title, int idOfOrder) : Menu(title) 
{
	this->idOfChangableOrder = idOfOrder;
}

void ChangeOrderMenu::show()
{
	system("cls");
	Table table = Table();
	table.showOrder(OrdersData::getOrder(this->idOfChangableOrder));
	std::cout << "Информация о ноутбуке:" << std::endl;
	std::cout << OrdersData::getOrder(this->idOfChangableOrder).getLaptop() << std::endl;
	Menu::show();
}

int ChangeOrderMenu::getID() const
{
	return this->idOfChangableOrder;
}

void ChangeOrderMenu::setID(int id)
{
	this->idOfChangableOrder = id;
}