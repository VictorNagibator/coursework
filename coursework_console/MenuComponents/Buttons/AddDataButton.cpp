#include <fstream>
#include <conio.h>
#include "AddDataButton.h"
#include "../../OrderComponents/Order.h"
#include "../FileInfo.h"
#include "../OrdersData.h"

AddDataButton::AddDataButton(const std::string& title) : Button(title)
{

}

void AddDataButton::execute() 
{
	Order o = Order();
	try
	{
		o.input();
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "Нажмите любую клавишу, чтобы продолжить...";
		_getch();
		OrdersData::verifyIDs();
		return;
	}
	
	OrdersData::addOrder(o);
	OrdersData::saveOrders(FileInfo::getPath());
}