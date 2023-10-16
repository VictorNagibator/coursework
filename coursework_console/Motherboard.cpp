#include <iostream>
#include <string>
#include "Motherboard.h"
#include "RAM.h"

void Motherboard::operator=(Motherboard other) {
	this->name = other.GetName();
	this->socket = other.GetSocket();
	this->chipset = other.GetChipset();
	this->supportedRAMType = other.GetSupportedRAMType();
}

std::ostream& operator << (std::ostream& out, const Motherboard& motherboard) {
	out << motherboard.GetName() << ", " << motherboard.GetSocket() << ", " << motherboard.GetChipset();
	return out;
}

Motherboard::Motherboard()
{
}

Motherboard::Motherboard(std::string name)
{
	this->name = name;
}

Motherboard::Motherboard(std::string name, std::string socket, std::string chipset, RAMType supportedRAMType)
{
	SetArguments(name, socket, chipset, supportedRAMType);
}

Motherboard::~Motherboard()
{
}

std::string Motherboard::GetName() const {
	return name;
}

std::string Motherboard::GetSocket() const {
	return socket;
}

std::string Motherboard::GetChipset() const {
	return chipset;
}

RAMType Motherboard::GetSupportedRAMType() const {
	return supportedRAMType;
}

void Motherboard::Input() {
	std::string name, socket, chipset;
	RAMType supportedRAMType;

	std::cout << "Введите название материнской платы: ";
	std::getline(std::cin, name);
	std::cout << "Введите сокет: ";
	std::getline(std::cin, socket);
	std::cout << "Введите чипсет: ";
	std::getline(std::cin, chipset);
	std::cout << "Введите поддерживаемый тип памяти (DDR - 0, DDR2 - 1, DDR3 - 2, DDR4 - 3, DDR5 - 4): ";
	std::cin >> supportedRAMType;
	while (getchar() != '\n');
	
	SetArguments(name, socket, chipset, supportedRAMType);
}


bool Motherboard::CheckArguments(std::string name, std::string socket, std::string chipset, RAMType supportedRAMType) {
	return supportedRAMType >= DDR && supportedRAMType <= DDR5;
}

void Motherboard::SetArguments(std::string name, std::string socket, std::string chipset, RAMType supportedRAMType) {
	if (CheckArguments(name, socket, chipset, supportedRAMType)) {
		this->name = name;
		this->socket = socket;
		this->chipset = chipset;
		this->supportedRAMType = supportedRAMType;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}