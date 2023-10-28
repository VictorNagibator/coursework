#include <istream>
#include <iostream>
#include "Order.h"
#include "Laptop.h"

std::istream& operator >> (std::istream& in, StatusType& status) {
	int choice;
	in >> choice;
	switch (choice)
	{
	case 0:
		status = ONHOLD;
		break;
	case 1:
		status = INPROCCESS;
		break;
	case 2:
		status = FINISHED;
		break;
	default:
		break;
	}
	return in;
};

std::ostream& operator << (std::ostream& out, StatusType& status) {
	switch (status)
	{
	case ONHOLD:
		out << "В ожидании";
		break;
	case INPROCCESS:
		out << "В ремонте";
		break;
	case FINISHED:
		out << "Готов";
		break;
	default:
		break;
	}
	return out;
};


void Order::operator=(Order other) {
	this->num = other.num;
	this->laptop = other.laptop;
	this->status = other.status;
}

std::ostream& operator << (std::ostream& out, Order& order) {
	out << order.getNum() << ". " << order.laptop.getName() << "\t" << order.getStatus();
	return out;
}

bool Order::checkArguments(int num, Laptop laptop, StatusType status) {
	return num > 0 && status >= ONHOLD && status <= FINISHED;
}

Order::Order()
{
	num = 1;
	laptop = Laptop();
	status = ONHOLD;
}

Order::Order(Laptop laptop)
{
	num = 1;
	this->laptop = laptop;
	status = ONHOLD;
}

Order::Order(int num, Laptop laptop, StatusType status)
{
	if (checkArguments(num, laptop, status)) {
		this->num = num;
		this->laptop = laptop;
		this->status = status;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}

Order::~Order()
{
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