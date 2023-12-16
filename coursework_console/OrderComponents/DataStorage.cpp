#include "DataStorage.h"

void DataStorage::operator=(DataStorage* other) {
	this->capacity = other->capacity;
	this->transferInterface = other->transferInterface;
	this->brand = other->brand;
	this->formFactor = other->formFactor;
}

DataStorage::DataStorage(DataTransferInterface transferInterface) {
	this->transferInterface = transferInterface;
}

DataStorage::DataStorage(int capacity, DataTransferInterface transferInterface, std::string brand, float formFactor) {
	tryToSetArguments(capacity, transferInterface, brand, formFactor);
}

int DataStorage::getCapacity() const {
	return capacity;
}

DataTransferInterface DataStorage::getInterface() const {
	return transferInterface;
}

std::string DataStorage::getBrand() const {
	return brand;
}

float DataStorage::getFormFactor() const {
	return formFactor;
}

void DataStorage::input() {
	int capacity;
	DataTransferInterface interface;
	std::string brand;
	float formFactor;

	std::cout << "Введите вместимость (в ГБ): ";
	std::cin >> capacity;
	std::cout << "Введите интерфейс подключения (PATA - 0, SATA - 1, SAS - 2, NVMe - 3): ";
	std::cin >> interface;
	std::cin.clear();
	while (std::cin.get() != '\n');
	std::cout << "Введите производителя: ";
	std::getline(std::cin, brand);
	std::cout << "Введите форм фактор (в дюймах): ";
	std::cin >> formFactor;
	std::cin.clear();
	while (std::cin.get() != '\n');

	tryToSetArguments(capacity, interface, brand, formFactor);
}


std::string DataStorage::toString() const {
	std::string name = this->getBrand() + ", " + std::to_string(this->getCapacity()) + " ГБ, " + dataTransferInterfaceToString(this->getInterface()) + ", " + std::format("{:.1f}", this->getFormFactor());
	return name;
}

json DataStorage::toJSON() const {
    json j;
	j["componentName"] = getComponentName();
	j["capacity"] = capacity;
	j["transferInterface"] = dataTransferInterfaceToString(transferInterface);
	j["brand"] = brand;
	j["formFactor"] = formFactor;
	return j;
}

void DataStorage::fromJSON(json data) {
	tryToSetArguments(data["capacity"], stringToDataTransferInterface(data["transferInterface"]), data["brand"], data["formFactor"]);
}


bool DataStorage::checkArguments(int capacity, DataTransferInterface transferInterface, std::string brand, float formFactor) const {
	return capacity >= 0 && formFactor >= 0;
}

void DataStorage::tryToSetArguments(int capacity, DataTransferInterface transferInterface, std::string brand, float formFactor) {
	if (checkArguments(capacity, transferInterface, brand, formFactor)) {
		this->capacity = capacity;
		this->transferInterface = transferInterface;
		this->brand = brand;
		this->formFactor = formFactor;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}