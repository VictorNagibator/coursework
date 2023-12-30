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
	if (OrdersData::isDataEmpty()) {
		std::cout << "Нет данных для удаления!" << std::endl;
		std::cout << "Нажмите любую клавишу для продолжения...";
		_getch();
		return;
	}

	std::cout << "Введите id удаляемого заказа: ";
	int id;
	std::cin >> id;
	std::cin.clear();
	while (std::cin.get() != '\n');
	if (checkArguments(id)) {
		system("cls");
		Table table = Table();
		table.showOrder(OrdersData::getOrder(id));
		std::cout << "Вы уверены, что хотите удалить заказ? (y/n): ";
		char answer = _getch();
		system("cls");
		if (answer == 'y') {
			OrdersData::removeOrder(id);
			OrdersData::saveOrders(FileInfo::getPath());
			std::cout << "Заказ успешно удален!" << std::endl;
		}
		else {
			std::cout << "Заказ не удален!" << std::endl;
		}
	}
	else {
		std::cout << "Заказа с таким id не существует!" << std::endl;
	}
	std::cout << "Нажмите любую клавишу для продолжения...";
	_getch();
}

bool DeleteDataButton::checkArguments(int id)
{
	auto data = OrdersData::getData();
	for (auto& order : data)
	{
		if (order.getID() == id) return true;
	}
	return false;
}