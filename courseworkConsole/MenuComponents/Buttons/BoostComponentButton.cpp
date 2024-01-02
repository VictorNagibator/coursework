#include "BoostComponentButton.h"
#include "../OrdersData.h"
#include "../FileInfo.h"

BoostComponentButton::BoostComponentButton(const std::string& title, ChangeOrderMenu* menu, ChangableObject changableObject) : ChangeOrderButton(title, menu, changableObject)
{

}

void BoostComponentButton::execute()
{
	try
	{
		Order newOrder = OrdersData::getOrder(this->parentMenu->getID());

		OrdersData::boostLaptopComponent(newOrder, changableObject);
		OrdersData::saveOrders(FileInfo::getPath());

		std::cout << "Успешный разгон компонента!" << std::endl;
	}
	catch (const std::exception&)
	{
		std::cout << "Некорректные данные для разгона компонента!" << std::endl;
	}
	
	std::cout << "Нажмите любую клавишу, чтобы продолжить...";
	_getch();
}