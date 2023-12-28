#include <conio.h>
#include "FindOrderButton.h"
#include "../OrdersData.h"
#include "../Table.h"

FindOrderButton::FindOrderButton(const std::string& title) : Button(title)
{

}

void FindOrderButton::execute()
{
	std::cout << "������� ID ������: ";
	int id;
	std::cin >> id;
	std::cin.clear();
	while (std::cin.get() != '\n');
	
	try
	{
		system("cls");
		Order order = OrdersData::getOrder(id);
		Table table = Table();
		table.showOrder(order);
		std::cout << "���������� � ��������:" << std::endl;
		std::cout << OrdersData::getOrder(id).getLaptop() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "������� ����� ������� ��� �����������...";
	_getch();
}