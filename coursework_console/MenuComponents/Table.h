#pragma once
#include <iostream>
#include "../OrderComponents/Order.h"

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