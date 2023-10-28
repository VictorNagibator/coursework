#include <istream>
#include <iostream>
#include <string>
#include <vector>
#include "RAM.h"

void RAM::operator=(RAM other) {
	this->name = other.getName();
	this->type = other.getRAMType();
	this->frequency = other.getFrequency();
	this->capacity = other.getCapacity();
}

std::ostream& operator << (std::ostream& out, const RAM& ram) {
	out << ram.getName() << ", " << ram.getRAMType() << ", " << ram.getCapacity() << " ГБ, " << ram.getFrequency() << " МГц";
	return out;
}

RAM::RAM()
{

}

RAM::RAM(std::string name)
{
	this->name = name;
}

RAM::RAM(RAMType type) {
	this->type = type;
}

RAM::RAM(std::string name, RAMType type, float frequency, int capacity)
{
	setArguments(name, type, frequency, capacity);
}

RAM::~RAM()
{
}

std::string RAM::getName() const {
	return name;
}

RAMType RAM::getRAMType() const {
	return type;
}

float RAM::getFrequency() const {
	return frequency;
}

int RAM::getCapacity() const {
	return capacity;
}

void RAM::input() {
	std::string name;
	RAMType type;
	float frequency;
	int capacity;

	std::cout << "Введите название RAM: ";
	std::getline(std::cin, name);
	std::cout << "Введите тип памяти (DDR - 0, DDR2 - 1, DDR3 - 2, DDR4 - 3, DDR5 - 4): ";
	std::cin >> type;
	std::cout << "Введите тактовую частоту (в МГц): ";
	std::cin >> frequency;
	std::cout << "Введите объем (в ГБ): ";
	std::cin >> capacity;
	while (getchar() != '\n');

	checkArguments(name, type, frequency, capacity);
}


bool RAM::checkArguments(std::string name, RAMType type, float frequency, int capacity) {
	return type >= DDR && type <= DDR5 && frequency >= 0 && frequency <= DDRFreqMax[type] && capacity >= 0;
}

void RAM::setArguments(std::string name, RAMType type, float frequency, int capacity) {
	if (checkArguments(name, type, frequency, capacity)) {
		this->name = name;
		this->type = type;
		this->frequency = frequency;
		this->capacity = capacity;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}