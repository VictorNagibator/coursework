#include "Order.h"

void Order::operator=(Order other) {
	this->id = other.getID();
	this->laptop = other.getLaptop();
	this->status = other.getStatus();
	this->additionalInfo = other.getAdditionalInfo();
}

std::ostream& operator << (std::ostream& out, Order& order) {
	out << order.toString();
	return out;
}

Order::Order() {
	id = ++lastID;
}

Order::Order(Laptop laptop) : Order(){
	this->laptop = laptop;
}

Order::Order(Laptop laptop, StatusType status, std::string additionalInfo) : Order(laptop) {
	this->status = status;
	this->additionalInfo = additionalInfo;
}

Order::Order(json j) {
	fromJSON(j);
	++lastID;
}

int Order::getLastID() {
	return lastID;
}

int Order::getID() const {
	return id;
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
	StatusType status;
	std::string additionalInfo;

	std::cout << "Номер заказа: " << lastID << std::endl;
	std::cout << "Введите статус заказа (0 - в ожидании, 1 - в ремонте, 2 - отремонтирован): ";
	std::cin >> status;
	std::cin.clear();
	while (std::cin.get() != '\n');
	std::cout << "\tВвод параметров ноутбука\n";
	laptop.input();
	std::cout << "\tВвод дополнительной информации\n";
	std::getline(std::cin, additionalInfo);

	this->id = this->lastID;
	this->laptop = laptop;
	this->status = status;
	this->additionalInfo = additionalInfo;
}

void Order::setStatus(StatusType status) {
	this->status = status;
	std::cout << "Состояние заказа успешно изменено!\n";
}

void Order::setLaptop(Laptop laptop) {
	this->laptop = laptop;
}

void Order::setAdditionalInfo(std::string additionalInfo) {
	this->additionalInfo = additionalInfo;
}

std::string Order::toString() const {
	std::string name = std::to_string(this->getID()) + ". " + this->laptop.getModelName() + "\t" + statusTypeToString(this->getStatus()) + '\t' + this->getAdditionalInfo();
	return name;
}

json Order::toJSON() const {
	json j;
	j["numOfOrder"] = id;
	j["laptop"] = laptop.toJSON();
	j["status"] = statusTypeToString(status);
	j["additionalInfo"] = additionalInfo;
	return j;
}

void Order::fromJSON(json j) {
	id = j["numOfOrder"];
	laptop.fromJSON(j["laptop"]);
	status = stringToStatusType(j["status"]);
	additionalInfo = j["additionalInfo"];
}