#include "Order.h"

std::ostream& operator << (std::ostream& out, Order& order) {
	out << order.toString();
	return out;
}

Order::Order(Laptop laptop) {
	numOfOrder = ++numOfLastOrder;
	this->laptop = laptop;
}

Order::Order(Laptop laptop, StatusType status, std::string additionalInfo) : Order(laptop) {
	this->status = status;
	this->additionalInfo = additionalInfo;
}

int Order::getNumOfLastOrder() {
	return numOfLastOrder;
}

int Order::getNumOfOrder() const {
	return numOfOrder;
}

const Laptop& Order::getLaptop() const {
	return laptop;
}

StatusType Order::getStatus() const {
	return status;
}

std::string Order::getAdditionalInfo() const {
	return additionalInfo;
}

void Order::input() {
	Laptop laptop;
	StatusType type;
	std::string additionalInfo;
	numOfLastOrder++;

	std::cout << "����� ������: " << numOfLastOrder << std::endl;
	std::cout << "������� ������ ������ (0 - � ��������, 1 - � �������, 2 - ��������������): ";
	std::cin >> type;
	std::cin.clear();
	while (std::cin.get() != '\n');
	std::cout << "\t���� ���������� ��������\n";
	laptop.input();
	std::cout << "\t���� �������������� ����������\n";
	std::getline(std::cin, additionalInfo);

	this->numOfOrder = this->numOfLastOrder;
	this->laptop = laptop;
	this->status = status;
	this->additionalInfo = additionalInfo;
}

void Order::setStatus(StatusType status) {
	this->status = status;
	std::cout << "��������� ������ ������� ��������!\n";
}

void Order::setLaptop(Laptop laptop) {
	this->laptop = laptop;
}

void Order::setAdditionalInfo(std::string additionalInfo) {
	this->additionalInfo = additionalInfo;
}

std::string Order::toString() const {
	std::string name = std::to_string(this->getNumOfOrder()) + ". " + this->laptop.getModelName() + "\t" + statusTypeToString(this->getStatus()) + '\t' + this->getAdditionalInfo();
	return name;
}

json Order::toJSON() const {
	json j;
	j["numOfOrder"] = numOfOrder;
	j["laptop"] = laptop.toJSON();
	j["status"] = statusTypeToString(status);
	j["additionalInfo"] = additionalInfo;
	return j;
}

void Order::fromJSON(json j) {
	numOfOrder = j["numOfOrder"];
	laptop.fromJSON(j["laptop"]);
	status = stringToStatusType(j["status"]);
	additionalInfo = j["additionalInfo"];
}