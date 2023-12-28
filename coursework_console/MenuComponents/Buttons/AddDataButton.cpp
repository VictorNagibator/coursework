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

		OrdersData::addOrder(o);
		OrdersData::saveOrders(FileInfo::getPath());
		
		system("cls");
		std::cout << "Запись успешно добавлена!" << std::endl;
	}
	catch (const std::invalid_argument& e)
	{
		system("cls");
		std::cout << e.what() << std::endl;
		OrdersData::verifyIDs();
	}
	
	std::cout << "Нажмите любую клавишу, чтобы продолжить...";
	_getch();
}