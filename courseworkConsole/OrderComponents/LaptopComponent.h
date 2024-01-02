#pragma once
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class LaptopComponent abstract
{
public:
	virtual std::string getComponentName() const abstract = 0;
	virtual void input() abstract = 0;
	virtual std::string toString() const abstract = 0;
	virtual json toJSON() const abstract = 0;
	virtual void fromJSON(json data) abstract = 0;
};