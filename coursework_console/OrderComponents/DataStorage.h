﻿#pragma once
#include <string>
#include <format>
#include <nlohmann/json.hpp>
#include "DataTransferInterface.h"
#include "LaptopComponent.h"

using json = nlohmann::json;

class DataStorage abstract : public LaptopComponent
{
public:
	DataStorage() = default;
	DataStorage(DataTransferInterface transferInterface);
	DataStorage(int capacity, DataTransferInterface transferInterface, std::string brand, float formFactor);
	~DataStorage() = default;

	void operator=(DataStorage* other);

	virtual std::string getComponentName() const abstract = 0;

	virtual int getCapacity() const;
	virtual DataTransferInterface getInterface() const;
	virtual std::string getBrand() const;
	virtual float getFormFactor() const;

	virtual void input();
	virtual std::string toString() const abstract;
	virtual json toJSON() const abstract;
	virtual void fromJSON(json data);
protected:
	int capacity = 0;
	DataTransferInterface transferInterface = DataTransferInterface::SATA;
	float formFactor = 0;
	std::string brand;

	bool checkArguments(int capacity, DataTransferInterface transferInterface, std::string brand, float formFactor) const;
	void tryToSetArguments(int capacity, DataTransferInterface transferInterface, std::string brand, float formFactor);
};