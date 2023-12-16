#pragma once
#include <iostream>
#include <nlohmann/json.hpp>
#include "../OrderComponents/Order.h"

using json = nlohmann::json;

class Table
{
public:
	Table() = default;

	void showOrder(Order order) const;
	void shortShow() const;
	void fullShow() const;
private:
	void showHeader() const;
	void showFooter() const;
};