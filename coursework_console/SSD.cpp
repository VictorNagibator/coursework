#include "SSD.h"

void SSD::operator=(SSD other) {
	this->capacity = other.capacity;
	this->transferInterface = other.transferInterface;
	this->brand = other.brand;
	this->formFactor = other.formFactor;
	this->typeOfFlashMemory = other.typeOfFlashMemory;
}

std::ostream& operator << (std::ostream& out, const SSD& ssd) {
	DataTransferInterface strInterface = ssd.getInterface();
	FlashMemoryType strMemoryType = ssd.getTypeOfFlashMemory();
	out << ssd.getBrand() << ", " << ssd.getCapacity() << " ГБ, " << strInterface << ", " << ssd.getFormFactor() << ", " << strMemoryType;
	return out;
}

SSD::SSD(DataTransferInterface transferInterface) {
	this->transferInterface = transferInterface;
}

SSD::SSD(int capacity, DataTransferInterface transferInterface, std::string brand, FlashMemoryType typeOfFlashMemory, float formFactor) {
	setArguments(capacity, transferInterface, brand, typeOfFlashMemory, formFactor);
}

std::string SSD::getStorageName() const {
	return "SSD";
}

int SSD::getCapacity() const {
	return capacity;
}

DataTransferInterface SSD::getInterface() const {
	return transferInterface;
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
	DataTransferInterface transferInterface;
	std::string brand;
	FlashMemoryType typeOfFlashMemory;
	float formFactor;

	std::cout << "Введите вместимость (в ГБ): ";
	std::cin >> capacity;
	std::cout << "Введите интерфейс подключения (PATA - 0, SATA - 1, SAS - 2, NVMe - 3): ";
	std::cin >> transferInterface;
	while (getchar() != '\n');
	std::cout << "Введите производителя: ";
	std::getline(std::cin, brand);
	std::cout << "Введите тип флеш-памяти (0 - SLC, 1 - MLC, 2 - NOR, 3 - NAND, 4 - 3DNAND): ";
	std::cin >> typeOfFlashMemory;
	std::cout << "Введите форм фактор (в дюймах): ";
	std::cin >> formFactor;
	while (getchar() != '\n');

	setArguments(capacity, transferInterface, brand, typeOfFlashMemory, formFactor);
}


bool SSD::checkArguments(int capacity, DataTransferInterface transferInterface, std::string brand, FlashMemoryType typeOfFlashMemory, float formFactor) {
	return capacity >= 0 && transferInterface >= PATA && transferInterface <= NVME && typeOfFlashMemory >= SLC && typeOfFlashMemory <= NAND3D && formFactor >= 0;
}

void SSD::setArguments(int capacity, DataTransferInterface transferInterface, std::string brand, FlashMemoryType typeOfFlashMemory, float formFactor) {
	if (checkArguments(capacity, transferInterface, brand, typeOfFlashMemory, formFactor)) {
		this->capacity = capacity;
		this->transferInterface = transferInterface;
		this->brand = brand;
		this->typeOfFlashMemory = typeOfFlashMemory;
		this->formFactor = formFactor;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}