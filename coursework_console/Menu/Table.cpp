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
		Order o;
		o.fromJSON(order);
		std::cout << "* " << o.getNumOfOrder() << " * " << o.getLaptop().getModelName() << " * " << statusTypeToString(o.getStatus()) << " * " << '\n';
		if (o.getNumOfOrder() == 5) break;
	}
	std::cout << "* " << "..." << " * " << "..." << " * " << "..." << " * " << '\n';
	showBottom();
}

void Table::fullShow() const {
	showHeader();
	for (auto& order : data) {
		Order o;
		o.fromJSON(order);
		std::cout << "* " << o.getNumOfOrder() << " * " << o.getLaptop().getModelName() << " * " << statusTypeToString(o.getStatus()) << " * " << o.getAdditionalInfo() << " *" << '\n';
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
	json data = json::parse(file);
}