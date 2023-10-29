#pragma once
#include <string>
#include <iostream>
#include <istream>
#include "DataStorage.h"
#include "FlashMemoryType.h"

class SSD : public DataStorage
{
public:
	SSD() = default;
	SSD(DataTransferInterface transferInterface);
	SSD(int capacity, DataTransferInterface transferInterface, std::string brand, FlashMemoryType typeOfFlashMemory, float formFactor);
	~SSD() = default;

	void operator=(SSD other);
	friend std::ostream& operator << (std::ostream& out, const SSD& ssd);

	std::string getStorageName() const;
	int getCapacity() const;
	DataTransferInterface getInterface() const;
	std::string getBrand() const;
	FlashMemoryType getTypeOfFlashMemory() const;
	float getFormFactor() const;
	void input();
private:
	FlashMemoryType typeOfFlashMemory = NAND3D;

	bool checkArguments(int capacity, DataTransferInterface transferInterface, std::string brand, FlashMemoryType typeOfFlashMemory, float formFactor);
	void setArguments(int capacity, DataTransferInterface transferInterface, std::string brand, FlashMemoryType typeOfFlashMemory, float formFactor);
};