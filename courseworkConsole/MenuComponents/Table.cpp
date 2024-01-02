#include <fstream>
#include "Table.h"
#include "FileInfo.h"
#include "../OrderComponents/Order.h"
#include "OrdersData.h"

void Table::showOrder(Order order) const {
	showHeader();
	std::string res = std::format("*{:^14d}*{:^17s}*{:^8s}*{:^22s}*", order.getID(), order.getLaptop().getModelName(), statusTypeToString(order.getStatus()), order.getAdditionalInfo());
	std::cout << res << std::endl;
	showFooter();
}

void Table::shortShow(std::vector<Order> data) const {
	showHeader();
	int num = 0;
	for (auto& order : data) {
		num++;
		std::string res = std::format("*{:^14d}*{:^17s}*{:^8s}*{:^22s}*", order.getID(), order.getLaptop().getModelName(), statusTypeToString(order.getStatus()), order.getAdditionalInfo());
		std::cout << res << std::endl;
		if (num == 5) break;
	}
	std::cout << std::format("*{:^14s}*{:^17s}*{:^8s}*{:^22s}*", "...", "...", "...", "...") << std::endl;
	showFooter();
}

void Table::fullShow(std::vector<Order> data) const {
	showHeader();
	for (auto& order : data) {
		std::string res = std::format("*{:^14d}*{:^17s}*{:^8s}*{:^22s}*", order.getID(), order.getLaptop().getModelName(), statusTypeToString(order.getStatus()), order.getAdditionalInfo());
		std::cout << res << std::endl;
	}
	showFooter();
}

void Table::showHeader() const {
	std::cout << "*******************************************************************" << '\n'
			  << "* Номер заказа * Название модели * Статус * Дополнительная инфо. *" << '\n'
		      << "*******************************************************************" << '\n';
}

void Table::showFooter() const {
	std::cout << "*******************************************************************" << '\n';
}