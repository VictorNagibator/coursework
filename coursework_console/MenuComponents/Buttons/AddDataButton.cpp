#include <fstream>
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
	o.input();
	OrdersData::addOrder(o);
	OrdersData::saveOrders(FileInfo::getPath());
}