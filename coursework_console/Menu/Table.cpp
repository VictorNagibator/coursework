#include <fstream>
#include "Table.h"

Table::Table(const std::string& filePath) {
	this->filePath = filePath;

	std::ifstream file(filePath);
	data = json::parse(file);
}

void Table::shortShow() const {

}

void Table::fullShow() const {

}