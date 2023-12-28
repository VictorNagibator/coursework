#pragma once
#include <iostream>
#include "../OrderComponents/Order.h"

class Table
{
public:
	Table() = default;

	void showOrder(Order order) const;
	void shortShow(std::vector<Order> data) const;
	void fullShow(std::vector<Order> data) const;
private:
	void showHeader() const;
	void showFooter() const;
};