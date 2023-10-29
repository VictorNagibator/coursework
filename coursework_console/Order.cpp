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
	else throw std::invalid_argument("������������ ������ ������!");
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

	std::cout << "������� ����� ������: ";
	std::cin >> num;
	std::cout << "������� ������ ������ (0 - � ��������, 1 - � �������, 2 - ��������������): ";
	std::cin >> status;
	std::cout << "\t���� ���������� ��������\n";
	laptop.input();
	if (checkArguments(num, laptop, status)) {
		this->num = num;
		this->laptop = laptop;
		this->status = status;
	}
	else throw std::invalid_argument("������������ ������ ������!");
}

void Order::setStatus(StatusType status) {
	if (status >= ONHOLD && status <= FINISHED) {
		this->status = status;
		std::cout << "��������� ������ ������� ��������!\n";
	}
	else throw std::invalid_argument("������������ ������ ������!");
}

void Order::setLaptop(Laptop laptop) {
	this->laptop = laptop;
}