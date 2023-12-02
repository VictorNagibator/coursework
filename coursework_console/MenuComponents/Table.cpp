#include <fstream>
#include "Table.h"
#include "FileInfo.h"
#include "../OrderComponents/Order.h"

Table::Table() {
	loadJSON(FileInfo::getPath());
}

Table::Table(const std::string& filePath) {
	loadJSON(filePath);
	FileInfo::setPath(filePath);
}

void Table::shortShow() const {
	showHeader();
	for (auto& order : data) {
		Order o = Order();
		o.fromJSON(order);
		std::string res = std::format("*{:^14d}*{:^17s}*{:^8s}*{:^22s}*", o.getNumOfOrder(), o.getLaptop().getModelName(), statusTypeToString(o.getStatus()), o.getAdditionalInfo());
		std::cout << res << std::endl;
		if (o.getNumOfOrder() == 5) break;
	}
	std::cout << std::format("*{:^14s}*{:^17s}*{:^8s}*{:^22s}*", "...", "...", "...", "...") << std::endl;
	showBottom();
}

void Table::fullShow() const {
	showHeader();
	for (auto& order : data) {
		Order o = Order();
		o.fromJSON(order);
		std::string res = std::format("*%14d*%17s*%8s*%22s*\n", o.getNumOfOrder(), o.getLaptop().getModelName(), statusTypeToString(o.getStatus()), o.getAdditionalInfo());
		std::cout << res << std::endl;
	}
	showBottom();
}

void Table::showHeader() const {
	std::cout << "*******************************************************************" << '\n'
			  << "* Номер заказа * Название модели * Статус * Дополнительная инфо. *" << '\n'
		      << "*******************************************************************" << '\n';
}

void Table::showBottom() const {
	std::cout << "*******************************************************************" << '\n';
}

void Table::loadJSON(const std::string& filePath) {
	std::ifstream file(filePath);
	this->data = json::parse(file);
	file.close();
}