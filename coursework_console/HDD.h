#pragma once
#include "DataStorage.h"

class HDD : public DataStorage
{
public:
	HDD();
	HDD(DataTransferInterface interface);
	HDD(int capacity, DataTransferInterface interface, std::string brand, int spindleSpeed, float formFactor);

	void operator=(HDD other);
	friend std::ostream& operator << (std::ostream& out, const HDD& hdd);

	int getCapacity() const;
	DataTransferInterface getInterface() const;
	std::string getBrand() const;
	int getSpindleSpeed() const;
	float getFormFactor() const;
	void input();
private:
	int spindleSpeed = 0;

	bool checkArguments(int capacity, DataTransferInterface interface, std::string brand, int spindleSpeed, float formFactor);
	void setArguments(int capacity, DataTransferInterface interface, std::string brand, int spindleSpeed, float formFactor);
};