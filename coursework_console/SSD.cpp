#include <string>
#include <iostream>
#include <istream>
#include "SSD.h"

void SSD::operator=(SSD other) {
	this->capacity = other.capacity;
	this->interface = other.interface;
	this->brand = other.brand;
	this->formFactor = other.formFactor;
	this->typeOfFlashMemory = other.typeOfFlashMemory;
}

std::ostream& operator << (std::ostream& out, const SSD& ssd) {
	out << ssd.getBrand() << ", " << ssd.getCapacity() << "ГБ, " << ssd.getInterface() << ", " << ssd.getFormFactor() << ", " << ssd.getTypeOfFlashMemory();
	return out;
}

SSD::SSD() {

}

SSD::SSD(DataTransferInterface interface) {
	this->interface = interface;
}

SSD::SSD(int capacity, DataTransferInterface interface, std::string brand, FlashMemoryType typeOfFlashMemory, float formFactor) {
	setArguments(capacity, interface, brand, typeOfFlashMemory, formFactor);
}

int SSD::getCapacity() const {
	return capacity;
}

DataTransferInterface SSD::getInterface() const {
	return interface;
}

std::string SSD::getBrand() const {
	return brand;
}

FlashMemoryType SSD::getTypeOfFlashMemory() const {
	return typeOfFlashMemory;
}

float SSD::getFormFactor() const {
	return formFactor;
}

void SSD::input() {
	int capacity;
	DataTransferInterface interface;
	std::string brand;
	FlashMemoryType typeOfFlashMemory;
	float formFactor;

	std::cout << "Введите вместимость: ";
	std::cin >> capacity;
	std::cout << "Введите интерфейс подключения (PATA - 0, SATA - 1, SAS - 2): ";
	std::cin >> interface;
	while (getchar() != '\n');
	std::cout << "Введите производителя: ";
	std::getline(std::cin, brand);
	std::cout << "Введите тип флеш-памяти (0 - SLC, 1 - MLC, 2 - NOR, 3 - NAND, 4 - 3DNAND): ";
	std::cin >> typeOfFlashMemory;
	std::cout << "Введите форм фактор (в дюймах): ";
	std::cin >> formFactor;
	while (getchar() != '\n');

	checkArguments(capacity, interface, brand, typeOfFlashMemory, formFactor);
}


bool SSD::checkArguments(int capacity, DataTransferInterface interface, std::string brand, FlashMemoryType typeOfFlashMemory, float formFactor) {
	return capacity >= 0 && interface >= PATA && interface <= SAS && typeOfFlashMemory >= SLC && typeOfFlashMemory <= NAND3D && formFactor >= 0;
}

void SSD::setArguments(int capacity, DataTransferInterface interface, std::string brand, FlashMemoryType typeOfFlashMemory, float formFactor) {
	if (checkArguments(capacity, interface, brand, typeOfFlashMemory, formFactor)) {
		this->capacity = capacity;
		this->interface = interface;
		this->brand = brand;
		this->typeOfFlashMemory = typeOfFlashMemory;
		this->formFactor = formFactor;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}