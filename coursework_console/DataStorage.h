#pragma once
#include "DataTransferInterface.h"

class DataStorage abstract
{
public:
	virtual std::string getStorageName() const abstract;

	virtual int getCapacity() const abstract;
	virtual DataTransferInterface getInterface() const abstract;
	virtual std::string getBrand() const abstract;
	virtual float getFormFactor() const abstract;
	virtual void input() abstract;
protected:
	int capacity = 0;
	DataTransferInterface transferInterface = SATA;
	float formFactor = 0;
	std::string brand;
};