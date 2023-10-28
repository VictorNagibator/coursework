#include <string>
#include <iostream>
#include <istream>
#include "HDD.h"

void HDD::operator=(HDD other) {
	this->capacity = other.capacity;
	this->interface = other.interface;
	this->brand = other.brand;
	this->spindleSpeed = other.spindleSpeed;
	this->formFactor = other.formFactor;
}

std::ostream& operator << (std::ostream& out, const HDD& hdd) {
	out << hdd.getBrand() << ", " << hdd.getCapacity() << "ГБ, " << hdd.getInterface() << ", " << hdd.getFormFactor();
	return out;
}

HDD::HDD() {

}

HDD::HDD(DataTransferInterface interface) {
	this->interface = interface;
}

HDD::HDD(int capacity, DataTransferInterface interface, std::string brand, int spindleSpeed, float formFactor) {
	setArguments(capacity, interface, brand, spindleSpeed, formFactor);
}

int HDD::getCapacity() const {
	return capacity;
}

DataTransferInterface HDD::getInterface() const {
	return interface;
}

std::string HDD::getBrand() const {
	return brand;
}

int HDD::getSpindleSpeed() const {
	return spindleSpeed;
}

float HDD::getFormFactor() const {
	return formFactor;
}

void HDD::input() {
	int capacity;
	DataTransferInterface interface;
	std::string brand;
	int spindleSpeed;
	float formFactor;

	std::cout << "Введите вместимость: ";
	std::cin >> capacity;
	std::cout << "Введите интерфейс подключения (PATA - 0, SATA - 1, SAS - 2): ";
	std::cin >> interface;
	while (getchar() != '\n');
	std::cout << "Введите производителя: ";
	std::getline(std::cin, brand);
	std::cout << "Введите cкорость вращения шпинделя: ";
	std::cin >> spindleSpeed;
	std::cout << "Введите форм фактор (в дюймах): ";
	std::cin >> formFactor;
	while (getchar() != '\n');

	checkArguments(capacity, interface, brand, spindleSpeed, formFactor);
}


bool HDD::checkArguments(int capacity, DataTransferInterface interface, std::string brand, int spindleSpeed, float formFactor) {
	return capacity >= 0 && interface >= PATA && interface <= SAS && spindleSpeed >= 0 && formFactor >= 0;
}

void HDD::setArguments(int capacity, DataTransferInterface interface, std::string brand, int spindleSpeed, float formFactor) {
	if (checkArguments(capacity, interface, brand, spindleSpeed, formFactor)) {
		this->capacity = capacity;
		this->interface = interface;
		this->brand = brand;
		this->spindleSpeed = spindleSpeed;
		this->formFactor = formFactor;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}