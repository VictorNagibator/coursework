#pragma once
#include "DataTransferInterface.h"

class DataStorage abstract
{
public:
	virtual int getCapacity() const abstract;
	virtual DataTransferInterface getInterface() const abstract;
	virtual std::string getBrand() const abstract;
	virtual float getFormFactor() const abstract;
protected:
	int capacity = 0;
	DataTransferInterface interface = SATA;
	float formFactor = 0;
	std::string brand;
};