#include "Motherboard.h"

void Motherboard::operator=(Motherboard other) {
	this->name = other.getName();
	this->socket = other.getSocket();
	this->chipset = other.getChipset();
	this->supportedRAMType = other.getSupportedRAMType();
}

std::ostream& operator << (std::ostream& out, const Motherboard& motherboard) {
	out << motherboard.getName() << ", " << motherboard.getSocket() << ", " << motherboard.getChipset();
	return out;
}

Motherboard::Motherboard(std::string name) {
	this->name = name;
}

Motherboard::Motherboard(std::string name, std::string socket, std::string chipset, RAMType supportedRAMType) {
	setArguments(name, socket, chipset, supportedRAMType);
}

Motherboard::~Motherboard() {

}

std::string Motherboard::getName() const {
	return name;
}

std::string Motherboard::getSocket() const {
	return socket;
}

std::string Motherboard::getChipset() const {
	return chipset;
}

RAMType Motherboard::getSupportedRAMType() const {
	return supportedRAMType;
}

void Motherboard::input() {
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
	
	setArguments(name, socket, chipset, supportedRAMType);
}


bool Motherboard::checkArguments(std::string name, std::string socket, std::string chipset, RAMType supportedRAMType) {
	return supportedRAMType >= DDR && supportedRAMType <= DDR5;
}

void Motherboard::setArguments(std::string name, std::string socket, std::string chipset, RAMType supportedRAMType) {
	if (checkArguments(name, socket, chipset, supportedRAMType)) {
		this->name = name;
		this->socket = socket;
		this->chipset = chipset;
		this->supportedRAMType = supportedRAMType;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}