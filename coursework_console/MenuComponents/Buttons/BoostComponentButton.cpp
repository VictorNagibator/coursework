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

		std::cout << "�������� ������ ����������!" << std::endl;
	}
	catch (const std::exception&)
	{
		std::cout << "������������ ������ ��� ������� ����������!" << std::endl;
	}
	
	std::cout << "������� ����� �������, ����� ����������...";
	_getch();
}