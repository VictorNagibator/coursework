#pragma once
#include <iostream>
#include <istream>
#include "Laptop.h"
#include "StatusType.h"

class Order
{
public:
	Order() = default;
	Order(Laptop laptop);
	Order(int num, Laptop laptop, StatusType status);
	~Order() = default;

	void operator=(Order other);
	friend std::ostream& operator << (std::ostream& out, Order& order);

	int getNum() const;
	Laptop getLaptop() const;
	StatusType getStatus() const;
	void input();
	void setStatus(StatusType status);
	void setLaptop(Laptop laptop);
private:
	int num;
	Laptop laptop;
	StatusType status;

	bool checkArguments(int num, Laptop laptop, StatusType status);
};