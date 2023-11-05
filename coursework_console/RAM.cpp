﻿#include "RAM.h"

void RAM::operator=(RAM other) {
	this->modelName = other.getModelName();
	this->type = other.getRAMType();
	this->frequency = other.getFrequency();
	this->capacity = other.getCapacity();
}

std::ostream& operator << (std::ostream& out, const RAM& ram) {
	out << ram.toString();
	return out;
}

RAM::RAM(std::string modelName) {
	this->modelName = modelName;
}

RAM::RAM(RAMType type) {
	this->type = type;
}

RAM::RAM(std::string modelName, RAMType type, float frequency, int capacity) {
	tryToSetArguments(modelName, type, frequency, capacity);
}

std::string RAM::getComponentName() const {
	return "RAM";
}

std::string RAM::getModelName() const {
	return modelName;
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
	std::string modelName;
	RAMType type;
	float frequency;
	int capacity;

	std::cout << "Введите название RAM: ";
	std::getline(std::cin, modelName);
	std::cout << "Введите тип памяти (DDR - 0, DDR2 - 1, DDR3 - 2, DDR4 - 3, DDR5 - 4): ";
	std::cin >> type;
	std::cout << "Введите тактовую частоту (в МГц): ";
	std::cin >> frequency;
	std::cout << "Введите объем (в ГБ): ";
	std::cin >> capacity;
	while (getchar() != '\n');

	tryToSetArguments(modelName, type, frequency, capacity);
}

std::string RAM::toString() const {
	std::string name = this->getModelName() + ", " + RAMTypeToString(this->getRAMType()) + ", " + std::to_string(this->getCapacity()) + " ГБ, " + std::format("{:.1f}", this->getFrequency()) + " МГц";
	return name;
}


bool RAM::checkArguments(std::string modelName, RAMType type, float frequency, int capacity) const {
	return type >= DDR && type <= DDR5 && frequency >= 0 && frequency <= DDRFreqMax[type] && capacity >= 0;
}

void RAM::tryToSetArguments(std::string modelName, RAMType type, float frequency, int capacity) {
	if (checkArguments(modelName, type, frequency, capacity)) {
		this->modelName = modelName;
		this->type = type;
		this->frequency = frequency;
		this->capacity = capacity;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}