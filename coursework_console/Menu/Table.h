#pragma once
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Table
{
public:
	Table(const std::string& filePath);

	void shortShow() const;
	void fullShow() const;
private:
	std::string filePath;

	json data;
};