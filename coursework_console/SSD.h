#pragma once
#include "DataStorage.h"
#include "FlashMemoryType.h"

class SSD : public DataStorage
{
public:
	SSD();
	SSD(DataTransferInterface interface);
	SSD(int capacity, DataTransferInterface interface, std::string brand, FlashMemoryType typeOfFlashMemory, float formFactor);

	void operator=(SSD other);
	friend std::ostream& operator << (std::ostream& out, const SSD& ssd);

	int getCapacity() const;
	DataTransferInterface getInterface() const;
	std::string getBrand() const;
	FlashMemoryType getTypeOfFlashMemory() const;
	float getFormFactor() const;
	void input();
private:
	FlashMemoryType typeOfFlashMemory = NAND3D;

	bool checkArguments(int capacity, DataTransferInterface interface, std::string brand, FlashMemoryType typeOfFlashMemory, float formFactor);
	void setArguments(int capacity, DataTransferInterface interface, std::string brand, FlashMemoryType typeOfFlashMemory, float formFactor);
};