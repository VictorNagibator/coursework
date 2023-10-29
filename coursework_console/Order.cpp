#include "Order.h"

void Order::operator=(Order other) {
	this->num = other.num;
	this->laptop = other.laptop;
	this->status = other.status;
}

std::ostream& operator << (std::ostream& out, Order& order) {
	StatusType type = order.getStatus();
	out << order.getNum() << ". " << order.laptop.getName() << "\t" << type;
	return out;
}

bool Order::checkArguments(int num, Laptop laptop, StatusType status) {
	return num > 0 && status >= ONHOLD && status <= FINISHED;
}

Order::Order(Laptop laptop) {
	num = 1;
	this->laptop = laptop;
	status = ONHOLD;
}

Order::Order(int num, Laptop laptop, StatusType status) {
	if (checkArguments(num, laptop, status)) {
		this->num = num;
		this->laptop = laptop;
		this->status = status;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}

int Order::getNum() const {
	return num;
}

Laptop Order::getLaptop() const {
	return laptop;
}

StatusType Order::getStatus() const {
	return status;
}

void Order::input() {
	int num;
	Laptop laptop;
	StatusType status;

	std::cout << "Введите номер заказа: ";
	std::cin >> num;
	std::cout << "Введите статус заказа (0 - в ожидании, 1 - в ремонте, 2 - отремонтирован): ";
	std::cin >> status;
	std::cout << "\tВвод параметров ноутбука\n";
	laptop.input();
	if (checkArguments(num, laptop, status)) {
		this->num = num;
		this->laptop = laptop;
		this->status = status;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}

void Order::setStatus(StatusType status) {
	if (status >= ONHOLD && status <= FINISHED) {
		this->status = status;
		std::cout << "Состояние заказа успешно изменено!\n";
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}

void Order::setLaptop(Laptop laptop) {
	this->laptop = laptop;
}