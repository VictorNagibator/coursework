#pragma once
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Table
{
public:
	Table();
	Table(const std::string& filePath);

	void shortShow() const;
	void fullShow() const;
private:
	json data;

	void showHeader() const;
	void showBottom() const;
	void loadJSON(const std::string& filePath);
};