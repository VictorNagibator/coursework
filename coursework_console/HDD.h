#pragma once
#include <string>
#include <iostream>
#include <istream>
#include "DataStorage.h"

class HDD : public DataStorage
{
public:
	HDD() = default;
	HDD(DataTransferInterface transferInterface);
	HDD(int capacity, DataTransferInterface transferInterface, std::string brand, int spindleSpeed, float formFactor);
	~HDD() = default;

	void operator=(HDD other);
	friend std::ostream& operator << (std::ostream& out, const HDD& hdd);

	std::string getStorageName() const;
	int getCapacity() const;
	DataTransferInterface getInterface() const;
	std::string getBrand() const;
	int getSpindleSpeed() const;
	float getFormFactor() const;
	void input();
private:
	int spindleSpeed = 0;

	bool checkArguments(int capacity, DataTransferInterface transferInterface, std::string brand, int spindleSpeed, float formFactor);
	void setArguments(int capacity, DataTransferInterface transferInterface, std::string brand, int spindleSpeed, float formFactor);
};