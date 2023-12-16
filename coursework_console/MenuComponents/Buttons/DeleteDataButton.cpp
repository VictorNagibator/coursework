#include <conio.h>
#include "DeleteDataButton.h"
#include "../OrdersData.h"
#include "../Table.h"
#include "../FileInfo.h"

DeleteDataButton::DeleteDataButton(const std::string& title) : Button(title)
{

}

void DeleteDataButton::execute()
{
	std::cout << "������� id ���������� ������: ";
	int id;
	std::cin >> id;
	std::cin.clear();
	while (std::cin.get() != '\n');
	if (checkArguments(id)) {
		system("cls");
		Table table = Table();
		table.showOrder(OrdersData::getOrder(id));
		std::cout << "�� �������, ��� ������ ������� �����? (y/n): ";
		char answer = _getch();
		system("cls");
		if (answer == 'y') {
			OrdersData::removeOrder(id);
			OrdersData::saveOrders(FileInfo::getPath());
			std::cout << "����� ������� ������!" << std::endl;
		}
		else {
			std::cout << "����� �� ������!" << std::endl;
		}
	}
	else {
		std::cout << "������ � ����� id �� ����������!" << std::endl;
	}
	std::cout << "������� ����� ������� ��� �����������...";
	_getch();
}

bool DeleteDataButton::checkArguments(int id)
{
	auto data = OrdersData::getData();
	for (auto& order : data)
	{
		if (order.getNumOfOrder() == id) return true;
	}
	return false;
}