#include "HDD.h"

void HDD::operator=(HDD other) {
	this->capacity = other.capacity;
	this->transferInterface = other.transferInterface;
	this->brand = other.brand;
	this->spindleSpeed = other.spindleSpeed;
	this->formFactor = other.formFactor;
}

std::ostream& operator << (std::ostream& out, const HDD& hdd) {
	DataTransferInterface strInterface = hdd.getInterface();
	out << hdd.getBrand() << ", " << hdd.getCapacity() << " ГБ, " << strInterface << ", " << hdd.getFormFactor();
	return out;
}

HDD::HDD(DataTransferInterface transferInterface) {
	this->transferInterface = transferInterface;
}

HDD::HDD(int capacity, DataTransferInterface transferInterface, std::string brand, int spindleSpeed, float formFactor) {
	setArguments(capacity, transferInterface, brand, spindleSpeed, formFactor);
}

std::string HDD::getStorageName() const {
	return "HDD";
}

int HDD::getCapacity() const {
	return capacity;
}

DataTransferInterface HDD::getInterface() const {
	return transferInterface;
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

	std::cout << "Введите вместимость (в ГБ): ";
	std::cin >> capacity;
	std::cout << "Введите интерфейс подключения (PATA - 0, SATA - 1, SAS - 2, NVMe - 3): ";
	std::cin >> interface;
	while (getchar() != '\n');
	std::cout << "Введите производителя: ";
	std::getline(std::cin, brand);
	std::cout << "Введите cкорость вращения шпинделя: ";
	std::cin >> spindleSpeed;
	std::cout << "Введите форм фактор (в дюймах): ";
	std::cin >> formFactor;
	while (getchar() != '\n');

	setArguments(capacity, interface, brand, spindleSpeed, formFactor);
}


bool HDD::checkArguments(int capacity, DataTransferInterface transferInterface, std::string brand, int spindleSpeed, float formFactor) {
	return capacity >= 0 && transferInterface >= PATA && transferInterface <= NVME && spindleSpeed >= 0 && formFactor >= 0;
}

void HDD::setArguments(int capacity, DataTransferInterface transferInterface, std::string brand, int spindleSpeed, float formFactor) {
	if (checkArguments(capacity, transferInterface, brand, spindleSpeed, formFactor)) {
		this->capacity = capacity;
		this->transferInterface = transferInterface;
		this->brand = brand;
		this->spindleSpeed = spindleSpeed;
		this->formFactor = formFactor;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}