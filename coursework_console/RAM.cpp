#include <istream>
#include <iostream>
#include <string>
#include <vector>
#include "RAM.h"

std::istream& operator >> (std::istream& in, RAMType& type) {
	int choice;
	in >> choice;
	switch (choice)
	{
	case 0:
		type = DDR;
		break;
	case 1:
		type = DDR2;
		break;
	case 2:
		type = DDR3;
		break;
	case 3:
		type = DDR4;
		break;
	case 4:
		type = DDR5;
		break;
	default:
		break;
	}
	return in;
};

std::ostream& operator << (std::ostream& out, RAMType& type) {
	switch (type)
	{
	case DDR:
		out << "DDR";
		break;
	case DDR2:
		out << "DDR2";
		break;
	case DDR3:
		out << "DDR3";
		break;
	case DDR4:
		out << "DDR4";
		break;
	case DDR5:
		out << "DDR5";
		break;
	default:
		break;
	}
	return out;
};


void RAM::operator=(RAM other) {
	this->name = other.GetName();
	this->type = other.GetRAMType();
	this->frequency = other.GetFrequency();
	this->capacity = other.GetCapacity();
}

std::ostream& operator << (std::ostream& out, const RAM& ram) {
	out << ram.GetName() << ", " << ram.GetRAMType() << ", " << ram.GetCapacity() << " ГБ, " << ram.GetFrequency() << " МГц";
	return out;
}

RAM::RAM()
{

}

RAM::RAM(std::string name)
{
	this->name = name;
}

RAM::RAM(std::string name, RAMType type, float frequency, int capacity)
{
	SetArguments(name, type, frequency, capacity);
}

RAM::~RAM()
{
}

std::string RAM::GetName() const {
	return name;
}

RAMType RAM::GetRAMType() const {
	return type;
}

float RAM::GetFrequency() const {
	return frequency;
}

int RAM::GetCapacity() const {
	return capacity;
}

void RAM::Input() {
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

	CheckArguments(name, type, frequency, capacity);
}


bool RAM::CheckArguments(std::string name, RAMType type, float frequency, int capacity) {
	return type >= DDR && type <= DDR5 && frequency >= 0 && frequency <= DDRFreqMax[type] && capacity >= 0;
}

void RAM::SetArguments(std::string name, RAMType type, float frequency, int capacity) {
	if (CheckArguments(name, type, frequency, capacity)) {
		this->name = name;
		this->type = type;
		this->frequency = frequency;
		this->capacity = capacity;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}